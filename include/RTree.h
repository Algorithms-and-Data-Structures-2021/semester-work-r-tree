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
    std::list<Node> children = new list<Node>();
    Node parent;
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

  int maxEntries;
  int minEntries;
  int size;
  static int numDims;
  Node *root;
  std::vector<float> pointDims = new list<float>();

 public:
  RTree(int maxEntries, int minEntries);
};