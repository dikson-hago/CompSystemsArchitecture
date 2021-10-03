// input example with file
// ./bin/task01 -f tests/test01.txt tests/out.txt
// input example with number of random
// ./bin/task01 -n 100 tests/out.txt

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>  
#include <cstring>

#include "container.h"

void ErrorInputMessage() {
    cout << "Incorrcet input\n";
}

void OutputInFileAndClearContainer(container &c, char* fileName) {
    ofstream ofst1(fileName);
    ofst1 << "Filled container:\n";
    SortContainer(c);
    Output(c, ofst1);
    Clear(c);
}

int InputFromFileAndValidateInputData(container &c,
char* command, char* fileName) {
    if(!strcmp(command, "-f")) {
        ifstream ifst(fileName);
        Input(c, ifst);
        return 0;
    }
    else if(!strcmp(command, "-n")) {
        auto size = atoi(fileName);
        if((size < 1) || (size > 10000)) { 
            cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return -1;
        }
        srand(static_cast<unsigned int>(time(0)));
        InputRandom(c, size);
        return 0;
    }
    else {
        ErrorInputMessage();
        return 0;
    }
}

int main(int argc, char* argv[]) {
    clock_t begin = clock();
    if(argc != 4) {
        ErrorInputMessage();
        return 1;
    }

    cout << "Start program"<< endl;
    container c;
    Init(c);

    cout << "command : " << argv[1] << "\n";

    int inputStatus = 
    InputFromFileAndValidateInputData(c, argv[1], argv[2]);

    if(inputStatus == 0) {
        OutputInFileAndClearContainer(c, argv[3]);
    }

    cout << "Stop program"<< endl;
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Time spent: " << time_spent << '\n';
    return 0;
}
