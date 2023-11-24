#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int baris, kolom;
        cin >> baris >> kolom;
        vector<vector<int>> matrix(baris, vector<int>(kolom, 0));
        int maksimal = 0, x, y;
        for (int i = 0; i < baris; i++)
        {
            for (int j = 0; j < kolom; j++)
            {
                cin >> matrix[i][j];
                if (i == 0)
                {
                    maksimal = max(maksimal, matrix[i][j]);
                    if (matrix[i][j] == maksimal)
                    {
                        x = i;
                        y = j;
                    }
                }
            }
        }
        // cout << endl;
        int terbesar = 0;
        for (int i = baris - 2; i >= 0; i--)
        {
            for (int j = kolom - 1; j >= 0; j--)
            {
                if (j + 1 != kolom && j - 1 != -1)
                {
                    matrix[i][j] += max({matrix[i + 1][j + 1], matrix[i + 1][j], matrix[i + 1][j - 1]});
                }
                else if (j + 1 == kolom)
                {
                    matrix[i][j] += max(matrix[i + 1][j], matrix[i + 1][j - 1]);
                }
                else if (j - 1 == -1)
                {
                    matrix[i][j] += max(matrix[i + 1][j], matrix[i + 1][j + 1]);
                }
                terbesar = max(terbesar, matrix[i][j]);
                // cout << matrix[i][j] << " ";
            }
            // cout << endl;
        }
        // cout << matrix[x][y] << endl;
        cout << terbesar << endl;
    }
}