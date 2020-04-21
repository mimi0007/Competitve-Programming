#include <bits/stdc++.h>

using namespace std;

vector <unsigned long long int> v;
bool ar[25];

void fact() {
    v.push_back(1);
    for(int i = 1; i < 20; i++) {
        v.push_back(i * v[i - 1]);
    }
}


int main() {
    fact(); //fun complexity doesn't work for calling a function in the first of the main function (when stores values)
    int T;
    unsigned long long int x, k;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        memset(ar, 0, sizeof(ar));
        cin >> x;
        int c = 0, m = 0;
        for(int j = 19; j >= 0; j--) {
            if(x >= v[j] && x != 0) {
                ar[j] = 1;
                c++;
                x = x - v[j];
            }
        }

        printf("Case %d: ", i);
        if(x == 0) {
            for(int j = 0; j < 25; j++) {
            if(ar[j] == 1) {
                m++;
                cout << j << "!";
                if(m < c) {
                    cout << "+";
                }
            }
        }
        cout << endl;
        }

        else {
            cout << "impossible" << endl;
        }

    }
    return 0;
}
