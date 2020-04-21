#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	map <char, int> m;
	m['N'] = 0;
	m['S'] = 2;
	m['L'] = 1;
	m['O'] = 3;
	int r, n, c;
	while(cin >> r >> c >> n) {
		if(r == 0 && c == 0 && n == 0) {
			break;
		}
		char s[r+3][c+3];
		string ss;
		int x , y, dir;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				cin >> s[i][j];
				if(s[i][j] == 'N' || s[i][j] == 'S' || s[i][j] == 'L' || s[i][j] == 'O') {
					x = i;
					y = j;
					dir = m[s[i][j]]; //to save the direction
					s[x][y] = '.'; //making it normal for further processes
				}
			}
		}
		cin >> ss;
		int dirx[4] = {-1, 0, 1, 0 }, diry[4] = {0, 1, 0, -1}, u, v, cc = 0;
		for(int i = 0; i < n; i++) {
			if(ss[i] == 'D') {
				dir++;
				dir %= 4;
			}
			
			else if( ss[i] == 'E') {
				dir--;
				if(dir < 0) {
					dir = 3; //important process
				}
			}
			
			else if(ss[i] == 'F') {
				u = x + dirx[dir];
				v = y + diry[dir];
				if((u >= 0 && v >= 0) && (u < r && v < c)) {
					if(s[u][v] == '*') {
						x = u; //updating value of position
						y = v;
						cc++;
						s[u][v] = '.'; //making it normal
					}
					
					else if(s[u][v] == '.') { //as it will update position when it is '.'
						x = u;
						y = v;
					}
				}
			}
		}
		cout << cc << endl;
	}
	return 0;
}

