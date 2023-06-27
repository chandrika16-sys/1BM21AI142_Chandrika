#include <iostream>
#include <ctime>

class SelectionSort {
private:
    int comparisons;
    int swaps;
public:
    SelectionSort() : comparisons(0), swaps(0) {}

    void sort(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            int min_idx = i;

            for (int j = i + 1; j < size; j++) {
                comparisons++; // Increment the comparisons counter

                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }

            if (min_idx != i) {
                std::swap(arr[i], arr[min_idx]);
                swaps++; // Increment the swaps counter
            }
        }
    }

    int getComparisons() {
        return comparisons;
    }

    int getSwaps() {
        return swaps;
    }
};

int main() {
 int size;
 int arr[size];
    std::cout<<"Enter the number of elements:";
   std::cin>>size;
   srand(time(nullptr));
 for(int i=0;i<size;i++)
 {
     arr[i]=rand()% size;
 }

    SelectionSort sorter;

    clock_t start_time = clock();
    sorter.sort(arr, size);
    clock_t end_time = clock();

    double duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    int comparisons = sorter.getComparisons();
    int swaps = sorter.getSwaps();

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of comparisons: " << comparisons << std::endl;
    std::cout << "Number of swaps: " << swaps << std::endl;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;

    return 0;
}
