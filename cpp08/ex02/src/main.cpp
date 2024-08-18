#include "../include/MutantStack.hpp"

#include <iostream>
#include <list>
int main()
{
    //===----------------------------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    Subject tests\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===----------------------------------------------------------------------===//
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << std::endl;
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
    }
    //===----------------------------------------------------------------------===//
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    My tests\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    //===----------------------------------------------------------------------===//
    {
        {
            std::cout << "\033[31m//    Copy constructor test\033[0m" << std::endl;
            MutantStack<int> mstack;
            mstack.push(42);
            mstack.push(43);
            mstack.push(44);
            for (MutantStack<int>::const_iterator cur = mstack.begin(); cur != mstack.end(); cur++) {
                std::cout << *cur << " ";
            }

            std::cout << std::endl;
            
            MutantStack<int> mStackCopy(mstack);
            for (MutantStack<int>::const_iterator cur = mStackCopy.begin(); cur != mStackCopy.end(); cur++) {
                std::cout << *cur << " ";
            }

            std::cout << std::endl;
        }
        {
            std::cout << "\033[31m//    Assignment Operator Overload test\033[0m" << std::endl;
            MutantStack<int> mstack;
            mstack.push(42);
            mstack.push(43);
            mstack.push(44);
            for (MutantStack<int>::const_iterator cur = mstack.begin(); cur != mstack.end(); cur++) {
                std::cout << *cur << " ";
            }

            std::cout << std::endl;
            
            MutantStack<int> mStackCopy = mstack;
            for (MutantStack<int>::const_iterator cur = mStackCopy.begin(); cur != mStackCopy.end(); cur++) {
                std::cout << *cur << " ";
            }

            std::cout << std::endl;
        }
        {
            // Will not compile as const iterators are read only:
            /*
            MutantStack<int> mstack;
            mstack.push(42);
            mstack.push(43);
            mstack.push(44);
            
            for (MutantStack<int>::const_iterator cur = mstack.begin(); cur != mstack.end(); cur++) {
                (*cur)++;
            }
            */
        }
    }
    return 0;
}