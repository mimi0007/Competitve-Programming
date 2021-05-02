#include <bits/stdc++.h>

using namespace std;

bool prime[10000009]; // giving int in bool makes WA, because bool = 2 byte, int = 4 byte

vector <int> v; // bool = 20000018 = 20mb < 32 mb. int = 40000036 = 40mb > 32mb, So, will have Memory limit exceeded using int

void sieve() {
    int r = sqrt(10000000 * 1.) + 2;
    prime[0] = 1;
    prime[1] = 1;


    for(int i = 4; i <= 10000000; i += 2) { // for 2, non primes without 2, thats why from 4
        prime[i] = 1;
    }
    v.push_back(2);
    for(int i = 3; i <= 10000000; i += 2) {
        if(prime[i] == 0) {
            v.push_back(i);
            if(i <= r) {
            for(int j = i * i; j <= 10000000; j += i) {
                prime[j] = 1;
                }
            }
        }
    }
}

int main() {
    sieve();
    int T, x;
    cout << sizeof(int) <<endl;
    scanf("%d", &x);
    for(int i = 1; i <= x; i++) {
        scanf("%d", &T);
        int c = 0;
        for(int j = 0; j < v.size(); j++) {
            if(v[j] < T && (prime[T-v[j]] == 0) && (v[j] <= T-v[j])) {
                c++;
            }
        }
        printf("Case %d: %d\n", i, c);
    }
    return 0;
}
