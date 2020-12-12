#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
 
int main() {
//	freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	ll T;
	cin >> T;
	while(T--) {
		ll a , b;
		cin >> a >> b;
		char s[600][600]; 
		ll ar[600][600], sum = 0;
		memset(ar, 0, sizeof(ar));
		for(int i = 1; i <= a; i++) {
			for(int j = 1; j <= b; j++) {
				cin >> s[i][j];
				if(s[i][j] == '*') {
					ar[i][j] += ar[i][j-1]+1;
				}
					
				else {
					if(j-1 >= 1)
						ar[i][j] += ar[i][j-1];
				}
			}
		}
		//ar is 0 indexed,
		for(int i = 1; i <= a; i++) {
			for(int j = 1; j <= b; j++) {
				if(s[i][j] == '*') {
					sum++;
					for(int k = i+1, l = 3, n = 1, m = 2; k <= a; k++, l += 2, n += 1, m += 1) {
						if(j+n <= b && j-m >= 0) {	//boundaries
							if(ar[k][j+n] - ar[k][j-m] == l)
								sum++; 
									
							else
								break;
						}
						
						else
							break;
					}                                                             
				}
			}
		}
		
		cout << sum << endl;
		
	}	
	return 0;
}
