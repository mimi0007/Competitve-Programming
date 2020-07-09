#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
 
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	ll n, q, k;
	cin >> n >> q >> k;
	ll ar[200003], arr[200003], x, y;
	memset(ar, 0, sizeof(ar));
	//memset(arr, 0, sizeof(arr));
	while(n--) {
		cin >> x >> y;
		ar[x]++; //line sweep
		ar[y+1]--; //line sweep
	}
	for(ll i = 1; i <= 200001 ; i++) {
		ar[i] += ar[i-1]; //cumulative sum
    if(ar[i] >= q)
        arr[i]=1;
      else
        arr[i]=0;
	}
	for(ll i = 1; i <= 200001 ; i++) {
		arr[i] += arr[i-1];
	}
	ll a, b;
	while(k--) {
		cin >> a >> b;
		cout << arr[b]- arr[a-1] << endl;
	}
	return 0;
}
