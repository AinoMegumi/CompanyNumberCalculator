#include "Calculator.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        for (int i = 1; i < argc; i++) {
            const std::string str(argv[i]);
            std::string Result = CalcCompanyNumber(str);
            if (std::strlen(Result.c_str()) == 0) Result = "Invalid value";
            std::cout << i << ". " << Result << std::endl;
        }
    }
    catch (const std::exception& er) {
        std::cout << std::endl;
    }
}