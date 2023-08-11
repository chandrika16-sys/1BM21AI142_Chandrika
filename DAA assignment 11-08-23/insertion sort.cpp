#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    int N;
    cout<< "Enter N:";
    cin>>N;
    int arr[N];
    cout << "Generated " << N << " random elements: ";
    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 100; // Randomly choose elements between 0 and 99
        cout << arr[i] << " ";
    }
    cout << endl;

    clock_t start_time = clock();
    insertionSort(arr, N);
    clock_t end_time = clock();

    cout << "Sorted elements: ";
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Time taken for sorting: " << time_taken << " seconds" << endl;

    return 0;
}

