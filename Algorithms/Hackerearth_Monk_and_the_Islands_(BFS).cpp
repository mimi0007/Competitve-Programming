#include <bits/stdc++.h>

using namespace std;

vector<int> adjlist[100009];
int vis[100009];

void BFS(int s) {
	memset(vis, -1, sizeof(vis));
	queue <int> q;
	vis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		for(int i = 0; i < adjlist[top].size(); i++) {
			if(vis[adjlist[top][i]] == -1) {
				vis[adjlist[top][i]] = vis[top] + 1;
				q.push(adjlist[top][i]);
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		while(m--) {
			int x, y;
			cin >> x >> y;
			adjlist[x].push_back(y);
			adjlist[y].push_back(x);
		}
		BFS(1);
		cout << vis[n] << endl;	
		for(int i = 0; i < n; i++) adjlist[i].clear();
	}
	return 0;
}

