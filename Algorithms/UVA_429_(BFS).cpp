#include <bits/stdc++.h>

using namespace std;

vector <int> adj[205];
int vis[205];

void BFS(int x) {
	vis[x] = 0;
	queue < int> q;
	q.push(x);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int i = 0; i < adj[v].size(); i++) {
			if(vis[adj[v][i]] == -1) {
				vis[adj[v][i]] = vis[v] + 1;
				q.push(adj[v][i]);
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int T;
	cin >> T; //creates an "enter" for cin >> T, if we use cin >> s for string this will not consider the "junk" or "enter"
	int t = T, xx = 0;
	map <string, int> m;
	string junk;
	getline(cin, junk);
	while(T--) {
		xx++;
		string s[205];
		for(int i = 0, j = 1; i <= 202; i++) {
			getline(cin, s[i]);
			if(s[i][0] == '*') {
				break;
			}
			m[s[i]] = j++; //creating id for individual strings
		}
		//making the graph by checking all the words for each one ....
		for(int j = 0; j < m.size(); j++) {
			for(int i = 1; i <= m.size(); i++) {
				int c = 0;
				if(s[j].size() == s[i].size()) { //if the size is same
					for(int k = 0; k < s[j].size(); k++) {
					if(s[i][k] != s[j][k]) {
							c++;
						}
					}
				} 
				if(c == 1) { //there is only one alphabet difference, so we can visit from that one word to another bidirectionally for this 1 alphabet difference
					adj[m[s[j]]].push_back(m[s[i]]);
					adj[m[s[i]]].push_back(m[s[j]]);
				}	
			}
		}		
			
		string ss, s1, s2;
		while(getline(cin, ss)) { // if we use cin, it will not take the nweline/junk 
			if(ss == "") {
				break; //breaks the loop and takes to the new case
			}
			int y = ss.size() - 1;
			for(int i = 0 ; i < y/2; i++) {
				s1.push_back(ss[i]);
			}
			//having those two words as source and destination
			for(int i = (y/2)+1; i < ss.size(); i++) {
				s2.push_back(ss[i]);
			}
			memset(vis, -1, sizeof(vis));
			//it is a must to reform the vis array for each execution to the algorithm-function 
			BFS(m[s1]);
			cout << s1 << " " << s2 << " " << vis[m[s2]] << endl;
			s1.clear();
			s2.clear();
			//clearing those source, and destination
		}
		for(int i = 1; i <= 203; i++) {
			adj[i].clear();
		}
		m.clear();
		if(t>xx) {
			cout << endl; //as several testacases will contain a blank line between them
		}
	}
	return 0;
}














