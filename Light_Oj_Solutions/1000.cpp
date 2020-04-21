#include <bits/stdc++.h>

using namespace std;
int main() {
    int T, a, b, s = 1;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", s++, a+b);
    }
    return 0;
}
