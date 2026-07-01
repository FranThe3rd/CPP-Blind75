#include <vector>
#include <unordered_set>
#include <iostream>


/*
 * So here we are solving a problem and checking verify that no digit from 1 to 9 repeats 
 * within any single row, column, or 3 × 3 subgrid. 
 * So we create vector of 9 empty sets for rows and columns.
 * Now same thing with blocks since we want to figure our if its part of section as a 3x3 grid.
 * All we do is use integer division, for example lets say our row and columnb was 1,8. We do (1/3)*3+(8/3) = 2
 * Which would be top right section of the board.
 * Anyways we iterate through the rows, and columns, and check if the board is in the sets, if they are, that means
 * they are duplicated and then you return false
 * Remember in c++ you can do integer division with "/" unlike python which is "//".
 *         Columns
        0 1 2 | 3 4 5 | 6 7 8
      +-------+-------+-------+
Row 0 |   0   |   1   |   2   |
Row 1 |   0   |   1   |   2   |
Row 2 |   0   |   1   |   2   |
      +-------+-------+-------+
Row 3 |   3   |   4   |   5   |
Row 4 |   3   |   4   |   5   |
Row 5 |   3   |   4   |   5   |
      +-------+-------+-------+
Row 6 |   6   |   7   |   8   |
Row 7 |   6   |   7   |   8   |
Row 8 |   6   |   7   |   8   |
      +-------+-------+-------+
 *
 *
 *
 * */

bool isValidSudoku(const std::vector<std::vector<char>>& board) {
    std::vector<std::unordered_set<char>> rows(9);
    std::vector<std::unordered_set<char>> cols(9);
    std::vector<std::unordered_set<char>> blocks(9);

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char current = board[r][c];

            if (current == '.') {
                continue;
            }

            int block = (r / 3) * 3 + (c / 3);

            if (rows[r].count(current) ||
                cols[c].count(current) ||
                blocks[block].count(current)) {
                return false;
            }

            rows[r].insert(current);
            cols[c].insert(current);
            blocks[block].insert(current);
        }
    }

    return true;
}

int main() {
std::vector<std::vector<char>> board = {
    {'1','2','.','.','3','.','.','.','.'},
    {'4','.','.','5','.','.','.','.','.'},
    {'.','9','1','.','.','.','.','.','3'},
    {'5','.','.','.','6','.','.','.','4'},
    {'.','.','.','8','.','3','.','.','5'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','.','.','.','.','.','2','.','.'},
    {'.','.','.','4','1','9','.','.','8'},
    {'.','.','.','.','8','.','.','7','9'}
};

bool result = isValidSudoku(board);

std::cout << result;



}
