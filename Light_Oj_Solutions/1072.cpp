#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        double R, r, n, y, z, x;
        cin >> R >> n;
        y = ((360.00 / n) /2.00);
        x = ((180.00 - (y + 90.00)) * acos(-1)) / 180.00; // should take all the angles in radian (x * pi / 180)
        z = cos(x);
        r = (z * R) / (z + 1.00);
        printf("Case %d: %.10f\n", i, r);
    }
    return 0;
}
