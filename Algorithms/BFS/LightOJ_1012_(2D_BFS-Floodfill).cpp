#include <bits/stdc++.h>

using namespace std;

int vis[23][23], dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, 1, -1}, r, c, ma; //UDRL
string s[23];


void bfs(int x, int y) {
	ma = 1;
	memset(vis, -1, sizeof(vis));
	vis[x][y] = 0;
	queue <int> qx, qy;
	qx.push(x);
	qy.push(y);
	while(!qx.empty() && !qy.empty()) {
		int vx = qx.front(), vy = qy.front();
		qx.pop();
		qy.pop();
		for(int i = 0; i < 4; i++) {
			int u = vx + dirx[i], v = vy + diry[i];
			if((u >= 0 && v >= 0) && (u < r && v < c) && (s[u][v] != '#')) {
				if(vis[u][v] == -1) {
					qx.push(u);
					qy.push(v);
					vis[u][v] = vis[vx][vy] + 1;
					ma++;
				}
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int T;
	cin >> T;
	for(int k = 1; k <= T; k++) {
		int x, y;
		cin >> c >> r;
		for(int i = 0; i < r; i++) {
			cin >> s[i];
		}
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(s[i][j] == '@') {
					x = i;
					y = j;
					break;
				}
			}
		}
		bfs(x, y);
		cout << "Case " << k << ": " << ma << endl;
		for(int i = 0; i < r; i++) {
			s[i].clear();
		}
	}
	return 0;
}









