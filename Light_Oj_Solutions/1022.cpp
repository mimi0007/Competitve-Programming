#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        double pi = 2*acos(0.0),r,A;
        cout << pi << endl;
        cin >> r;
        A = ((2.00 * r)*(2.00 * r)) - (pi * r * r);
        printf("Case %d: %.2f\n", i, A);
    }
    return 0;
}
