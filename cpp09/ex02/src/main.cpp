#include <iostream>
#include <ctime>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <list>
#include <deque>

//===----------------------------------------------------------------------===//
//                       Parsing
//===----------------------------------------------------------------------===//

int check_inputs(int argc, char **argv)
{
    if (argc < 3) {
        std::cerr << "Error: Not enough arguments." << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!std::isdigit(argv[i][j])) {
                std::cerr << "Error: Inputs incorrect (check for negative numbers)." << std::endl;
                return 1;
            }
        }
    }

    return 0;
}

int store_inputs(int argc, char **argv, std::deque<int> &deque)
{
    for (int i = 1; i < argc; i++) {
        std::stringstream s(argv[i]);
        int value;
        if (!(s >> value)) {
            std::cout << "Error while converting one of your input to int." << std::endl;
            return 1;
        }
        if (std::find(deque.begin(), deque.end(), value) != deque.end()) {
            std::cout << "Error: Your list of numbers contain duplicates." << std::endl;
            return 1;
        } else {
            deque.push_back(value);
        }
    }
    return 0;
}

//===----------------------------------------------------------------------===//

template <typename T>
void insertions()
{
    return;
}

template <typename T>
void binary_search_insertion(T &sorted, int toInsert)
{
    std::cout << "no" <<std::endl;
    typename T::iterator left = sorted.begin();
    typename T::iterator right = sorted.end();

    

    while (left != right) {
        typename T::iterator middle = left;
        std::advance(middle, std::distance(left, right) / 2);

        if (toInsert < *middle) {
            right = middle;
        } else {
            left = middle;
            ++left;
        }
    }
    sorted.insert(left, toInsert);
}

template <typename T>
void merge_insertion_sort(T &container)
{
    if (container.size() < 2) {
        return ;
    }

    if (container.size() == 2) {
        if ((*container.begin()) > *(++container.begin())) {
            int temp = (*container.begin());
            (*container.begin()) = *(++container.begin());
             *(++container.begin()) = temp;
        }
        return ;
    }

    typename T::iterator first = container.begin();
    typename T::iterator second = ++container.begin();

    T maxElements;

    int minOfMax = 999999;
    int secondMin;
    typename T::iterator secondMinIterator;

    while (first != container.end() && second != container.end()) { //find the pair of the first element of maxElements

        int max = std::max(*first, *second);

        if (minOfMax > max) {
            minOfMax = max;
            if (max == *first) {
                secondMin = *second;
                secondMinIterator = second;
            } else {
                secondMin = *first;
                secondMinIterator = first;
            }
        }
        maxElements.push_back(max);
        if (*first > *second) {
            first = container.erase(first);
        } else {
            second = container.erase(second);
        }
        first++;
        second++;
    }

    merge_insertion_sort(maxElements); // sorting max elements using merge insertion sort

    maxElements.push_front(secondMin);
    container.erase(secondMinIterator);

    for (typename T::iterator it = container.begin(); it != container.end(); it++) {
        binary_search_insertion(maxElements, *it);
    }

    for (typename T::iterator it = maxElements.begin(); it != maxElements.end(); it++) {
        container.push_back(*it);
    }
}

int main(int argc, char **argv)
{
    std::deque<int> deque;

    std::cout << "hello" << std::endl;

    if (check_inputs(argc, argv) != 0) return 1;
    if (store_inputs(argc, argv, deque) != 0) return 1;

    std::list<int> list(deque.begin(), deque.end());

    merge_insertion_sort(deque);


    std::clock_t start = std::clock();
    double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "Execution time: "<< duration * 1000000 << "μs" <<std::endl;

    return 0;
}