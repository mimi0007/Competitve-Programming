#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, ar[1009], m;
        cin >> N;
        vector <int> v;
        for(int j = 0; j < N; j++) {
            cin >> ar[j];
        }
        long long int mul;
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
            int sum = 0;
            mul = ar[i] * ar[j];
                while(mul != 0) {
                m = mul % 10;
                sum = sum + m;
                mul = mul / 10;
                }
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());

        cout << v[v.size()-1] << endl;
    }
    return 0;
}
