#include "container.h"

// constructor
Container::Container() {
    container_length_ = 0;
}

// destructor
Container::~Container() {
    Clear();
}

// clear container
void Container::Clear() {
    for(int i = 0; i < container_length_; i++) {
        delete cont_[i];
    }
    container_length_ = 0;
}

// set color and type of shape
bool Container::SetColorAndType(int shape_key, int color_key) {
    switch(shape_key) {
        case 1:
            cont_[container_length_] = new Rectangle();
            cont_[container_length_]->SetColor(color_key);
            break;
        case 2:
            cont_[container_length_] = new Triangle();
            cont_[container_length_]->SetColor(color_key);
            break;
        case 3:
            cont_[container_length_] = new Circle();
            cont_[container_length_]->SetColor(color_key);
            break;
        case 4:
            return false;
    }
    return true;
}

// input data for container
void Container::Input(ifstream &ifst) {
    while(!ifst.eof()) {
        int shape_key, color_key;
        ifst >> shape_key >> color_key;
        if(SetColorAndType(shape_key, color_key)) {
            cont_[container_length_]->Input(ifst);
            container_length_++;
        }
    }
}

// get random data for container
void Container::InputRandom(int size) {
    while(container_length_ < size) {
        auto shape_key = rand() % 3 + 1;
        auto color_key = rand() % 7 + 1;
        SetColorAndType(shape_key, color_key);
        switch(shape_key) {
            case 1:
                shape_key = ShapeName::RECTANGLE;
                cont_[container_length_]->InputRandom();
            case 2:
                shape_key = ShapeName::TRIANGLE;
                cont_[container_length_]->InputRandom();
            case 3:
                shape_key = ShapeName::CIRCLE;
                cont_[container_length_]->InputRandom();
        }
        container_length_++;
    }
}

// output data of container
void Container::Output(ofstream &ofst) {
    ofst << "Container contains " << container_length_ << " elements." << '\n';
    for(int i = 0; i < container_length_; i++) {
        ofst << i << ": ";
        ofst << "It is ";
        cont_[i]->OutColor(ofst);
        cont_[i]->Output(ofst);
    }
}

// sort container's elements by their perimeter
void Container::SortContainer() {
    for(int i = 0; i < container_length_; i++) {
        for(int j = container_length_ - 1; j > i; j--) {
            if(cont_[j]->Perimeter() < cont_[j - 1]->Perimeter()) {
                std::swap(cont_[j], cont_[j - 1]);
            }
        }
    }
}