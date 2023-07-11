#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class QuickSort {
private:
    std::vector<int> data;
    int operations;

public:
    QuickSort() : operations(0) {}

    void generateRandomData(int size) {
        data.clear();
        data.reserve(size);

        std::srand(std::time(nullptr));
        for (int i = 0; i < size; ++i) {
            int randomValue = std::rand() % 100;
            data.push_back(randomValue);
        }
    }

    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
                ++operations;
            }
            ++operations;
        }

        std::swap(arr[i + 1], arr[high]);
        ++operations;
        return (i + 1);
    }

    void quickSort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);

            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    void sort() {
        operations = 0;
        quickSort(data, 0, data.size() - 1);
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
    QuickSort sorter;
    int size;

    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    sorter.generateRandomData(size);
    std::cout << "Generated data: ";
    sorter.printData();

    sorter.sort();
    std::cout << "Sorted data: ";
    sorter.printData();

    std::cout << "Number of basic operations: " << sorter.getOperations() << std::endl;

    return 0;
}

