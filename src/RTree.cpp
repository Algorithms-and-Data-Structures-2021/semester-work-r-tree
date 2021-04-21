#include <iostream>
#include <algorithm>
#include <cmath>
#include "RTree.h"


// NODE STRUCTURE
RTree::Node::Node(std::vector<float> coords, std::vector<float> dimensions, bool leaf){
  this->coords = coords;
  this->dimensions = dimensions;
  this->leaf = leaf;

//  std::copy_n(coords.begin(), coords.size(), this->coords.begin());
//  std::copy_n(dimensions.begin(), dimensions.size(), this->dimensions.begin());
}

// TO CREATE ROOT OR ANOTHER NODE
RTree::Node* RTree::Node::buildRoot(bool asLeaf){
  std::vector<float> initCoords(numDims);
  std::vector<float> initDimensions(numDims);

  for(int i = 0; i < numDims; i++){
    initCoords[i] = static_cast<float>(std::sqrt(std::numeric_limits<float>::max()));
    initDimensions[i] = -2.0f * static_cast<float>(std::sqrt(std::numeric_limits<float>::max()));
  }

  return new RTree::Node(initCoords, initDimensions, asLeaf);
}

RTree::Entry::Entry(std::vector<float> coords, std::vector<float> dimensions, int entry) : Node(coords, dimensions, true){
  this->entry = entry;

}


// R-TREE CONSTRUCTOR
RTree::RTree(int maxEntries, int minEntries){
  this->maxEntries = maxEntries;
  this->minEntries = minEntries;
  this->numDims = 2;
  this->root = Node::buildRoot(true);
}
