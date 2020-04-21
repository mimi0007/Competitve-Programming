#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        double a, b, c, d, h, x, y, N;
        cin >> a >> b >> c >> d;
        if(a < c) {
           x = ((c - a) + b + d) /2.00;
           y = sqrt((x * (x - ( c - a)) * (x - b) * ( x - d)) * 1.);
           h = (y * 2.00) / ( c - a);
           N = .50*h*(c+a);
           printf("Case %d: %.7f\n", i, N);
        }

        else if(a > c) {
           x = ((a - c) + b + d) /2.00;
           y = sqrt((x * (x - (a - c)) * (x - b) * ( x - d)) * 1.);
           h = (y * 2.00) / (a - c);
           N = .50*h*(c+a);
           printf("Case %d: %.7f\n", i, N);
        }

        else {
            N = b * d;
            printf("Case %d: %.7f\n", i, N);
        }
    }
    return 0;
}
