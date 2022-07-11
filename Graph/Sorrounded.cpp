/*
Problem to find O sorrounded by X
4 4
X X X X           X X X X
X O O X           X X X X
X X O X    ---->  X X X X
X O X X           X O X X
*/
#include <bits/stdc++.h>
using namespace std;
void change(vector<vector<char>> &mat, int x, int y)
{
    mat[x][y] = '*';
    int dr1[] = {0, 0, 1, -1};
    int dr2[] = {-1, 1, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        int to1 = x + dr1[i];
        int to2 = y + dr2[i];
        if (to1 >= 0 and to1 < mat.size() and to2 >= 0 and to2 < mat.size() and mat[to1][to2] == 'O')
        {
            change(mat, to1, to2);
        }
    }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n = 4;
    int x = n, y = n;
    vector<vector<char>> mat = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}};
    // approach is to check only for corner edges

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 or i == n - 1 or j == 0 or j == n - 1)
            {
                if (mat[i][j] == 'O')
                    change(mat, i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] == 'O' ? mat[i][j] = 'X' : true;
            mat[i][j] == '*' ? mat[i][j] = 'O' : true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}