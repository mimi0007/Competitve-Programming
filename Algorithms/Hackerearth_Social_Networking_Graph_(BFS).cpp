#include <bits/stdc++.h>

using namespace std;


int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	int n, e, x;
	cin >> n >> e;
	vector <int> adjlist[n+5]; //as there is no constraint for x
	int a, b;
	while(e--) {
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	cin >> x;
	int m, n1;
	while(x--) {
		int vis[n+5];
		memset(vis, -1, sizeof(vis)); 
		int c = 0;
		cin >> m >> n1;
		queue <int> q;
		q.push(m);
		vis[m] = 0;
		while(!q.empty()) {
			int top = q.front();
			q.pop();
			for(int i = 0; i < adjlist[top].size(); i++) {
				if(vis[adjlist[top][i]] == -1) {
					vis[adjlist[top][i]] = vis[top] + 1;
					if(vis[adjlist[top][i]] == n1) c++;
					q.push(adjlist[top][i]);
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}

