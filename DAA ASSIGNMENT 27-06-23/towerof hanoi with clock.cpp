#include <iostream>
#include <ctime>

class TowerOfHanoi {
private:
    int numMoves;
public:
    TowerOfHanoi() : numMoves(0) {}

    void solve(int n, char source, char auxiliary, char destination) {
        if (n == 1) {
            moveDisk(source, destination);
        } else {
            solve(n - 1, source, destination, auxiliary);
            moveDisk(source, destination);
            solve(n - 1, auxiliary, source, destination);
        }
    }

    void moveDisk(char source, char destination) {
        numMoves++;
    }

    int getNumMoves() {
        return numMoves;
    }
};

int main() {
    int numDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;

    TowerOfHanoi tower;

    clock_t start_time = clock();
    tower.solve(numDisks, 'A', 'B', 'C');
    clock_t end_time = clock();

    double duration = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    int numMoves = tower.getNumMoves();

    std::cout << "Total moves: " << numMoves << std::endl;
    std::cout << "Time taken: " << duration << " seconds" << std::endl;

    return 0;
}

