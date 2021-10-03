#ifndef __container__
#define __container__

#include "shape.h"

struct container {
    enum {max_len = 10000};  // max length
    int len; // current length
    shape cont[max_len];
};

// initialize new container
void Init(container &c);

// clear container
void Clear(container &c);

// input data for container
void Input(container &c, ifstream &ifst);

// get random data for container
void InputRandom(container &c, int size);

// output data of container
void Output(container &c, ofstream &ofst);

// sort container's elements by their perimeter
void SortContainer(container &c);

#endif
