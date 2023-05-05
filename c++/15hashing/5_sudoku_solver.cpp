// write a program to solve a sudoku puzzle by filling the empty cells.
// recursion and backtracking
// start from (0,0) you want to reach (8,8)
// try out all valid combinations
// initialse ans=false, currently at (x,y)
// if ans= already filled move to next block
// else
// for (numbers=1 to 9)
// if you can place number at (x,y)
// ans=ans or place number at (x,y) and solve for next block
#include <bits/stdc++.h>
using namespace std;
void helper(int r, int c, vector<vector<char>> &a, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> &row, vector<map<int, int>> &col)
{
    if (r == 9)// is row is 9 then it has been solved so print and return
    {
        for (auto it : a)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    if (c == 9)// if column is 9 it means we have reached end of row so move to next row
    {
        helper(r + 1, 0, a, mp, row, col);
        return;
    }
    if (a[r][c] != '.')// if current cell is already filled that means != "." then move to the next column
    {
        helper(r, c + 1, a, mp, row, col);
        return;
    }
    // if current cell is empty then try to fill it with all possible numbers
    for (int i = 1; i <= 9; i++)
    {
        // if the number is not present in the row, column and the 3*3 box then place it
        int rw = r / 3, cl = c / 3;
        if (!mp[{rw, cl}][i] && !row[r][i] && !col[c][i])
        {
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c] = i + '0';
            // after it is placed move to the next column and reset the values to 0
            helper(r, c + 1, a, mp, row, col);// it tries to solve the whole sudoku with the assumption that the current cell is filled with the number i, if it is wrong then it will backtrack here only and try with the next number
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = '.';
        }
    }
}
void solveSudoku(vector<vector<char>> &a)
{
    // 0,0 , 0,1 and all in pair,, inner map key is number(1 to 9) and value is 1 or 0
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);// key is number(1 to 9) and value is 1 or 0
    vector<map<int, int>> col(9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] != '.')// if it is filled then mark it as 1
            {
                mp[{i / 3, j / 3}][a[i][j] - '0'] = 1;// mark it as 1 in the 3*3 box
                row[i][a[i][j] - '0'] = 1;// mark it as 1 in the row
                col[j][a[i][j] - '0'] = 1;// mark it as 1 in the column
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}
int main()
{
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(sudoku);
    return 0;
}