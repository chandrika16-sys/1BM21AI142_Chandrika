#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<int>& board) {
    for (int prevRow = 0; prevRow < row; ++prevRow) {
        if (board[prevRow] == col ||
            board[prevRow] - prevRow == col - row ||
            board[prevRow] + prevRow == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueensUtil(int row, int n, vector<int>& board, vector<vector<string>>& solutions) {
    if (row == n) {
        vector<string> solution;
        for (int i = 0; i < n; ++i) {
            string rowStr(n, '.');
            rowStr[board[i]] = 'Q';
            solution.push_back(rowStr);
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board)) {
            board[row] = col;
            solveNQueensUtil(row + 1, n, board, solutions);
            board[row] = -1;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> board(n, -1);
    solveNQueensUtil(0, n, board, solutions);
    return solutions;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    int count = 1;
    for (const auto& solution : solutions) {
        cout << "Solution " << count << ":\n";
        for (const string& row : solution) {
            cout << row << "\n";
        }
        cout << "\n";
        count++;
    }

    return 0;
}
