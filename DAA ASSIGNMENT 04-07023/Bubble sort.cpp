#include <iostream>
#include <ctime>
#include <cstdlib>

class Clock {
private:
    std::clock_t start_time;

public:
    void start() {
        start_time = std::clock();
    }

    double elapsed() {
        std::clock_t end_time = std::clock();
        return static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    }
};

void bubbleSort(int arr[], int size, int& basic_ops) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            basic_ops++; // Counting the number of basic operations

            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                basic_ops++; // Counting the number of basic operations
            }
        }
    }
}

void generateRandomInput(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100; // Generate a random number between 0 and 99
    }
}

int main() {
    const int size = 10;
    int arr[size];

    std::srand(std::time(nullptr)); // Seed the random number generator

    generateRandomInput(arr, size);

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    Clock clock;
    clock.start();

    int basic_ops = 0;
    bubbleSort(arr, size, basic_ops);

    double elapsed_time = clock.elapsed();

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Elapsed time: " << elapsed_time << " seconds" << std::endl;
    std::cout << "Number of basic operations: " << basic_ops << std::endl;

    return 0;
}



