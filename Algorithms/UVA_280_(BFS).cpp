#include <bits/stdc++.h>

using namespace std;

vector <int> adj[105];
int vis[105], ma;

void BFS(int x) {
	ma = 0; 
	queue <int> q;
	q.push(x);
	while(!q.empty()) {
		int y = q.front();
		q.pop();
		for(int i = 0; i < adj[y].size(); i++) {
			if(vis[adj[y][i]] == -1) {
				q.push(adj[y][i]);
				vis[adj[y][i]] = vis[y] + 1;
				ma++;
			}
		}
	}
}

int main() {
	freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int T;
	while(cin >> T) {
		if(T==0)
			break;
		int n, m, x, y;
		vector <int> v;
		while(cin >> n) {
			if(n == 0)
				break;
			while(1) {
				cin >> m;
				if(m == 0) {
					break;
				}
				adj[n].push_back(m);
			}
		}
		cin >> x;
		for(int i = 0; i < x; i++) {
			cin >> y;
			v.push_back(y);
		}
		for(int i = 0; i < v.size(); i++) {
			m = 0;
			memset(vis, -1, sizeof(vis));
			BFS(v[i]);
			cout << T-ma;
			for(int j = 1; j <= T; j++) {
				if(vis[j] == -1) {
					cout << " " << j;
				}
			}
			cout << endl;
		}
		
		for(int i = 1; i <= T; i++) {
			adj[i].clear();
		}
	}
	return 0;
}

















