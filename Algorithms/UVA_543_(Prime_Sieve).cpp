#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int prime[1000009], p[1000009], k; // in initialization p[less/small value] cannot run, cause p[i] works as a loop for 1000000
//small values can make overflow

void sieve() {
    int r = sqrt(1000003 * 1.) + 2;
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i <= r; i++) {
        if(prime[i] == 0) {
            for (int j = i*i; j <= 1000000 ; j += i) {
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
    k = m;
}

int main() {
    sieve();
    ll T;
    while(cin >> T) {
        if(T == 0) {
            break;
        }
    cout << T << " = ";
    int f = 0;
    for (int i = 0; i < k; i++) {
        if((p[i] < T) && (prime[T-p[i]] == 0) && (T-p[i] % 2 != 0)){ // if we use T/2, it gives a wrong for case - 6 like prime[3-2] = 0
            cout << p[i] << " + " << T-p[i] << endl;
            f = 1;
            break;
        }

    }

    if(f!= 1) {
        cout << "Goldbach's conjecture is wrong." << endl;
    }
    }
    return 0;
}
