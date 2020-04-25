#include <bits/stdc++.h>

using namespace std;

vector <int> adj[1000];
int vis[1000];

void BFS(int x) {
	queue <int> q;
	vis[x] = 0;
	q.push(x);
	while(!q.empty()) {
		int y = q.front();
		q.pop();
		for(int i = 0; i < adj[y].size(); i++) {
			if(vis[adj[y][i]] == -1) {
				q.push(adj[y][i]);
				vis[adj[y][i]] = vis[y] + 1;
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int T, N, M, P;
	cin >> T;
	cout << "SHIPPING ROUTES OUTPUT\n\n";
	for(int i = 1; i <= T; i++) { 
		cout << "DATA SET  " << i << "\n\n";
		cin >> M >> N >> P;
		string s;
		map <string, int> m;
		for(int j = 1; j <= M; j++) {
			cin >> s;
			m[s] = j;
		}
		string a, b;
		while(N--) {
			cin >> a >> b;
			adj[m[a]].push_back(m[b]);
			adj[m[b]].push_back(m[a]);
		}
		int X;
		string x, y;
		while(P--) {
			cin >> X;
			cin >> x >> y;
			memset(vis, -1, sizeof(vis));
			BFS(m[x]);
			if(vis[m[y]] == -1) {
				cout << "NO SHIPMENT POSSIBLE" << endl;
			}
			else {
				cout << "$" << X*vis[m[y]]*100 << endl;
			}
		}
		cout << endl;
		for(int k = 1; k <= M; k++) {
			adj[k].clear();
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

















