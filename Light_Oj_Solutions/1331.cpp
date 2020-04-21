#include <bits/stdc++.h>
 
using namespace std;
#define pi acos(-1)
 
int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        double r1, r2, r3, s, A, a, b, c, x;
        cin >> r1 >> r2 >> r3;
        s = ((r1+r2) + (r2+r3) + (r3+r1)) / 2.00;
        A= sqrt(s * (s-(r1+r2)) * (s-(r2+r3)) * (s-(r3+r1)) * 1.);
        a = acos(((r1+r2)*(r1+r2)+(r3+r1)*(r3+r1)- (r2+r3)*(r2+r3))/ (2.00 * (r1+r2) * (r3+r1))) * (r1 * r1 / 2.00);
        b = acos(((r1+r2)*(r1+r2)+(r2+r3)*(r2+r3)- (r3+r1)*(r3+r1))/ (2.00 * (r1+r2) * (r2+r3))) * (r2 * r2 / 2.00);
        c = acos(((r3+r1)*(r3+r1)+(r2+r3)*(r2+r3)- (r1+r2)*(r1+r2))/ (2.00 * (r1+r3) * (r3+r2))) * (r3 * r3 / 2.00);
        x = A - (a+b+c);
        cout << "Case " << i << ": " << setprecision(10) << x << endl;
    }
    return 0;
}
