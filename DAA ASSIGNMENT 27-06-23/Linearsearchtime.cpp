#include <iostream>

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

    double getEfficiency() {
        return static_cast<double>(comparisons) / size;
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
    int index = linear_search.search(target);
    double efficiency = linear_search.getEfficiency();

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

    std::cout << "Efficiency of linear search: " << efficiency << std::endl;

    return 0;
}

