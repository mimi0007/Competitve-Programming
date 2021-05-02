#include <bits/stdc++.h>

using namespace std;

int r, c, adj[1005][1005], vis[1005][1005], dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, 1, -1};

void bfs(int sx, int sy) {
	memset(vis, -1, sizeof(vis));
	vis[sx][sy] = 0;
	queue <int> qx, qy;
	qx.push(sx);
	qy.push(sy);
	while(!qx.empty() && !qy.empty()) {
		int vx = qx.front(), vy = qy.front();
		qx.pop(); 
		qy.pop();
		for(int i = 0; i < 4; i++) { //for identifying all the adjacent cells
			int u = vx + dirx[i];
			int v = vy + diry[i];
			if((u >= 0 && v >= 0) && (u < r && v < c) && (adj[u][v] != 1)) {
				if(vis[u][v] == -1) {
					qx.push(u);
					qy.push(v);
					vis[u][v] = vis[vx][vy] + 1; //distance from the source
				}
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int ins, m, q, r1, sr, sc, dr, dc;
	while(cin >> r >> c) {
		if(r == 0 && c == 0)
			break;
		cin >> ins;
		memset(adj, 0, sizeof(adj)); //to take more values
		while(ins--) {
			cin >> r1 >> q;
			while(q--) {
				cin >> m;
				adj[r1][m] = 1;
			}
		}
		cin >> sr >> sc;
		cin >> dr >> dc;
		bfs(sr, sc);
		cout << vis[dr][dc] << endl;
	}
	return 0;
}







