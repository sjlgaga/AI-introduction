#include <iostream>
#include <cstring>
using namespace std;
int board[4][4], winx, winy;
bool flag = false;
void input()
{
    char a[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '.')
                board[i][j] = 0;
            else if (a[i][j] == 'x')
                board[i][j] = 1;
            else if (a[i][j] == 'o')
                board[i][j] = -1;
        }
    }
}
bool owin()
{
    for (int i = 0; i < 4; i++)
    {
        if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1)
            return true;
    }
    for (int i = 0; i < 4; i++)
    {
        if (board[0][i] == -1 && board[1][i] == -1 && board[2][i] == -1 && board[3][i] == -1)
            return true;
    }
    if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1)
        return true;
    if (board[3][0] == -1 && board[2][1] == -1 && board[1][2] == -1 && board[0][3] == -1)
        return true;
    return false;
}
int xbdwin()
{
    int pt = 0, winway = 0;
    for (int i = 0; i < 4; i++)
    {
        pt = 0;
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 1)
                pt++;
            else if (board[i][j] == -1)
                pt--;
        }
        if (pt == 3)
            winway++;
    } // row
    for (int i = 0; i < 4; i++)
    {
        pt = 0;
        for (int j = 0; j < 4; j++)
        {
            if (board[j][i] == 1)
                pt++;
            else if (board[j][i] == -1)
                pt--;
        }
        if (pt == 3)
            winway++;
    } // col
    pt = 0;
    for (int i = 0; i < 4; i++)
    {

        if (board[i][i] == 1)
            pt++;
        else if (board[i][i] == -1)
            pt--;
    }
    if (pt == 3)
        winway++; // diag1
    pt = 0;
    for (int i = 0; i < 4; i++)
    {

        if (board[3 - i][i] == 1)
            pt++;
        else if (board[3 - i][i] == -1)
            pt--;
    }
    if (pt == 3)
        winway++; // diag2
    return winway;
}
void process()
{
    if (xbdwin() >= 2)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == 0)
                {
                    flag = true;
                    winx = i;
                    winy = j;
                    return;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = 1;
                for (int a = 0; a < 4; a++)
                {
                    for (int b = 0; b < 4; b++)
                    {
                        if (board[a][b] == 0)
                            board[a][b] = -1;
                        if (owin() == true)
                        {
                            flag = false;
                            return;
                        }
                        board[a][b] = 0;
                    }
                } // o move
                if (xbdwin() >= 2)
                {
                    winx = i;
                    winy = j;
                    return;
                }
                board[i][j] = 0;
            }
        }
    }
}
void output()
{

    if (flag == true)
        cout << "(" << winx << "," << winy << ")" << endl;
    else
        cout << "#####" << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char c;
    memset(board, 0, sizeof(board));
    for (;;)
    {
        cin >> c;
        if (c == '$')
            return 0;
        input();
        process();
        output();
    }
}