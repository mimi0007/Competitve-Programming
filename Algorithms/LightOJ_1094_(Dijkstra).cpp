#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

vector <pii> adjlist[30005];
int dis[30005], node, n;

void clr() {
	for(int i = 0; i < n; i ++) {
		dis[i] = INT_MAX;
	}
}

void dijkstra(int x) {
	priority_queue < pii, vector <pii>, greater<pii> > pq;
	pq.push({0, x});
	dis[x] = 0;
	while(!pq.empty()) {
		int u = pq.top().second;
		node = u; //the last element of the queue is the last node/farthest node
		pq.pop();
		for(int i = 0; i < adjlist[u].size(); i++) {
			int w = adjlist[u][i].first;
			int v = adjlist[u][i].second;
			if(dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int T, a , b, c;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++) {
		scanf("%d", &n);
		for(int j = 1; j < n; j++) {
			scanf("%d %d %d", &a, &b, &c);
			adjlist[a].push_back({c, b});
			adjlist[b].push_back({c, a});
		}
		clr();
		dijkstra(0); //from source 0 to have the farthest node of this tree
		clr(); //clearing the whole dis for new values
		dijkstra(node); //now the farthest node will be counted from the very last node to have the actual answer
		cout << "Case " << k << ": " << dis[node]<< endl;
		for(int i = 0; i < n; i++) {
			adjlist[i].clear();
		}
	}
	return 0;
}














