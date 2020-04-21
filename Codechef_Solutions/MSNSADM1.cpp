#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, ar[200], ar1[200];
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> ar[i];
        }

        for(int i = 0; i < N; i++) {
            cin >> ar1[i];
        }

        for(int i = 0; i < N; i++) {
            ar[i] = ar[i] * 20 - ar1[i] * 10;
            if(ar[i] < 0) {
                ar[i] = 0;
            }
        }

        sort(ar, ar+N);
        cout << ar[N-1] << endl;
    }
    return 0;
}
