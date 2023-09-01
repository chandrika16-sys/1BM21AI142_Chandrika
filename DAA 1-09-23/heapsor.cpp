#include <iostream>
#include <ctime>
#include <cstdlib>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int choice;
    while(1){
    std::cout << "Choose input method:\n";
    std::cout << "1. Manual Entry\n";
    std::cout << "2. Random Number Generator\n";
    std::cin >> choice;

    int n;
    std::cout << "Enter the number of elements (N): ";
    std::cin >> n;

    int arr[n];
    if (choice == 1) {
        std::cout << "Enter " << n << " integers:\n";
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
    } else if (choice == 2) {
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 1000; // Generate random integers between 0 and 999
        }
    } else {
        std::cout << "Invalid choice\n";
        return 1;
    }

    clock_t startTime = clock();
    heapSort(arr, n);
    clock_t endTime = clock();

    std::cout << "Sorted array: ";
    printArray(arr, n);

    double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC;
    std::cout << "Time taken: " << elapsedTime * 1000 << " ms\n";
    }
    return 0;
}

