#include <iostream>

using namespace std;

class A {
    public:
    int s;
    int ele[10];
};

int linearSearch(const A& arr, int key) {
    for (int i = 0; i < arr.s; i++) {
        if (arr.ele[i] == key) {
            return i;
        }
    }
    return 0;
}

int main() {
    A arr;

    cout << "Enter the size of the array: ";
    cin >> arr.s;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < arr.s; i++) {
        cin >> arr.ele[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int result = linearSearch(arr, key);

    if (result == 0) {
        cout << "Element not found in the array.";
    } else {
        cout << "Element found at index " << result << " in the array.";
    }

    return 0;
}


