#include <iostream>
#include <ctime>
#include <sstream>
#include <list>
#include <deque>
#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

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
        typename T::iterator middle = left; // start from left to determine the middle
        // O(1) for queu and O(N) for lists
        std::advance(middle, std::distance(left, right) / 2); // determine the middle 

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
void merge_insertion_sort(T &container) {

    if (container.size() < 2) {
        return;
    }

    std::vector<int> maxElements;
    std::vector<int> minElements;

    std::pair<long, int> save(std::numeric_limits<long>::max(), 0); // minOfMax, his pair

    // Step 1 and 2: Create pairs and create minElements and maxElements
    typename T::iterator it = container.begin();
    while (it != container.end()) {
        int first = *it++;
        if (it == container.end()) {
            minElements.push_back(first);
            break;
        }
        int second = *it++;

        if (first > second) {
            if (first < save.first) {
                save.first = first;
                save.second = second;
            }
            maxElements.push_back(first);
            minElements.push_back(second);
        } else {
            if (second < save.first) {
                save.first = second;
                save.second = first;
            }
            maxElements.push_back(second);
            minElements.push_back(first);
        }
    }

    // Step 3: Sort the maxElements (S) recursively in ascending order.
    T maxElementsSorted(maxElements.begin(), maxElements.end());
    merge_insertion_sort(maxElementsSorted);

    // Step 4: Insert the pair of the smallest element from maxElement at the begining of maxElementsSorted
    maxElementsSorted.push_front(save.second);
    std::vector<int>::iterator it2 = find(minElements.begin(), minElements.end(), save.second);
    if (it2 != minElements.end())
        minElements.erase(it2);

    // Step 5: Merge minElements into the sorted maxElements using binary search
    for (typename std::vector<int>::iterator it = minElements.begin(); it != minElements.end(); ++it) {
        binary_search_insertion(maxElementsSorted, *it);
    }

    container = maxElementsSorted;
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

    merge_insertion_sort(deque);

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

    merge_insertion_sort(list);

    double list_duration = (std::clock() - start_list) / (double)CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << list_duration << "ms" << std::endl;

    return 0;
}
