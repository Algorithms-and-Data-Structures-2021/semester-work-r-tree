#include <vector>
#include <list>
#ifndef SEMESTER_WORK_TEMPLATE_RTREE_H
#define SEMESTER_WORK_TEMPLATE_RTREE_H

#endif

#pragma once

class RTree{

 public:
  class Node{
   public:
    std::vector<float> coords;
    std::vector<float> dimensions;
    std::list<Node*> children;
    Node* parent;
    bool leaf;
    static Node* buildRoot(bool asLeaf);

   public:
    Node(std::vector<float> coords, std::vector<float> dimensions, bool leaf);
  };

  class Entry : public Node {
   public:
    int entry;
    Entry(std::vector<float> coords, std::vector<float> dimensions, int entry);
  };

 private:
  RTree::Node chooseLeaf(RTree::Node n, RTree::Entry e);
  float getRequiredExpansion(std::vector<float> coords, std::vector<float> dimensions, Node e);
  float getArea(std::vector<float> dimensions);
  std::vector<Node*> splitNode(Node *n);
  void tighten(std::vector<RTree::Node*> nodes);
  void adjustTree(RTree::Node *n, RTree::Node *nn);
  std::vector<RTree::Node *> pickSeeds(std::list<Node *> *nn);
  RTree::Node *pickNext(std::list<RTree::Node *> &cc);
  int maxEntries;
  int minEntries;
  int size;

  static int numDims;
  Node *root;
  std::vector<float>* pointDims;

 public:
  RTree(int maxEntries, int minEntries);
  void insert(std::vector<float> coords, std::vector<float> dimensions, int entry);

};