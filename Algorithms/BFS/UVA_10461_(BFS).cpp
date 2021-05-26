#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
#define MOD 1000000007

ll dirkx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dirky[] = {0, 0, 1, -1, -1, 1, -1, 1}; //kings move - U, D, R, L, LU, RU, LD, RD

ll b_vis[600], a_vis[600];
vector <ll> b_adjlist[600], a_adjlist[600];

//Source dependent to them
void b_BFS(ll s) {
	queue <ll> q;
	b_vis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		ll u = q.front();
		q.pop();
		for(int i = 0; i < b_adjlist[u].size(); i++) {
			if(b_vis[b_adjlist[u][i]] == -1) {
				b_vis[b_adjlist[u][i]] = b_vis[u] + 1;
				q.push(b_adjlist[u][i]);
			}
		}
	}
	 
}
//They dependent on source
void a_BFS(ll s) {
	queue <ll> q;
	a_vis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		ll u = q.front();
		q.pop();
		for(int i = 0; i < a_adjlist[u].size(); i++) {
			if(a_vis[a_adjlist[u][i]] == -1) {
				a_vis[a_adjlist[u][i]] = a_vis[u] + 1;
				q.push(a_adjlist[u][i]);
			}
		}
	} 
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/out", "w", stdout); for output in out file
	fasterInOut;
	ll v, e, cas = 1;
	while(cin >> v >> e) {
		ll sum = 0;
		if(v == 0 && e == 0)
			break;
		ll node[600];
		vector <ll> qr; 
		for(int i = 1; i <= v; i++) {
			cin >> node[i];
			sum += node[i];
		}
		ll a, b;
		while(e--) {
			cin >> a >> b;
			b_adjlist[a].push_back(b);
			a_adjlist[b].push_back(a);
		}
			
		ll T, x;
		cin >> T;
		
		while(T--) {
			cin >> x;
			qr.push_back(x);
		}
		cout << "Case #" << cas++ << ":" << endl;
		for(int i = 0; i < qr.size(); i++) {
			ll ma = sum, mi = 0;
			memset(a_vis, -1, sizeof(a_vis));
			memset(b_vis, -1, sizeof(b_vis));
			
			b_BFS(qr[i]);
			for(int j = 1; j < 505; j++) {
				if(b_vis[j] > 0) {
					mi += node[j];
				}
			} 
			a_BFS(qr[i]);
			for(int j = 1; j < 505; j++) {
				if(a_vis[j] != -1) {
					ma -= node[j];
				}
			}
			cout << ma-mi << endl;
		}
		for(int j = 0; j <= v; j++)
			a_adjlist[j].clear();
				
		for(int j = 0; j <= v; j++)
			b_adjlist[j].clear();
		cout << endl;
	}
	return 0;                            
}
