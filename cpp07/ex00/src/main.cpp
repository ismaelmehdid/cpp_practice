#include "../include/swap_min_max.hpp"

#include <iostream>
#include <string>

int main( void )
{
    //===----------------------------------------------------------------------===//
    //                       Subject tests
    //===----------------------------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    Subject tests\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===----------------------------------------------------------------------===//
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;   
    }
    //===----------------------------------------------------------------------===//


    //===----------------------------------------------------------------------===//
    //                       My tests
    //===----------------------------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    My tests\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===----------------------------------------------------------------------===//
    {
        float a = 2.2f;
        float b = 3.9f;
        std::cout << "Before -> a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "After -> a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

        std::cout << std::endl;

        char c = 'c';
        char d = 'd';
        std::cout << "Before -> c = " << c << ", d = " << d << std::endl;
        ::swap( c, d );
        std::cout << "After -> c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

        std::cout << std::endl;

        std::string e = "hello";
        std::string f = "bob";
        std::cout << "Before -> e = " << e << ", f = " << f << std::endl;
        ::swap( e, f );
        std::cout << "After -> e = " << e << ", f = " << f << std::endl;
        std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
        std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
    }
    //===----------------------------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===----------------------------------------------------------------------===//
    return 0;
}
