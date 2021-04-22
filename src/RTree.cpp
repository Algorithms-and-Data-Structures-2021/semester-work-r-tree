#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include "RTree.h"

// NODE STRUCTURE
RTree::Node::Node(std::vector<float> coords, std::vector<float> dimensions, bool leaf) {
  this->coords = coords;
  this->dimensions = dimensions;
  this->leaf = leaf;

  //  std::copy_n(coords.begin(), coords.size(), this->coords.begin());
  //  std::copy_n(dimensions.begin(), dimensions.size(), this->dimensions.begin());
}

// TO CREATE ROOT OR ANOTHER NODE
RTree::Node *RTree::Node::buildRoot(bool asLeaf) {
  std::vector<float> initCoords(numDims);
  std::vector<float> initDimensions(numDims);

  for (int i = 0; i < numDims; i++) {
    initCoords[i] = static_cast<float>(std::sqrt(std::numeric_limits<float>::max()));
    initDimensions[i] = -2.0f * static_cast<float>(std::sqrt(std::numeric_limits<float>::max()));
  }

  return new RTree::Node(initCoords, initDimensions, asLeaf);
}

RTree::Entry::Entry(std::vector<float> coords, std::vector<float> dimensions, int entry)
    : Node(coords, dimensions, true) {
  this->entry = entry;
}

// R-TREE CONSTRUCTOR
RTree::RTree(int maxEntries, int minEntries) {
  this->maxEntries = maxEntries;
  this->minEntries = minEntries;
  this->numDims = 2;
  this->root = Node::buildRoot(true);
}

//INSERT
void RTree::insert(std::vector<float> coords, std::vector<float> dimensions, int entry) {
  assert(coords.size() == numDims);
  assert(dimensions.size() == numDims);

  Entry *e = new Entry(coords, dimensions, entry);
  Node l = chooseLeaf(*root, *e);
  l.children.push_back(e);
  size++;
  e->parent = &l;
  if (l.children.size() > maxEntries) {
    Node[] splits = splitNode(l);
    adjustTree(splits[0], splits[1]);
  } else {
    adjustTree(l, nullptr);
  }
}

//INSERT HELP METHODS

//chooseLeaf and help methods
RTree::Node RTree::chooseLeaf(RTree::Node n, RTree::Entry e) {
  if (n.leaf) {
    return n;
  }

  float minInc = std::numeric_limits<float>::max();
  Node *next = nullptr;
  for (RTree::Node *c : n.children) {
    float inc = getRequiredExpansion(c->coords, c->dimensions, e);

    if (inc < minInc) {
      minInc = inc;
      next = c;
    } else if (inc == minInc) {
      float curArea = 1.0f;
      float thisArea = 1.0f;
      for (int i = 0; i < c->dimensions.size(); i++) {
        curArea *= next->dimensions.at(static_cast<unsigned long>(i));
        thisArea *= c->dimensions.at(static_cast<unsigned long>(i));
      }
      if (thisArea < curArea) {
        next = c;
      }
    }
  }
  return chooseLeaf(*next, e);
}

float RTree::getRequiredExpansion(std::vector<float> coords, std::vector<float> dimensions, RTree::Node e) {
  float area = getArea(dimensions);
  auto *deltas = new std::vector<float>(dimensions.size());
  for (unsigned long i = 0; i < deltas->size(); i++) {
    if ((coords.at(i) + dimensions.at(i)) < (e.coords.at(i) + e.dimensions.at(i))) {
      deltas->at(i) = e.coords.at(i) + e.dimensions.at(i) - coords.at(i) - dimensions.at(i);
    } else if (coords.at(i) + dimensions.at(i) > (e.coords.at(i) + e.dimensions.at(i))) {
      deltas->at(i) = coords.at(i) - e.coords.at(i);
    }
  }
  float expanded = 1.0f;
  for (unsigned long i = 0; i < dimensions.size(); i++) {
    expanded *= dimensions.at(i) + deltas->at(i);
  }
  return (expanded - area);
}

