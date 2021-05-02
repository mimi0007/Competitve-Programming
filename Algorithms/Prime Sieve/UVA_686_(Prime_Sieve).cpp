#include <bits/stdc++.h>

using namespace std;

int prime[50000], p[50000], k;

void sieve() {
    int r = sqrt(40000 * 1.) + 1;
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i <= r; i++) {
        if(prime[i] == 0) {
            for(int j = i * i; j < 40000; j += i) {
                prime[j] = 1;
            }
        }
    }

    for(int i = 0; i < 40000 ; i++) {
        if(prime[i] == 0) {
            p[k] = i;
            k++;
        }
    }
}

int main() {
    sieve();
    int T, x[50000];
    while(cin >> T) {
        if(T == 0) {
            break;
        }
    int c = 0;
    memset(x, 0, sizeof(x));
    for(int i = 0; i < k; i++) {
        if((p[i] < T) && (prime[T-p[i]] == 0)) {
            if(x[p[i]] == 0 && x[T-p[i]] == 0 ) {
                x[p[i]] = 1;
                x[T-p[i]] = 1;
                c++;
            }
        }
    }
    cout << c << endl;
    }
}
