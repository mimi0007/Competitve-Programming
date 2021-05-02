#include <bits/stdc++.h>

using namespace std;

#define pii pair <int, int>
vector <pii> adj[30005];
long long int vis[30005], node;
//int weight[30005][30005]; //this is not possible as array can take atmost 10^7 values in total

void BFS(int x) {
	priority_queue <pii, vector <pii>, greater <pii> > pq; //minimum priority queue
	pq.push({0, x}); //weight, node
	vis[x] = 0;
	while(!pq.empty()) {
		int y = pq.top().second;
		node = y; //storing the farthest node for a source in node
		pq.pop();
		for(int i = 0; i < adj[y].size(); i++) {
			if(vis[adj[y][i].second] == -1) {
				vis[adj[y][i].second] = vis[y] + adj[y][i].first; // vis[node] = vis[parent] + weight of node from parent
				pq.push({vis[adj[y][i].second], adj[y][i].second}); // new value of vis[node], node
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int n, a, b, c, t;
	scanf("%d", &n);
	for(int k = 1; k <= n; k++) {
		scanf("%d", &t);
		for(int m = 1; m < t; m++) {
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back({c, b});
			adj[b].push_back({c, a});
		}
		memset(vis, -1, sizeof(vis));
		BFS(0);
		memset(vis, -1, sizeof(vis)); //preparing the array 2nd time for new source!
		BFS(node);
		cout << "Case " << k << ": " << vis[node] << endl;
		for(int i = 0; i < t; i++) 
			adj[i].clear();
	}
	return 0;
}















