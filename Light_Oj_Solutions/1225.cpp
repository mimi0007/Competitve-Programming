#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, c = 1;
    cin >> T;
    while(T--) {
        long long int x;
        cin >> x;
        int sum = 0, y = x;
        while(x != 0) {
            int p = x % 10;
            sum = sum * 10+ p;
            x /= 10;
        }
        if ( y == sum) {
            cout << "Case " << c++ << ": Yes" << endl;
        }

        else {
            cout << "Case " << c++ << ": No" << endl;
        }
    }
    return 0;
}


