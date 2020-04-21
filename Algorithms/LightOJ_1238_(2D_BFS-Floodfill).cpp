#include <bits/stdc++.h>

using namespace std;

int r, c, vis[25][25], dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, 1, -1}; //U D R L
string s[25]; //10^5 strings cannot be declared at a time, if it does, there can be a buffer which makes Runtime Error

void bfs(int x, int y) {
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
			if((u >= 0 && v >= 0) && (u < r && v < c) && (s[u][v] != '#') && (s[u][v] != 'm')) {
				if(vis[u][v] == -1) {
					qx.push(u);
					qy.push(v);
					vis[u][v] = vis[vx][vy] + 1;
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
		cin >> r >> c;
		for(int i = 0; i < r; i++) {
			cin >> s[i];
		}
		int ax, ay, bx, by, cx, cy, hx, hy;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(s[i][j] == 'a') {
					ax = i;
					ay = j;
				}
				
				else if(s[i][j] == 'b') {
					bx = i;
					by = j;
				}
				
				else if(s[i][j] == 'c') {
					cx = i;
					cy = j;
				}
				
				else if(s[i][j] == 'h') {
					hx = i;
					hy = j;
				}
			}
		}
		bfs(hx, hy);
		cout << "Case " << k << ": " << max(max(vis[ax][ay], vis[bx][by]), vis[cx][cy]) << endl;
		for(int i = 0; i < r; i++) {
			s[i].clear();
		}
	}
	return 0;
}







