#include "../include/Span.hpp"

#include <iostream>

int main(void)
{
    //===----------------------------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    Subject tests\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===----------------------------------------------------------------------===//

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    //===----------------------------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    Too many elements test\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===----------------------------------------------------------------------===//

    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    //===----------------------------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    Span member functions tests\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===----------------------------------------------------------------------===//

    Span spanTest = Span(100);
    spanTest.fill_random(spanTest.begin(), spanTest.end());
    spanTest.display();
    std::cout << "Shortest span: " << spanTest.shortestSpan() << std::endl;
    std::cout << "Longest span: " << spanTest.longestSpan() << std::endl;

    //===----------------------------------------------------------------------===//

    //Span makeMeLag(1000000);
    //makeMeLag.fill_random(makeMeLag.begin(), makeMeLag.end());
    //makeMeLag.display();

}
