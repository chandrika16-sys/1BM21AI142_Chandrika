#include <iostream>
#include <cstdlib>
#include <ctime>

class MergeSort {
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

    int mergeCount;

public:
    MergeSort() : mergeCount(0) {}

    void merge(Array& arr, int left, int middle, int right) {
        int leftSize = middle - left + 1;
        int rightSize = right - middle;

        Array leftArr(leftSize);
        Array rightArr(rightSize);

        for (int i = 0; i < leftSize; i++) {
            leftArr[i] = arr[left + i];
            mergeCount++; // Count basic operation
        }

        for (int i = 0; i < rightSize; i++) {
            rightArr[i] = arr[middle + 1 + i];
            mergeCount++; // Count basic operation
        }

        int i = 0, j = 0, k = left;

        while (i < leftSize && j < rightSize) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
            mergeCount++; // Count basic operation
        }

        while (i < leftSize) {
            arr[k] = leftArr[i];
            i++;
            k++;
            mergeCount++; // Count basic operation
        }

        while (j < rightSize) {
            arr[k] = rightArr[j];
            j++;
            k++;
            mergeCount++; // Count basic operation
        }
    }

    void mergeSort(Array& arr, int left, int right) {
        if (left < right) {
            int middle = left + (right - left) / 2;

            mergeSort(arr, left, middle);
            mergeSort(arr, middle + 1, right);
            merge(arr, left, middle, right);
        }
    }

    int getMergeCount() const {
        return mergeCount;
    }
};

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    MergeSort mergeSort;

    MergeSort::Array arr(n);
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random inputs from 0 to 99
    }

    std::cout << "Generated data: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mergeSort.mergeSort(arr, 0, n - 1);

    std::cout << "Sorted data: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of basic operation: " << mergeSort.getMergeCount() << std::endl;

    return 0;
}
