#include "../include/easyfind.hpp"

#include <vector>
#include <set>
#include <list>
#include <deque>

int main(void)
{
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    Vector test\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(6);

    easyfind(vec, 4);
    easyfind(vec, 100);

    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    Set test\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;

    std::set<int> set;
    set.insert(4);
    set.insert(2);
    set.insert(16);
    set.insert(0);
    set.insert(-47);
    set.insert(742);

    easyfind(set, -47);
    easyfind(set, 42);

    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    List test\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;

    std::list<int> list;
    list.push_back(90);
    list.push_front(100);
    list.push_back(6);
    list.push_front(-42);
    list.push_back(-7);
    list.push_front(0);

    easyfind(list, 100);
    easyfind(list, 99);

    // deque are similar to linked list but are stored contiguously in memory so you can access an element in O(1)
    // you can also access directly the end or the begining of the deque in O(1)
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;
    std::cout << "\033[31m//    Deque test\033[0m" << std::endl;
    std::cout << "\033[31m//===" << std::string(70, '-') << "===//\033[0m" << std::endl;

    std::list<int> deque;
    deque.push_back(120);
    deque.push_front(10);
    deque.push_back(6);
    deque.push_front(42);
    deque.push_back(9);
    deque.push_front(0);

    easyfind(deque, 120);
    easyfind(deque, 1);

    return 0;
}