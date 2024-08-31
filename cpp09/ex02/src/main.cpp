#include <iostream>
#include <ctime>
#include <sstream>
#include <list>
#include <deque>
#include <algorithm>
#include <limits>

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


template <typename T>
int store_inputs(int argc, char **argv, T &container)
{
    for (int i = 1; i < argc; i++) {
        std::stringstream s(argv[i]);
        int value;
        if (!(s >> value)) {
            std::cout << "Error while converting one of your input to int." << std::endl;
            return 1;
        }
        if (std::find(container.begin(), container.end(), value) != container.end()) {
            std::cout << "Error: Your list of numbers contain duplicates." << std::endl;
            return 1;
        } else {
            container.push_back(value);
        }
    }
    return 0;
}

//===----------------------------------------------------------------------===//

template <typename T>
void binary_search_insertion(T &sorted, int toInsert)
{
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
T merge_insertion_sort(T container)
{
    std::cout << "-----------------------------------------------------" << std::endl;
    for (typename T::iterator it = container.begin(); it != container.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    if (container.size() < 2) {
        return container;
    }

    if (container.size() == 2) {
        if ((*container.begin()) > *(++container.begin())) {
            int temp = (*container.begin());
            (*container.begin()) = *(++container.begin());
             *(++container.begin()) = temp;
        }
        return container;
    }

    typename T::iterator first = container.begin();
    typename T::iterator second = ++container.begin();

    T maxElements;

    long minOfMax = std::numeric_limits<long>::max();
    int secondMin;
    typename T::iterator secondMinIterator;

    while (first != container.end() && second != container.end()) {

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
        std::cout << "Max of pair: <" << *first << ", " << *second << "> is " << max << std::endl;
        maxElements.push_back(max);
        if (*first > *second) {
            typename T::iterator saveFirst = first;
            second++;
            if (second == container.end()) break;
            second++;
            first++;
            first++;
            container.erase(saveFirst);
        } else {
            typename T::iterator saveSecond = second;
            second++;
            if (second == container.end()) break;
            second++;
            first++;
            first++;
            container.erase(saveSecond);
        }

        std::cout << "HO" << std::endl;
    }

    maxElements = merge_insertion_sort(maxElements);

    maxElements.push_front(secondMin);
    container.erase(secondMinIterator);

    for (typename T::iterator it = container.begin(); it != container.end(); it++) {
        binary_search_insertion(maxElements, *it);
    }

    return maxElements;
}


int main(int argc, char **argv)
{
    if (check_inputs(argc, argv) != 0) return 1;

    std::deque<int> deque;
    std::list<int> list;

    // --------------------- DEQUE TEST ------------------- //

    std::clock_t start_deque = std::clock();

    if (store_inputs(argc, argv, deque) != 0) return 1;

    std::cout << "Before: ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    deque = merge_insertion_sort(deque);

    std::cout << "After: ";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    double deque_duration = (std::clock() - start_deque) / (double)CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << deque_duration << "ms" << std::endl;

    // --------------------- LIST TEST ------------------- //

    std::clock_t start_list = std::clock();

    if (store_inputs(argc, argv, list) != 0) return 1;

    list = merge_insertion_sort(list);

    double list_duration = (std::clock() - start_list) / (double)CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << list_duration << "ms" << std::endl;

    return 0;
}
