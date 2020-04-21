#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int x, y;
        cin >> x >> y;
        if (x <= y) {
            cout << "Case " << i << ": " << 4*y+19 << endl;
        }

        else {
            cout << "Case " << i << ": " << 4*((x - y)+x)+19 << endl;
        }
    }
    return 0;
}
