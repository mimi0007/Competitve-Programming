#include<bits/stdc++.h>

using namespace std;

int prime[1009], p[1009]; // initial value will be 0 for global declaration

void sieve() {
    int r = sqrt(1000 * 1.) + 2; // sqrt sometimes returns double values, that why multiplying 1.
    prime[0] = 1;
    prime[1] = 0;
    for(int i = 2; i <= r; i++) {
        if(prime[i] == 0) {
            for(int j = i * i; j <= 1000 ; j = j + i) {
                prime[j] = 1;

            }
        }
    }


    int k, m;
    for(int k = 1, m = 0; k <= 1000; k++) {
        if(prime[k] == 0) {
            p[m] = k; //serially keeping all the prime values like 3rd prime value, prime[3] = 5
            m++;
        }
    }
}

int main() {
    sieve();
    int a, b;
    while(cin >> a >> b) {
        int c = 0;
        cout << a << " " << b << ":";
        for(int i = 1; i <= a; i++) {
            if(prime[i] == 0) {
                c++;
            }
        }

        if (c % 2 != 0 ) {
            int y = 2*b - 1;
            if(y < c) {
                int x = (c - y) / 2;
                for(int i = x; i < x + y ; i++) {
                        cout << " " << p[i];
                }
            }

            else {
                for(int i = 1; i <= a ; i++) {
                        if(prime[i] == 0)
                        cout << " " << i;
                }
            }
            cout << endl;
        }

        else {
            int y = 2*b;
            if( y < c) {
                int x = (c - y) / 2;
                for(int i = x; i < x + y ; i++) {
                        cout << " " << p[i];
                }
            }

            else {
                for(int i = 1; i <= a ; i++) {
                        if(prime[i] == 0)
                        cout << " " << i;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
