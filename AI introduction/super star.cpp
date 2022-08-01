#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;
int n;
int direx[27] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int direy[27] = {-1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int direz[27] = {-1, -1, -1, 0, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 0, 1, 1, 1};
bool out(double xx, double yy, double zz)
{
    if (xx < 0 || yy < 0 || zz < 0)
        return true;
    else
        return false;
}
class dot
{
public:
    double corx;
    double cory;
    double corz;
    dot(double xx, double yy, double zz) : corx(xx), cory(yy), corz(zz){};
    double dis(const dot &r)
    {
        return sqrt((corx - r.corx) * (corx - r.corx) + (cory - r.cory) * (cory - r.cory) + (corz - r.corz) * (corz - r.corz));
    }
};
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector<dot> points;

    for (;;)
    {
        cin >> n;
        if (n == 0)
            break;
        double tempx, tempy, tempz;
        points.clear();
        int maxx = 0, minx = 101, maxy = 0, miny = 101, maxz = 0, minz = 101;
        for (int i = 1; i <= n; i++)
        {
            cin >> tempx >> tempy >> tempz;
            if (tempx > maxx)
                maxx = int(tempx) + 1;
            else if (tempx < minx)
                minx = int(tempx);
            if (tempy > maxy)
                maxy = int(tempy) + 1;
            else if (tempy < miny)
                miny = int(tempy);
            if (tempz > maxz)
                maxz = int(tempz) + 1;
            else if (tempz < minz)
                minz = int(tempz);
            dot temp(tempx, tempy, tempz);
            points.push_back(temp);
        }
        vector<dot> bestdot;
        vector<double> bestans;
        for (int m = 0; m < 30; m++)
        {
            double xx = (rand() % (maxx - minx + 1)) + minx;
            double yy = (rand() % (maxy - miny + 1)) + miny;
            double zz = (rand() % (maxz - minz + 1)) + minz;
            dot curdot(xx, yy, zz);
            double curans = 0;
            for (auto i : points)
            {
                if (curans < curdot.dis(i))
                    curans = curdot.dis(i);
            }

            for (double t = 1000; t > 1e-7; t *= 0.9)
            {
                for (int i = 0; i < 27; i++)
                {
                    double tpx = curdot.corx + t * direx[i];
                    double tpy = curdot.cory + t * direy[i];
                    double tpz = curdot.corz + t * direz[i];
                    if (out(tpx, tpy, tpz) == true)
                        continue;
                    dot tpdot(tpx, tpy, tpz);
                    double tpans = 0;
                    for (auto i : points)
                    {
                        if (tpans < tpdot.dis(i))
                            tpans = tpdot.dis(i);
                    }
                    if (tpans < curans)
                    {
                        curans = tpans;
                        curdot = tpdot;
                        break;
                    }
                }
            }
            bestans.push_back(curans);
        }
        double pt = 6000;
        for (auto i : bestans)
        {
            if (pt > i)
                pt = i;
        }
        cout << fixed << setprecision(5) << pt << endl;
    }

    return 0;
}