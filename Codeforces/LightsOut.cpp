#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> nums(3, vector<int>(3)); // Original matrix
    vector<vector<int>> temp(3, vector<int>(3)); // Temporary matrix for storing changes

    // Input matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> nums[i][j];
            temp[i][j] = nums[i][j]; // Initialize temp with the original values
        }
    }

    vector<int> delRow = {-1, 0, 1, 0}; // Row direction vector (up, right, down, left)
    vector<int> delCol = {0, 1, 0, -1}; // Column direction vector (up, right, down, left)

    // Iterate through the matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (nums[i][j] % 2 == 1) // If the current cell value is odd
            {
                temp[i][j] = !temp[i][j]; // Toggle the current cell
                // Toggle neighboring cells
                for (int k = 0; k < 4; k++)
                {
                    int nRow = i + delRow[k];
                    int nCol = j + delCol[k];
                    if (nRow >= 0 && nRow < 3 && nCol >= 0 && nCol < 3)
                    {
                        temp[nRow][nCol] = !temp[nRow][nCol];
                    }
                }
            }
        }
    }

    // Output the modified matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << temp[i][j];
        }
        cout << endl;
    }

    return 0;
}
