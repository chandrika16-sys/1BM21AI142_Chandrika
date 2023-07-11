#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class MergeSort {
private:
    std::vector<int> data;
    int operations;

public:
    MergeSort() : operations(0) {}

    void generateRandomData(int size) {
        data.clear();
        data.reserve(size);

        std::srand(std::time(nullptr));
        for (int i = 0; i < size; ++i) {
            int randomValue = std::rand() % 100;  // Generates random numbers between 0 and 99
            data.push_back(randomValue);
        }
    }

    void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& merged) {
        int leftSize = left.size();
        int rightSize = right.size();
        int i = 0, j = 0;

        while (i < leftSize && j < rightSize) {
            if (left[i] <= right[j]) {
                merged.push_back(left[i]);
                ++i;
            } else {
                merged.push_back(right[j]);
                ++j;
            }
            ++operations;
        }

        while (i < leftSize) {
            merged.push_back(left[i]);
            ++i;
            ++operations;
        }

        while (j < rightSize) {
            merged.push_back(right[j]);
            ++j;
            ++operations;
        }
    }

    void mergeSort(std::vector<int>& arr) {
        int size = arr.size();
        if (size <= 1)
            return;

        int mid = size / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());

        mergeSort(left);
        mergeSort(right);

        arr.clear();
        merge(left, right, arr);
    }

    void sort() {
        operations = 0;
        mergeSort(data);
    }

    void printData() const {
        for (int i : data) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    int getOperations() const {
        return operations;
    }
};

int main() {
    MergeSort sorter;
    int size;

    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    sorter.generateRandomData(size);
    std::cout << "data: ";
    sorter.printData();

    sorter.sort();
    std::cout << "Sorted data: ";
    sorter.printData();

    std::cout << "Number of basic operations: " << sorter.getOperations() << std::endl;

    return 0;
}

