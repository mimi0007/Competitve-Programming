#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        double x, y, h, p;
        cin >> x >> y >> h >> p;
        cout << "Case " << i << ": ";
        double N, m, z = ((x - y) * p) / h; //extra part in between two radiuses
        m = z + y; //extra part + bottom radius = new radius in height p
        N = (acos(-1) * p * (m * m+ m * y+ y * y)) / 3.00;
        printf("%.9f\n", N);
    }
    return 0;
}
