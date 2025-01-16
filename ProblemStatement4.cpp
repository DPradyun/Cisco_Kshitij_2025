/* Pascals' Triangle Function for 6 lines
       1
      1 1
     1 2 1
    1 3 3 1
   1 4 6 4 1
  1 5 10 10 5 1

Row i will have i elements,
elements in (i+1)th row having correlation with the (i)th row elements.
Fix the code for a seamless run of Pascal's Triangle.
*/


#include <iostream>
#include <vector>

using namespace std;

// Function to generate Pascal's Triangle
vector<vector<int>> generatePascalsTriangle(int numRows) {
    vector<vector<int>> triangle;

    for (int row = 0; row < numRows; row++) {
        vector<int> currentRow(row + 1, 1); 

        for (int col = 1; col < row; col++) {
            currentRow[col] = triangle[row - 1][col] + triangle[row - 1][col] - 1;
        }

        triangle.push_back(currentRow);
    }

    return triangle;
}


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
