#include <iostream>
#include <unordered_map>
#include <bitset>
using namespace std;

bool isValid(vector<vector<char>>& board, unordered_map<int, bitset<9>>& rowSet, 
                unordered_map<int, bitset<9>>& colSet, 
                unordered_map<int, bitset<9>>& boxSet, 
                int row, int col, char num) {
        int digit = num - '1';  // Convert char to 0-based index
        
        // Check if digit exists in row, column, or box
        if (rowSet[row][digit]) return false;
        if (colSet[col][digit]) return false;
        if (boxSet[(row/3)*3 + (col/3)][digit]) return false;
        
        return true;
    }

bool findEmptyCell(vector<vector<char>>& board, int& row, int& col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == '.') 
                return true;
        }
    }
    return false;
}
bool solve(vector<vector<char>>& board, 
        unordered_map<int, bitset<9>>& rowSet,
        unordered_map<int, bitset<9>>& colSet,
        unordered_map<int, bitset<9>>& boxSet) {
    
    int row, col;
    if (!findEmptyCell(board, row, col)) return true;

    for (char num = '1'; num <= '9'; num++) {
        if (isValid(board, rowSet, colSet, boxSet, row, col, num)) {
            board[row][col] = num;
            int digit = num - '1';
            rowSet[row].set(digit);
            colSet[col].set(digit);
            boxSet[(row/3)*3 + (col/3)].set(digit);

            if (solve(board, rowSet, colSet, boxSet)) return true;

            // Backtrack
            board[row][col] = '.';
            rowSet[row].reset(digit);
            colSet[col].reset(digit);
            boxSet[(row/3)*3 + (col/3)].reset(digit);
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    // Maintaining set of rows to check validity in O(1);
    unordered_map<int, bitset<9>> rowSet;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            rowSet[i].set(board[i][j] - '1');
        }
    }
    
    // Maintaining set of cols to check validity in O(1);
    unordered_map<int, bitset<9>> colSet;
    for (int c = 0; c < 9; c++) {
        for (int r = 0; r < 9; r++) {
            if (board[r][c] == '.') continue;
            colSet[c].set(board[r][c] - '1');
        }
    }

    // Maintaining set of boxes to check validity in O(1);
    unordered_map<int, bitset<9>> boxSet;
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int boxNum = (i/3)*3 + (j/3);
            for (int row = i; row < i + 3; row++) {
                for (int col = j; col < j + 3; col++) {
                    if (board[row][col] == '.') continue;
                    boxSet[boxNum].set(board[row][col] - '1');
                }
            }
        }
    }
    solve(board, rowSet, colSet, boxSet);
}

int main() {
    
    return 0;
}