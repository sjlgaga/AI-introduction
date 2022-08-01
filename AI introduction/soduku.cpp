#include <iostream>
#include <stdio.h>
using namespace std;
int a[9][9];
bool flag = false;
void input();
void output();
bool judge(int n, int k);
void fill(int n);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testtime;
    cin >> testtime;
    for (int t = 1; t <= testtime; t++)
    {
        flag = false;
        input();
        fill(0);
        if (flag == true)
            output();
        else
            cout << -1;
    }
}

void input()
{
    char c[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> c[i][j];
            a[i][j] = c[i][j] - '0';
        }
    }
}

void output()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

bool judge(int n, int k)
{
    int row = n / 9;
    for (int i = 0; i < 9; i++)
    {
        if (a[row][i] == k)
            return false;
    }
    int col = n % 9;
    for (int i = 0; i < 9; i++)
    {
        if (a[i][col] == k)
            return false;
    }
    for (int i = (n / 27) * 3; i <= (n / 27) * 3 + 2; i++)
    {
        for (int j = (n % 9 / 3) * 3; j <= (n % 9 / 3) * 3 + 2; j++)
        {
            if (a[i][j] == k)
                return false;
        }
    }
    return true;
}

void fill(int n)
{
    if (n > 80)
    {
        flag = true;
        return;
    }
    if (a[n / 9][n % 9] != 0)
    {
        fill(n + 1);
    }
    else
    {
        for (int k = 1; k <= 9; k++)
        {
            if (judge(n, k) == true)
            {
                a[n / 9][n % 9] = k;
                fill(n + 1);
            }
            if (flag == true)
                return;
            a[n / 9][n % 9] = 0;
        }
    }
}