#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

#include <cstdlib>
#include <time.h>
#include <iostream>

Base *generate(void)
{
    static bool seeded;

    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    int value = rand();
    if (value % 3 == 0) {
        return new A();
    }
    if (value % 2 == 0) {
        return new B();
    }
    if (value % 1 == 0) {
        return new C();
    }
    return 0;
}

void identify(Base* p)
{
    if (!p)
        return ;
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    } catch (std::exception &e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (std::exception &e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (std::exception &e) {}
}

int main(void)
{
    for (int i = 0; i < 10; i++) {
        Base *ptr = generate();
        if (ptr) {
            identify(ptr);
            identify(*ptr);
            delete(ptr);
        }
        std::cout << "\033[32m" << std::string(40, '=') << "\033[0m" << std::endl;
    }
}