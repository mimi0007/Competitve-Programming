#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
#define MOD 1000000007

ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; //kings move - U, D, R, L, LU, RU, LD, RD
map < pair <ll, ll> , bool > matrix, vis; //vis became 0 as declared globally
map < pair <ll, ll> , ll > dis; //to store the distance 
ll xx, yy, mx = LONG_LONG_MIN, my = LONG_LONG_MIN;
//mx, my for highest row and column

void BFS(ll sx, ll sy) {
	vis[{sx, sy}] = 1; //visited or not visited
	dis[{sx, sy}] = 0; //source to source distance 0
	queue < pair <ll, ll> > q;
	q.push({sx, sy});
	while(!q.empty()) {
		ll vx = q.front().first, vy = q.front().second;
		q.pop();
		for(int i = 0; i < 8; i++) {
			ll u = vx + dirkx[i];
			ll v = vy + dirky[i];
			if(u >= 0 && u <= mx && v >= 0 && v <= my) {
				if(matrix[{u,v}] == 1 && vis[{u, v}] == 0) { //whether it is allowed or not (matrix) and visited/
					q.push({u, v});
					dis[{u, v}] = dis[{vx, vy}] + 1;
					vis[{u, v}] = 1;
				}
			}
		}
	}
}
 
int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	ll x1, y1;
	cin >> x1 >> y1 >> xx >> yy;
	ll T;
	cin >> T;
	ll r, x, y;
	while(T--) {
		cin >> r >> x >> y;
		mx = max(mx, r);
		for(ll i = x; i <= y; i++) {
			matrix[{r, i}] = 1; //to keep values in that row, column 
			my = max(my, i);
		}
	}
	BFS(x1, y1);
	if(dis[{xx, yy}] > 0)
		cout << dis[{xx, yy}] << endl;
	else 
		/*if(x1 == xx && y1 == yy)
			cout << 0 << endl;*/ //This is not needed as source and destination will not co incide
		cout << -1 << endl;
	
	return 0;
}
