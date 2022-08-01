#include <iostream>
#include <cmath>
using namespace std;

int num;
const double eps = 1e-2;
int direx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int direy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
struct cod
{
    double xx;
    double yy;
    cod(double x0 = 0, double y0 = 0)
    {
        xx = x0;
        yy = y0;
    }
    double getdis(cod r)
    {
        return sqrt((r.xx - xx) * (r.xx - xx) + (r.yy - yy) * (r.yy - yy));
    }
};
cod dot[110];
double getsum(cod &r)
{
    double sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += r.getdis(dot[i]);
    }
    return sum;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> dot[i].xx >> dot[i].yy;
    double ans = getsum(dot[0]), step = 100;
    cod s = dot[0];
    cod re;
    while (step > eps)
    {
        bool flag = false;
        for (int i = 0; i < 8; i++)
        {
            re = cod(s.xx + step * direx[i], s.yy + step * direy[i]);
            double temp = getsum(re);
            if (temp < ans)
            {
                ans = temp;
                s = re;
                flag = true;
                break;
            }
        }
        if (flag == false)
            step = step / 2;
    }
    cout << int(ans);
}