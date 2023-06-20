#include <iostream>

using namespace std;

class A{
    public:
    int s;
    int ele[10];
};

int binarySearch(const A& arr, int key) {
    int left = 0;
    int right = arr.s - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr.ele[mid] == key) {
            return mid;
        }
        else if (arr.ele[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;
}

int main() {
    A arr;

    cout << "Enter the size of the array: ";
    cin >> arr.s;

    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < arr.s; i++) {
        cin >> arr.ele[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int result = binarySearch(arr, key);

    if (result == 0) {
        cout << "Element not found in the array.";
    }
    else {
        cout << "Element found at index " << result << " in the array.";
    }

    return 0;
}
