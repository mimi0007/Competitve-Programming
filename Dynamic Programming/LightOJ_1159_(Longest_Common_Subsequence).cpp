#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
#define MOD 1000000007

ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; //kings move - U, D, R, L, LU, RU, LD, RD

int dp[58][58][58], x, y, z; //3d array for 3 strings
string a, b, c;

int rec(int i, int j, int k) {
	if(i >= x || j >= y || k >= z) 
		return 0;
		
	if(dp[i][j][k] != -1)
		return dp[i][j][k];
		
	if(a[i] == b[j] && b[j] == c[k]) 
		return dp[i][j][k] = rec(i+1, j+1, k+1) + 1;
	
	else
		return dp[i][j][k] =  max(rec(i+1, j, k), max(rec(i, j+1, k), rec(i, j, k+1)));	
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	//freopen("/home/mimi0007/Desktop/Temp/out", "w", stdout);
	fasterInOut;
	int T;
	cin >> T;
	for(int kk = 1; kk <= T; kk++) {
		cin >> a >> b >> c;
		x = a.size();
		y = b.size();
		z = c.size();
		memset(dp, -1, sizeof(dp));
		cout << "Case " << kk << ": " << rec(0, 0, 0) << endl;
	}
	return 0;                            
}
