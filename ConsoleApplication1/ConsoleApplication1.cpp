#include <iostream>

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void addColumn(int matrix[MAX_ROWS][MAX_COLS], int numRows, int& numCols, int position) {
    if (position < 0 || position > numCols) {
        std::cout << "Invalid position.\n";
        return;
    }

    for (int i = numRows - 1; i >= 0; i--) {
        matrix[i][numCols] = (i > position) ? matrix[i][numCols - 1] : 0;
    }

    numCols++;
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int numRows = 3;
    int numCols = 3;

    std::cout << "Initial Matrix:\n";
    printMatrix(matrix, numRows, numCols);

    int position;
    std::cout << "Enter the position to add a column: ";
    std::cin >> position;

    addColumn(matrix, numRows, numCols, position);

    std::cout << "Matrix after adding a column:\n";
    printMatrix(matrix, numRows, numCols);

    return 0;
}
