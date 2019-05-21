/**
 * @author: Muhammadjon Hakimov
 * created: 4/19/2019 02:05:13
 */

#include "gtest.h"
#include "CommonElementsCounter.h"
#include <vector>
#include <random>

TEST(CheckSame, SameEmptyVectors) {
    std::vector<int> first;
    std::vector<int> second;

    int result = commonElementsCount(first, second);
    EXPECT_EQ(result, 0);
}

TEST(CheckSame, SameEmptyArrays) {
    int first[] = {};
    int second[] = {};

    int result = commonElementsCount(0, first, 0, second);
    EXPECT_EQ(result, 0);
}

TEST(CheckSame, SameVectors) {
    std::vector<int> first = {0, 1, 2, 3, 4, 5};
    std::vector<int> second = {0, 1, 2, 3, 4, 5};

    int result = commonElementsCount(first, second);
    EXPECT_EQ(result, 6);
}

TEST(CheckSame, SameArrays) {
    int first[] = {0, 1, 2, 3, 4, 5};
    int second[] = {0, 1, 2, 3, 4, 5};

    int result = commonElementsCount(6, first, 6, second);
    EXPECT_EQ(result, 6);
}

TEST(CheckSameSizes, SingleSameVectors) {
    std::vector<int> first = {1};
    std::vector<int> second = {1};

    int result = commonElementsCount(first, second);
    EXPECT_EQ(result, 1);
}

TEST(CheckSameSizes, SingleDifferentVectors) {
    std::vector<int> first = {47451};
    std::vector<int> second = {541};

    int result = commonElementsCount(first, second);
    EXPECT_EQ(result, 0);
}

TEST(CheckSameSizes, SingleSameArrays) {
    int first[] = {-1};
    int second[] = {-1};

    int result = commonElementsCount(1, first, 1, second);
    EXPECT_EQ(result, 1);
}

TEST(CheckSameSizes, SingleDifferentArrays) {
    int first[] = {-5261};
    int second[] = {-76382};

    int result = commonElementsCount(1, first, 1, second);
    EXPECT_EQ(result, 0);
}

TEST(CheckSameSizes, VectorTest) {
    std::vector<int> first = {2, 1, 0};
    std::vector<int> second = {0, 2, 1};

    int result = commonElementsCount(first, second);
    EXPECT_EQ(result, 3);

    first = {4, 6, 34, -2, 3};
    second = {1, 2, 8, -2, 4};

    result = commonElementsCount(first, second);
    EXPECT_EQ(result, 2);
    EXPECT_EQ(commonElementsCount(second, first), 2);

    first = {-4, 2, 6, -145, 5};
    second = {9, 0, 4, -23, -143};

    result = commonElementsCount(first, second);
    EXPECT_EQ(result, 0);
}

TEST(CheckSameSizes, ArrayTest) {
    int first[] = {5, 2, 9, 0};
    int second[] = {6, 1, 7, -5};

    int result = commonElementsCount(4, first, 4, second);
    EXPECT_EQ(result, 0);
    EXPECT_EQ(result, commonElementsCount(4, second, 4, first));
}

TEST(CheckDifferentSizes, EmptyVectorTest) {
    std::vector<int> first = {};
    std::vector<int> second = {9, 8, 7};

    int result = commonElementsCount(first, second);
    EXPECT_EQ(result, 0);
}

TEST(CheckDifferentSizes, EmptyVectorAnotherTest) {
    std::vector<int> first = {1, 1, 2, 3};
    std::vector<int> second = {};

    int result = commonElementsCount(first, second);
    EXPECT_EQ(result, 0);
}

TEST(CheckDifferentSizes, EmptyArrayTest) {
    int first[] = {};
    int second[] = {4, 6, 1};

    int result = commonElementsCount(0, first, 3, second);
    EXPECT_EQ(result, 0);
}

