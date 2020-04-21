#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        double ox, oy, ax, ay, bx, by, oa, oc, cx, cy, x, arc;
        cin >> ox >> oy >> ax >> ay >> bx >> by;
        oa = sqrt(((ox - ax)*(ox - ax)+(oy - ay)*(oy - ay))* 1.);
        cx = (ax + bx) / 2.00;
        cy = (ay + by) / 2.00;
        oc = sqrt(((ox - cx)*(ox - cx)+(oy - cy)*(oy - cy)) * 1.);
        x = ((acos(oc / oa)) * 180.00) / (acos(-1)); //because c++ gives angle in radian standard
        arc = (x * acos(-1) * oa) / 90.00;
        printf("Case %d: %.10f\n", i, arc);
    }
    return 0;
}
