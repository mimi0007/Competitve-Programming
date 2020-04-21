#include <bits/stdc++.h>

using namespace std;

int prime[1000009], p[1000009];

void sieve() {
    int r = sqrt(1000000 * 1.) + 2; // 1 non prime, 0 prime
    for(int i = 2; i <= r; i++) {
    prime[0] = 1;
    prime[1] = 1;
        if(prime[i] == 0) {
            for (int j = i * i; j <= 1000000; j = j + i) {
                prime[j] = 1;
            }
        }
    }
    int m = 0;
    for(int i = 2; i <= 1000000 ; i++) {
        if(prime[i] == 0) {
            p[m] = i;
            m++;
        }
    }
}

int main() {
    sieve();
    long long int T;
    while(cin >> T) {
        if(T == 0) {
            break;
        }
    cout << T << ":" << endl;
    int f = 0;
    for(int i = 0; i < 78498; i++) { // with the last iteration, m = 78498, p[i] < T, otherwise the difference will be - (minus)
        if (p[i]<T/2 && prime[T-p[i]] == 0) { // again, if we give p[i] < T/2, then the execution will be less than it was before
             cout << p[i] << "+" << T-p[i] << endl; //like for 12 - 3 9, 5 7, 7 5, 9 3, now the execution time is getting half
            f = 1;
            break;
        }
    }
    if(f != 1) {
        cout << "NO WAY!" << endl;
    }
    }
    return 0;
}
