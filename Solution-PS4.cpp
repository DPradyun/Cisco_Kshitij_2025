// Solution for problem statement 4

#include <iostream>
#include <vector>

using namespace std;

// Function to generate Pascal's Triangle
vector<vector<int>> generatePascalsTriangle(int numRows) {
    vector<vector<int>> triangle;

    for (int row = 0; row < numRows; row++) {
        vector<int> currentRow(row + 1, 1);
// Bug fix 1: The element in the follwing row should always be the additive of value in the current [row - 1][col - 1] and [row - 1][col]
// Faulty code being: currentRow[col] = triangle[row - 1][col] + triangle[row - 1][col] - 1; Would always print 1's
        for (int col = 1; col < row; col++) {
            currentRow[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
        }

        triangle.push_back(currentRow);
    }

    return triangle;
}

// Function to print Pascal's Triangle
void printPascalsTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows=6;

    vector<vector<int>> triangle = generatePascalsTriangle(numRows);

    cout << "Pascal's Triangle:" << endl;
    printPascalsTriangle(triangle);

    return 0;
}
