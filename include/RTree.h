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
    std::vector<Node*> children;
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
  std::vector<RTree::Node *> pickSeeds(std::vector<Node *> *nn);
  bool deleting(std::vector<float> &coords, std::vector<float> &dimensions, int entry);
  RTree::Node *pickNext(std::vector<RTree::Node *> &cc);
  bool isOverlap(std::vector<float> scoords, std::vector<float> sdimensions, std::vector<float> coords,
                        std::vector<float> dimensions);
  void search(std::vector<float> *coords, std::vector<float> *dimensions, RTree::Node *n, std::vector<int> *results);
  RTree::Node* findLeaf(RTree::Node *n, std::vector<float> *coords, std::vector<float> *dimensions, int entry);
  void condenseTree(RTree::Node *n);
  void insert(std::vector<float> coords, std::vector<float> dimensions, int entry);
  int maxEntries;
  int minEntries;
  int size;

  static int numDims;
  Node *root;
  std::vector<float> pointDims;

 public:
  RTree();
  void insert(std::vector<float> coords, int entry);
  std::vector<int> search(std::vector<float> *coords, std::vector<float> *dimensions);
  bool deleting(std::vector<float> coords, int entry);
};