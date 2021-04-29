#include <iostream>
#include "RTree.h"


using namespace std;

int main(int argc, char *argv[]) {
  RTree *a = new RTree();
  auto b = std::vector<float>{11,11};
  auto c = std::vector<float>{15, 2};
  auto d = std::vector<float>{22, 7};



  a->insert(&b, 0);
  a->insert(&c, 1);
  a->insert(&d, 2);

  a->deleting(&c, 1);
  a->deleting(&b, 0);
  a->deleting(&d, 2);
  a->deleting(&d, 3);



  return 0;
}