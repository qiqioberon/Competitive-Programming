#include <iostream>
using namespace std;

int main()
{

    const int size = 101;
    int arr[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = -1;
        }
    }
    arr[1][1] = 1;
    arr[0][0] = 0;
    int i = 1, j = 1;
    int x = 0, y = 0;
    int t = 1;

    while ((x + 2 < size) && (i + 2 < size) && (y + 2 < size) && (j + 2 < size))
    {
        // cout << ".";
        if (t % 2 == 0)
        {
            if (j + 2 < size)
            {
                arr[i][j + 2] = arr[i][j] + 2;
                j += 2;
            }
            if (y + 2 < size)
            {
                arr[x][y + 2] = arr[x][y] + 2;
                y += 2;
            }
        }
        else
        {
            if (i + 2 < size)
            {
                arr[i + 2][j] = arr[i][j] + 2;
                i += 2;
            }
            if (x + 2 < size)
            {
                arr[x + 2][y] = arr[x][y] + 2;
                x += 2;
            }
        }
        t++;
    }

    int inputX, inputY;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> inputX >> inputY;
        if (arr[inputX][inputY] != -1)
            cout << arr[inputX][inputY] << endl;
        else
            cout << "No Number" << endl;
    }

    return 0;
}