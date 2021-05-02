#include <bits/stdc++.h>

using namespace std;

int dx, dy, sx, sy, vis[10][10], dirx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, diry[8] = {1, 2, 2, 1, -1, -2, -2, -1}; // Clockwise Counting with direction

void bfs(int r, int c) {
	memset(vis, -1, sizeof(vis));
	vis[r][c] = 0;
	queue <int> qr, qc;
	qr.push(r);
	qc.push(c);
	while(!qr.empty() && !qc.empty()) {
		int rx = qr.front(), cx = qc.front();
		qr.pop();
		qc.pop();
		for(int i = 0; i < 8 ; i++) {
			int u = rx + dirx[i], v = cx + diry[i];
			if((u >= 1 && v >= 1) && (u <= 8 && v <= 8)) { //from 1,1 to 8,8
				if(vis[u][v] == -1) {
					qr.push(u);
					qc.push(v);
					vis[u][v] = vis[rx][cx] + 1;
				}
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	string s1, s2;
	while(cin >> s1 >> s2) {    
		sx = s1[1] - '0';
		dx = s2[1] - '0';
		sy = (s1[0] - 'a') + 1;
		dy = (s2[0] - 'a') + 1;
		bfs(sx, sy);
		cout << "To get from " << s1 << " to " << s2 << " takes " << vis[dx][dy] <<" knight moves.\n";
		s1.clear();
		s2.clear();
	}
	return 0;
}











