#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long _ll;
typedef long double ld;
const ld PI = acosl(-1);

struct Point
{
    _ll x, y;
    Point(_ll x = 0, _ll y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    bool operator!=(const Point &p) const { return x != p.x || y != p.y; }
    ld theta() const { return atan2l(y, x); }
    ld norm() const { return sqrtl(x*x + y*y); }
}O(0,0);

string to_string(Point p)
{
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}


int solve()
{
    int n, cnt = 0;
    _ll x0,Y0,x1,Y1,x,y;
    string op, res;

    n = inf.readInt(0, 23, "n");
    inf.readEoln();
    x0 = inf.readInt(-200'000, 200'000, "x0");
    inf.readSpace();
    Y0 = inf.readInt(-200'000, 200'000, "Y0");
    inf.readEoln();
    x1 = inf.readInt(-200'000, 200'000, "x1");
    inf.readSpace();
    Y1 = inf.readInt(-200'000, 200'000, "Y1");
    inf.readEoln();
    Point s(x0,Y0), t(x1,Y1), p;

    cout << n << '\n' << x0 << ' ' << Y0 << endl;

    while(1)
    {
        op = ouf.readToken("[?!]"); ouf.readSpace();
        if(op == "!") break;
        
        x = ouf.readInt(-200'020, 200'020, "x"); ouf.readSpace();
        y = ouf.readInt(-200'020, 200'020, "y");
        p = Point(x,y);

        if(abs(x-x0) + abs(y-Y0) > 20) 
            quitf(_wa, "too far from start point.");

        ++cnt;
        if(!(t != p))
            printf("233.3333333333333\n");
        else
            printf("%.13Lf\n", (t-p).theta());
        fflush(stdout);
    }

    if(n <= 13)
    {
        res = ouf.readToken();
        if(res == "impossible")
            return 1;
        quitf(_wa, "wrong answer.");
    }
    else
    {
        x = ouf.readInt(-200'020, 200'020, "x"); ouf.readSpace();
        y = ouf.readInt(-200'020, 200'020, "y");
        p = Point(x,y);
        Point d1 = t-s, d2 = t-p;
        if(abs(d2.norm()/max(ld(1.0),d1.norm())) > 3e-4)
            quitf(_wa, ("eps exceeded. expected:"+to_string(t)+" found:"+to_string(p)).c_str());
        if(abs(x-x1) + abs(y-Y1) > 10)
            ++cnt;
        if(n-cnt >= 12)
            return 1;
        else
            quitf(_wa, ("too few Eyes of Ender. expected:"+to_string(t)+" found:"+to_string(p)).c_str());
    }
    quitf(_wa, "what is this?");
}

int main(int argc, char* argv[])
{
    setName("interactor for MC");
    registerInteraction(argc, argv);

    int T = inf.readInt(1, 20000, "T");
    inf.readEoln();

    cout << T << '\n';
    
    for(int i = 0; i < T; ++i)
        solve();

    quitf(_ok, "accepted.");

    return 0;
}