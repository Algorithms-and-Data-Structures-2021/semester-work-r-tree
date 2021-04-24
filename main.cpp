#include <iostream>
#include "RTree.h"



using namespace std;

int main(int argc, char *argv[]) {
  RTree *a = new RTree();

  a->insert(std::vector<float>{1, 0}, 0);
  a->insert(std::vector<float>{11, 11}, 1);
  a->insert(std::vector<float>{15, 2}, 2);
  a->insert(std::vector<float>{22, 7}, 3);
  a->insert(std::vector<float>{14, 84}, 4);
  a->insert(std::vector<float>{50, 9}, 5);
  a->insert(std::vector<float>{1, 3}, 6);
  a->insert(std::vector<float>{0, 44}, 7);
  a->insert(std::vector<float>{10, 12}, 8);
  a->insert(std::vector<float>{66, 55}, 9);
  a->insert(std::vector<float>{21, 1}, 10);
  a->insert(std::vector<float>{8, 5}, 11);
  a->insert(std::vector<float>{6, 6}, 12);
  a->insert(std::vector<float>{7, 5}, 13);

  return 0;
}