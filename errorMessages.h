#include <iostream>

class ErrorMessages {
public:
    static void IncorrectAmountOfArgs() {
        std::cout << "Incorrect amount of args";
    }

    static void IncorrectInputData() {
        std::cout << "Incorrect input data";
    }
};