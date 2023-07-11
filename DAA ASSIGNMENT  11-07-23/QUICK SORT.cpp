#include <iostream>
#include <cstdlib>
#include <ctime>

class QuickSort {
private:
    class Array {
    public:
        int* data;
        int size;

        Array(int n) : size(n) {
            data = new int[size];
        }

        ~Array() {
            delete[] data;
        }

        int& operator[](int index) {
            return data[index];
        }
    };

    int partitionCount;

public:
    QuickSort() : partitionCount(0) {}

    int partition(Array& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
                partitionCount++; // Count basic operation
            }
        }

        std::swap(arr[i + 1], arr[high]);
        partitionCount++; // Count basic operation

        return i + 1;
    }

    void quickSort(Array& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);

            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    int getPartitionCount() const {
        return partitionCount;
    }
};

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    QuickSort quickSort;

    QuickSort::Array arr(n);
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random inputs from 0 to 99
    }

    std::cout << "Generated Data: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort.quickSort(arr, 0, n - 1);

    std::cout << "Sorted data: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << " " << quickSort.getPartitionCount() << std::endl;

    return 0;
}
