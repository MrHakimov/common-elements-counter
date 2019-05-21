/**
 * @author: Muhammadjon Hakimov
 * created: 4/19/2019 12:45:50
 */

#ifndef COMMON_ELEMENTS_COUNTER
#define COMMON_ELEMENTS_COUNTER

#include <vector>
#include <algorithm>

bool has(std::vector<int> &container, int searchingElement) {
    if (container.empty()) {
        return false;
    }

    unsigned int leftBorder = 0;
    unsigned int rightBorder = container.size();

    while (rightBorder - leftBorder > 1) {
        unsigned int middle = (leftBorder + rightBorder) / 2;

        if (container[middle] <= searchingElement) {
            leftBorder = middle;
        } else {
            rightBorder = middle;
        }
    }

    return (container[leftBorder] == searchingElement);
}

bool has(size_t containerSize, const int *container, int searchingElement) {
    if (containerSize == 0) {
        return false;
    }

    unsigned int leftBorder = 0;
    unsigned int rightBorder = containerSize;

    while (rightBorder - leftBorder > 1) {
        unsigned int middle = (leftBorder + rightBorder) / 2;

        if (container[middle] <= searchingElement) {
            leftBorder = middle;
        } else {
            rightBorder = middle;
        }
    }

    return (container[leftBorder] == searchingElement);
}

// Main solution
unsigned int commonElementsCount(std::vector<int> first, std::vector<int> second) {
    if (first.size() > second.size()) {
        first.swap(second);
    }

    std::sort(first.begin(), first.end());

    unsigned int answer = 0;
    for (int element : second) {
        if (has(first, element)) {
            ++answer;
        }
    }

    return answer;
}

unsigned int commonElementsCount(size_t firstSize, int *first, size_t secondSize, int *second) {
    if (firstSize > secondSize) {
        std::swap(firstSize, secondSize);
        std::swap(first, second);
    }

    std::sort(first, first + firstSize);

    unsigned int answer = 0;
    for (size_t i = 0; i < secondSize; i++) {
        int element = second[i];
        if (has(firstSize, first, element)) {
            ++answer;
        }
    }

    return answer;
}

#endif // COMMON_ELEMENTS_COUNTER
