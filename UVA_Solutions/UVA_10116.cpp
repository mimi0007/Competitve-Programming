#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int a, b, n;
	while(cin >> a >> b >> n) {
		if(a == 0 && b == 0 && n == 0) {
			break;
		}
		
		string s[a+2]; 
		map <char, int> m; //map for assigning the values of the directions
		
		m['N'] = 0;
		m['S'] = 1;
		m['E'] = 2;
		m['W'] = 3;
		
		for(int i = 0; i < a; i++) {
			cin >> s[i];
		}
		
		int dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, 1, -1}; // direction arrays
		int x = 0, y = n-1, k = 2, tt = 0, ss = 0, vis[a+2][b+2], f = 0; //k = 2, as we are cunting the first step, and working from the 2nd step
		memset(vis, 0, sizeof(vis));
		vis[x][y] = 1; 
		ss = 1; //when there will be only one element
		while(1) {
			int u = x + dirx[m[s[x][y]]], v = y + diry[m[s[x][y]]]; //new x and y
			if((u < a && v < b) && (u >= 0 && v >= 0)) { //to assure that x , y is not out of the bound
				x = u;
				y = v;
				if(vis[x][y] > 0) { //everyone will be 0 at first, so, after that, if any direction appears it will come into this oop
					f = 1; //for breaking
					tt = vis[x][y]; //starting/ending directions value of the loop
				}
				
				else {
					vis[x][y] += k++; // 1, 2, 3, 4, incrementing k after keeping the value
					ss = vis[x][y];
				}
			}
			
			else {
				f = 1;
			}
			
			if(f ==1) 
				break;
		}
		
		if(tt == 0) {
			cout << ss << " step(s) to exit"<< endl;
		}
		
		else {
			cout << tt-1 << " step(s) before a loop of " << abs(ss - tt)+ 1 << " step(s)" << endl;
		}
		
		for(int i = 0; i < a; i++) {
			s[i].clear();
		}
		
	}
	
	return 0;
}
