#include "container.h"

// initialize new container
void Init(container &c) {
    c.len = 0;
}

// clear container
void Clear(container &c) {
    c.len = 0;
}

// input data for container
void Input(container &c, ifstream &ifst) {
    while(!ifst.eof()) {
        if(Input(c.cont[c.len], ifst)) {
            c.len++;
        }
    }
}

// get random data for container
void InputRandom(container &c, int size) {
    while(c.len < size) {
        if(InputRandom(c.cont[c.len])) {
            c.len++;
        }
    }
}

// output data of container
void Output(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << endl;
    for(int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        ofst << "It is ";
        OutColor(c.cont[i], ofst);
        Output(c.cont[i], ofst);
    }
}

// sort container's elements by their perimeter
void SortContainer(container &c) {
    for(int i = 0; i < c.len; i++) {
        for(int j = c.len - 1; j > i; j--) {
            if(Perimeter(c.cont[j]) < Perimeter(c.cont[j - 1])) {
                std::swap(c.cont[j], c.cont[j - 1]);
            }
        }
    }
}