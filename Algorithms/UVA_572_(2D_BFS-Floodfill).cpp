#include <bits/stdc++.h>

using namespace std;

int vis[105][105], dirx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, diry[8] = {0, 0, 1, -1, -1, 1, -1, 1 }, r, c; //U D L R UR UL DR DL as it also diagonal cells
string s[105];

void BFS(int x, int y) {
	memset(vis, -1, sizeof(vis));
	vis[x][y] = 0;
	queue <int> qx, qy;
	qx.push(x);
	qy.push(y);
	while(!qx.empty() && !qy.empty()) {
		int vx = qx.front(), vy = qy.front();
		s[vx][vy] = '*';
		qx.pop();
		qy.pop();
		for(int i = 0; i < 8; i++) {
			int u = vx + dirx[i], v = vy + diry[i];
			if((u >= 0 && v >= 0) && (u < r && v < c) && s[u][v] != '*') {
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
	while(cin >> r >> c) {
		if(r == 0) 
			break;
		for(int i = 0; i < r; i++) {
			cin >> s[i];
		}
		int cc = 0;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(s[i][j] == '@') {
					BFS(i, j);
					cc++;
				}
			}
		}
		cout << cc << endl;
		for(int i = 0; i < r; i++) {
			s[i].clear();
		}
	}
	return 0;
}