float RTree::getArea(std::vector<float> dimensions) {
  float area = 1.0f;
  for (unsigned long i = 0; i < dimensions.size(); i++) {
    area *= dimensions.at(i);
  }
  return area;
}

//splitNode
std::vector<RTree::Node *> RTree::splitNode(RTree::Node *n) {
  std::vector<Node *> nn = std::vector<RTree::Node *>{n, new Node(n->coords, n->dimensions, n->leaf)};
  nn.at(1)->parent = n->parent;
  if (nn.at(1) != nullptr) {
    nn.at(1)->parent->children.push_back(nn.at(1));
  }
  std::list<Node *> cc(n->children);
  n->children.clear();

  std::vector<Node *> ss = pickSeeds(cc);
  nn.at(0)->children.push_back(ss.at(0));
  nn.at(1)->children.push_back(ss.at(1));

  tighten(nn);

  while (!cc.isEmpty()) {
    if ((nn[0]->children.size() >= static_cast<unsigned long>(minEntries))
        && (nn.at(1)->children.size() + cc.size() == static_cast<unsigned long>(minEntries))) {
      std::fill(cc.begin(), cc.end(), nn[1]);  //возможно не работает
      cc.clear();
      tighten(nn);  //not sure this is required
      return nn;
    } else if ((nn[1]->children.size() >= static_cast<unsigned long>(minEntries))
               && (nn.at(0)->children.size() + cc.size() == static_cast<unsigned long>(minEntries))) {
      std::fill(cc.begin(), cc.end(), nn[0]);  //возможно не работает
      cc.clear();
      tighten(nn);
      return nn;
    }

    RTree::Node *c = pickNext(cc);
    RTree::Node *preferred = nullptr;

    float e0 = getRequiredExpansion(nn.at(0)->coords, nn.at(0)->dimensions, *c);
    float e1 = getRequiredExpansion(nn.at(1)->coords, nn.at(1)->dimensions, *c);

    if (e0 < e1) {
      preferred = nn.at(0);
    } else if (e0 > e1) {
      preferred = nn.at(1);
    } else {
      float a0 = getArea(nn.at(0)->dimensions);
      float a1 = getArea(nn.at(1)->dimensions);
      if (a0 < a1) {
        preferred = nn.at(0);
      } else if (e0 > a1) {
        preferred = nn.at(1);
      } else {
        if (nn.at(0)->children.size() < nn.at(1)->children.size()) {
          preferred = nn.at(0);
        } else if (nn.at(0)->children.size() > nn.at(1)->children.size()) {
          preferred = nn.at(1);
        } else {
          preferred = nn.at(static_cast<unsigned long>(random()));
        }
      }
    }
    preferred->children.push_back(c);
    tighten(std::vector<RTree::Node *>{preferred});
  }
  return nn;
}
void RTree::tighten(std::vector<RTree::Node *> nodes) {
  assert(((nodes.size() >= 1), L"Pass some nodes to tighten!"));
  for(RTree::Node *n: nodes){
    assert(n->children.size() > 0);
    auto *minCoords = new float[static_cast<unsigned long>(numDims)];
    auto *maxCoords = new float[static_cast<unsigned long>(numDims)];
    for (int i = 0; i < numDims; i++)
    {
      minCoords[i] = std::numeric_limits<float>::max();
      maxCoords[i] = 0.000000;

      for (Node *c : n->children)
      {
        c->parent = n;
        if (c->coords[i] < minCoords[i])
        {
          minCoords[i] = c->coords[i];
        }
        if ((c->coords[i] + c->dimensions[i]) > maxCoords[i])
        {
          maxCoords[i] = (c->coords[i] + c->dimensions[i]);
        }
      }
    }
    for (int i = 0; i < numDims; i++)
    {
      // Convert max coords to dimensions
      maxCoords[i] -= minCoords[i];
    }

  }

}
