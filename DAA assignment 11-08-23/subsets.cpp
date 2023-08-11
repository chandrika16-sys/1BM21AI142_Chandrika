#include <iostream>
using namespace std;

const int MAX_ELEMENTS = 100; // Maximum number of elements in the set

void printSubset(int subset[], int subsetSize) {
    cout << "Subset: ";
    for (int i = 0; i < subsetSize; ++i) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

void generateSubsets(int set[], int n, int targetSum, int subset[], int subsetSize, int index) {
    if (targetSum == 0) {
        printSubset(subset, subsetSize);
        return;
    }

    if (index == n || targetSum < 0) {
        return;
    }

    subset[subsetSize] = set[index];

    generateSubsets(set, n, targetSum - set[index], subset, subsetSize + 1, index + 1);
    generateSubsets(set, n, targetSum, subset, subsetSize, index + 1);
}

void findSubsets(int set[], int n, int targetSum) {
    int subset[MAX_ELEMENTS];
    generateSubsets(set, n, targetSum, subset, 0, 0);
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    int set[MAX_ELEMENTS];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> set[i];
    }

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    findSubsets(set, n, targetSum);

    return 0;
}

