#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)

int r, c, fire_vis[1005][1005], dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, 1, -1}, source_vis[1005][1005];
vector <pair <ll, ll> > vv;
string s[1006];


void multiple_source_bfs() {
	memset(fire_vis, -1, sizeof(fire_vis));
	queue <int> qx, qy;
	for(auto i: vv) { //pushing all the multiple sources into the queue;
		fire_vis[i.first][i.second] = 0; //making all the sources vis = 0
		qx.push(i.first);
		qy.push(i.second);
	}
	while(!qx.empty() && !qy.empty()) {
		int vx = qx.front(), vy = qy.front();
		qx.pop(); 
		qy.pop();
		for(int i = 0; i < 4; i++) { //for identifying all the adjacent cells
			int u = vx + dirx[i];
			int v = vy + diry[i];
			if((u >= 0 && v >= 0) && (u < r && v < c)) { //checking whether they are in between the range
				if(s[u][v] != '#') { //whether the cell is a wall
					if(fire_vis[u][v] == -1 || (fire_vis[vx][vy] + 1 < fire_vis[u][v])) { //relazxation
						qx.push(u); //if it's visited then it'll check whether there can be a minimum path for any source by source+1 < previous
						qy.push(v); //As it is adjacent to that definite source, so, source+1
						fire_vis[u][v] = fire_vis[vx][vy] + 1; //distance from the source
					}
				}
			}
		}
	}
}

void bfs(int sx, int sy) { //it is for the man as a source 
	memset(source_vis, -1, sizeof(source_vis));
	source_vis[sx][sy] = 0;
	queue <int> qx, qy;
	qx.push(sx);
	qy.push(sy);
	while(!qx.empty() && !qy.empty()) {
		int vx = qx.front(), vy = qy.front();
		qx.pop(); 
		qy.pop();
		for(int i = 0; i < 4; i++) {
			int u = vx + dirx[i];
			int v = vy + diry[i];
			if((u >= 0 && v >= 0) && (u < r && v < c)) {
				if(s[u][v] != '#') {
					if(source_vis[u][v] == -1) { //here we have to check the condition if they are in the same cell at the same time
						if(fire_vis[u][v] == -1 || (fire_vis[u][v] > source_vis[vx][vy]+1)) { //if fire didn't reach out there then okay
							qx.push(u); // and, if fire reached out there, then it should be of greater path then from the source
							qy.push(v); //that is, the source path should be less as it should go faster
							source_vis[u][v] = source_vis[vx][vy] + 1;
						}
					}
				}
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int T;
	cin >> T;
	while(T--) {
		cin >> r >> c;
		for(int i = 0; i < r; i++) {
			cin >> s[i];
		}
		ll sr, sc, dr, dc;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(s[i][j] == 'S') {
					sr = i;
					sc = j;
				}
				
				else if(s[i][j] == 'E') {
					dr = i;
					dc = j;
				}
				
				else if(s[i][j] == 'F') {
					vv.push_back({i, j});
				}
			}
		}
		multiple_source_bfs();
		bfs(sr, sc);
		ll ff = source_vis[dr][dc]; //if source cannot reach there
		if(ff == -1)
			cout << "N\n";
		else 
			cout << "Y\n";
		vv.clear();
	}
	return 0;
}
