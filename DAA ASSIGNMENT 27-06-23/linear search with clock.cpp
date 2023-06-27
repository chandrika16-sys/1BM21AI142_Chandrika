#include <iostream>
#include <ctime>

class LinearSearch {
private:
    int* data;
    int size;
    int comparisons;

public:
    LinearSearch(int* input, int n) : data(input), size(n), comparisons(0) {}

    int search(int target) {
        for (int i = 0; i < size; i++) {
            comparisons++; // Increment the comparisons counter

            if (data[i] == target) {
                return i; // Element found at index i
            }
        }

        return -1; // Element not found
    }

    int getComparisons() {
        return comparisons;
    }
};

int main() {
     int size;
    int i,target,c=0;
   std::cout<<"Enter the number of elements:";
   std::cin>>size;
   int data[size];
   std::cout<<"Enter elements\n";
   for(i=0;i<size;i++)
   {
      std::cin>>data[i];
   }
   std::cout<<"Enter element to be searched:";
   std::cin>>target;


    LinearSearch linear_search(data, size);

    clock_t start_time = clock();
    int index = linear_search.search(target);
    clock_t end_time = clock();

    double duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    int comparisons = linear_search.getComparisons();

    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;

    if (index != -1) {
        std::cout << "Element " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }

    std::cout << "Number of comparisons: " << comparisons << std::endl;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;

    return 0;
}
