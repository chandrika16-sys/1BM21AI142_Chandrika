#include <iostream>

using namespace std;

class toh{
    public:
char s;
char d;
char aux;
int n;
};

void toh(int n, char s, char d, char aux) {
    if (n == 1) {
        cout << "Move the first disk from " << s<< " to " << d <<endl;
        return;
    }

    toh(n - 1, s, aux, d);
    cout << "Move the disk " << n << " from " << s << " to " << d <<endl;
    toh(n - 1, aux, d, s);
}

int main() {
    int disk;

    cout << "Enter the number of disks: ";
    cin >> disk;

    toh(disk, 'A', 'C', 'B');

    return 0;
}

