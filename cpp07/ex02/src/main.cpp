#include "../include/Array.hpp"

#include <iostream>
#define MAX_VAL 750

int main(void)
{
    //===-----------------------------------------------------===//
    //                      Subject tests
    //===-----------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    Subject tests\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===-----------------------------------------------------===//


    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) { // filling random values for mirror and numbers
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;   // Assignment operator overload test 
        Array<int> test(tmp);       // Copy constructor test
    }

    for (int i = 0; i < MAX_VAL; i++) { // check if both arrays saved the same values
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try { // checking out of bound exception
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try { // checking out of bound exception
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete [] mirror;


    //===-----------------------------------------------------===//
    //                       My tests
    //===-----------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    My tests\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===-----------------------------------------------------===//

    Array<std::string> emptyStringArray = Array<std::string>(0); // empty array test

    //===-----------------------------------------------------===//
    std::cout << "\033[31m//    Array with empty strings test\033[0m" << std::endl;
    //===-----------------------------------------------------===//

    Array<std::string> stringArray = Array<std::string>(5);
    for (int i = 0; i < 5; i++) {
        std::cout << stringArray[i] << std::endl;
    }

    //===-----------------------------------------------------===//
    std::cout << "\033[31m//    Filled string array test\033[0m" << std::endl;
    //===-----------------------------------------------------===//
    Array<std::string> goodStringArray = Array<std::string>(5);

    goodStringArray[0] = "Hey";
    goodStringArray[1] = "it's";
    goodStringArray[2] = "me";
    goodStringArray[3] = "Bob";
    goodStringArray[4] = ".";

    for (unsigned int i = 0; i < goodStringArray.size(); i++) { // size member function test
        std::cout << goodStringArray[i] << " ";
    }
    std::cout << std::endl;
    //===-----------------------------------------------------===//
}
