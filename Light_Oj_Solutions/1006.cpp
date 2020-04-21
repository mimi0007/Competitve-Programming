#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
ll ar[10009], a, b, c, d, e, f;
 
ll fn (int x) {
    if(x == 0) return a;
    if(x == 1) return b;
    if(x == 2) return c;
    if(x == 3) return d;
    if(x == 4) return e;
    if(x == 5) return f;
 
    if(ar[x] != -1) {
        return ar[x]%10000007;
    }
    else {
        ar[x] = (fn(x-1)%10000007 + fn(x-2)%10000007 + fn(x-3)%10000007 + fn(x-4)%10000007 + fn(x-5)%10000007 + fn(x-6)%10000007)%10000007;
        return ar[x];
    }
}
 
int main() {
    int n, cnt= 1, m;
    cin >> m;
    while(m--) {
    cin >> a >> b >> c >> d >> e >> f >> n;
 
    memset(ar, -1, sizeof(ar));
 
    cout << "Case " << cnt++ << ": " << fn(n)%10000007 << endl;
    }
    return 0;
}