TEST(CheckDifferentSizes, EmptyArrayAnotherTest) {
    int first[] = {8, 2, 5, 2};
    int second[] = {};

    int result = commonElementsCount(4, first, 0, second);
    EXPECT_EQ(result, 0);
}

TEST(CheckDifferentSizes, VectorTest) {
    int first1[] = {5, -6, 41, -7453, 63, 635};
    int second1[] = {36, 3727, -7313457, 626, -784, 2542, 7873, 11};

    int result = commonElementsCount(6, first1, 8, second1);
    EXPECT_EQ(result, 0);

    // Checking DESC-sorted
    int first2[] = {-632, -234, -116, -63, -2};
    int second2[] = {652, 43, 1, -2};

    result = commonElementsCount(5, first2, 4, second2);
    EXPECT_EQ(result, 1);

    // Checking ASC-sorted
    int first3[] = {6, 9, 53, 632, 945, 5212, 55555};
    int second3[] = {9, 53, 945};

    result = commonElementsCount(7, first3, 3, second3);
    EXPECT_EQ(result, 3);
    EXPECT_EQ(result, commonElementsCount(3, second3, 7, first3));
}

// Stupid solution for testing correctness of main solution
unsigned int commonElementsCountStupid(std::vector<int> first, std::vector<int> second) {
    unsigned int answer = 0;
    for (int i : first) {
        for (int j : second) {
            if (i == j) {
                ++answer;
            }
        }
    }

    return answer;
}

std::random_device randomDevice;
std::mt19937 generate{randomDevice()};
int MAX_VALUE = 1000000000;
int MIN_VALUE = -1000000000;

void generateSequences(std::vector<int> &first, std::vector<int> &second, int L, int R) {
    size_t firstSize = generate() % (R - L + 1) + L; // Generating size of vector : [L, R]
    first.resize(firstSize);
    size_t secondSize = generate() % (R - L + 1) + L;
    second.resize(secondSize);

    for (int i = 0; i < firstSize; i++) {
        first[i] = generate() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    for (int i = 0; i < secondSize; i++) {
        second[i] = generate() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

TEST(RandomTests, VectorTestSmall) {
    for (int i = 0; i < 100; i++) {
        std::vector<int> first;
        std::vector<int> second;

        generateSequences(first, second, 0, 100);
        EXPECT_EQ(commonElementsCount(first, second), commonElementsCountStupid(first, second));
        EXPECT_EQ(commonElementsCount(first, second), commonElementsCountStupid(second, first));
        EXPECT_EQ(commonElementsCount(second, first), commonElementsCountStupid(first, second));
        EXPECT_EQ(commonElementsCount(second, first), commonElementsCountStupid(second, first));
    }
}

TEST(RandomTests, VectorTestMiddle) {
    for (int i = 0; i < 1000; i++) {
    std::vector<int> first;
    std::vector<int> second;

    generateSequences(first, second, 250, 1000);
    EXPECT_EQ(commonElementsCount(first, second), commonElementsCountStupid(first, second));
    EXPECT_EQ(commonElementsCount(first, second), commonElementsCountStupid(second, first));
    EXPECT_EQ(commonElementsCount(second, first), commonElementsCountStupid(first, second));
    EXPECT_EQ(commonElementsCount(second, first), commonElementsCountStupid(second, first));
    }
}

TEST(RandomTests, VectorTestLarge) {
    for (int i = 0; i < 1000; i++) {
    std::vector<int> first;
    std::vector<int> second;

    generateSequences(first, second, 5000, 10000);
    EXPECT_EQ(commonElementsCount(first, second), commonElementsCountStupid(first, second));
    EXPECT_EQ(commonElementsCount(first, second), commonElementsCountStupid(second, first));
    EXPECT_EQ(commonElementsCount(second, first), commonElementsCountStupid(first, second));
    EXPECT_EQ(commonElementsCount(second, first), commonElementsCountStupid(second, first));
    }
}
