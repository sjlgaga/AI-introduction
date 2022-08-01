#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
int xlen, ylen, hnum;
int direx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int direy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool out(double xx, double yy)
{
    if (xx > xlen || xx < 0 || yy > ylen || yy < 0)
        return true;
    else
        return false;
}
class dot
{
public:
    double corx;
    double cory;
    dot(double xx, double yy) : corx(xx), cory(yy){};
    double dis(const dot &r)
    {
        return sqrt((corx - r.corx) * (corx - r.corx) + (cory - r.cory) * (cory - r.cory));
    }
};
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases;
    vector<dot> points;
    cin >> cases;
    for (int g = 1; g <= cases; g++)
    {
        cin >> xlen >> ylen >> hnum;
        double tempx, tempy;
        points.clear();

        for (int i = 1; i <= hnum; i++)
        {
            cin >> tempx >> tempy;
            dot temp(tempx, tempy);
            points.push_back(temp);
        }
        vector<double> bestans;
        vector<dot> bestdot;
        for (int m = 0; m < hnum; m++)
        {
            dot curdot = points[m];
            double curans = 20000;
            for (int i = 0; i < hnum; i++)
            {
                if (curans > curdot.dis(points[i]))
                    curans = curdot.dis(points[i]);
            }

            for (double t = 1000; t > 1e-6; t *= 0.9)
            {
                for (int i = 0; i < 8; i++)
                {
                    double tpx = curdot.corx + t * direx[i];
                    double tpy = curdot.cory + t * direy[i];
                    if (out(tpx, tpy) == true)
                        continue;
                    dot tpdot(tpx, tpy);
                    double tpans = 20000;
                    for (int i = 0; i < hnum; i++)
                    {
                        if (tpdot.dis(points[i]) < tpans)
                            tpans = tpdot.dis(points[i]);
                    }
                    if (tpans > curans)
                    {
                        curans = tpans;
                        curdot = tpdot;
                        break;
                    }
                }
            }
            bestans.push_back(curans);
            bestdot.push_back(curdot);
        }
        int pt = 0;
        for (int i = 0; i < hnum; i++)
        {
            if (bestans[i] > bestans[pt])
                pt = i;
        }

        cout << "The safest point is (" << fixed << setprecision(1) << bestdot[pt].corx << ", " << bestdot[pt].cory << ")" << endl;
    }

    return 0;
}