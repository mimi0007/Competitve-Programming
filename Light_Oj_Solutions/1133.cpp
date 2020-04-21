#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string X;
        int m, n, A, B, ar[200];
        cin >> A >> B;
        for (int j = 0; j < A; j++) {
            cin >> ar[j];
        }
        while(B--) {
            cin >> X;
            if(X == "S") {
                cin >> m;
                for (int j = 0; j < A; j++) {
                    ar[j] = ar[j] + m;
                }
            }

            else if (X == "M") {
                cin >> m;
                 for (int j = 0; j < A; j++) {
                    ar[j] = ar[j] * m;
                }
            }

            else if (X == "D") {
                cin >> m;
                 for (int j = 0; j < A; j++) {
                    ar[j] = ar[j] / m;
                }
            }

            else if (X == "P") {
                cin >> m >> n;
                swap(ar[m], ar[n]);
            }

            else if (X == "R") {
                for(int j = 0; j < A/2; j++) {
                    swap(ar[0], ar[A-j-1]);
                }
            }
        }
        cout << "Case " << i << ":" << endl;
        for (int j = 0; j < A-1; j++) {
            cout << ar[j] << " ";
        }
        cout << ar[A-1] << endl;
    }
    return 0;
}
