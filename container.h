#ifndef __container__
#define __container__

#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "shape.h"


class Container {
private:
    const static int max_len = 10000;  // max length
    int container_length_; // current length
    Shape* cont_[max_len];

    bool SetColorAndType(int key, int color_key);

public:
    // constructor
    Container();

    // destructor
    ~Container();

    // clear container
    void Clear();

    // input data for container
    void Input(ifstream &ifst);

    // get random data for container
    void InputRandom(int size);

    // output data of container
    void Output(ofstream &ofst);

    // sort container's elements by their perimeter
    void SortContainer();
};
#endif
