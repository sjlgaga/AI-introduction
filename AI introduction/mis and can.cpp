#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
int m, n;
int closed[1010][1010][2];
struct State
{
    int m, c; //传教士和食人魔数
    int dep;  //已划船次数
    int boat; //左岸是否有船
};
queue<State> q;
int bfs(State s)
{
    if (s.m == 0 && s.c == 0)
    {
        return s.dep;
    }
    if (closed[s.m][s.c][s.boat] == 1) //闭节点
        return -1;
    closed[s.m][s.c][s.boat] = 1; //放入闭节点集
    if (s.boat == 1)
    {
        for (int i = n; i >= 1; i--)
        {                      //从左往右，船上载i个人
            if (i > s.m + s.c) //如果多于总人数
                continue;
            for (int j = i; j >= 0; j--)
            {                               // j个食人魔,i-j个传教士
                if (j > s.c || i - j > s.m) //如果多于实际的人数
                    continue;
                if (j != i && j > i - j) //船上有传教士而且少于食人魔
                    continue;
                if (s.m - (i - j) != 0 && (s.m - (i - j) != s.c - j) && s.m - (i - j) != m) //船往右走，左岸剩下的传教士和食人魔不为0且左岸传教士不等于左岸的食人魔数且（那么下一个状态必定非法）
                    continue;
                if (closed[s.m - (i - j)][s.c - j][0] == 1)
                    continue;
                if (s.m - (i - j) == 0 && s.c - j == 0)
                    return s.dep + 1;
                State next;
                next.boat = 0;
                next.m = s.m - (i - j);
                next.c = s.c - j;
                next.dep = s.dep + 1;
                q.push(next); //放入开节点集
            }
        }
    }
    else
    {
        for (int i = 1; i <= 2; i++)
        {                              //从右往左，船上载i个人
            if (i > 2 * m - s.m - s.c) //如果多于总人数
                continue;
            for (int j = i; j >= 1; j--)
            {                                       // j个食人魔,i-j个传教士
                if (j > m - s.c || i - j > m - s.m) //如果多于实际的人数
                    continue;
                if (j != i && j > i - j) //船上有传教士而且少于食人魔
                    continue;
                if (m - s.m - (i - j) != 0 && (m - s.m - (i - j) != m - s.c - j) && s.m != 0) //船往左走，右岸剩下的传教士不为0且不等于右岸的食人魔数而且不是全部（那么下一个状态必定非法）
                    continue;
                if (closed[s.m + (i - j)][s.c + j][1] == 1)
                    continue;
                State next;
                next.boat = 1;
                next.m = s.m + (i - j);
                next.c = s.c + j;
                next.dep = s.dep + 1;
                q.push(next); //放入开节点集
            }
        }
    }
    return -1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> m >> n;
    State initial;
    initial.c = initial.m = m;
    initial.boat = 1;
    initial.dep = 0;
    q.push(initial);
    memset(closed, 0, sizeof(closed));
    int ans = -1;
    State s;
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        ans = bfs(s);
        if (ans != -1)
        {
            break;
        }
    }
    cout << ans;
    return 0;
}
