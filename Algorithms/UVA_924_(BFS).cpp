#include <bits/stdc++.h>

using namespace std;

vector <int> adj[2600];
int k;

void BFS(int s) {
	queue <int> Q;
	int vis[2700];
	memset(vis, -1, sizeof(vis)); 
	vis[s] = 0; //visited
	Q.push(s);
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < adj[v].size(); i++) {
			if(vis[adj[v][i]] == -1) {
				Q.push(adj[v][i]);
				vis[adj[v][i]] = vis[v] + 1;
			}
		}
	}
	int ma = 0,c, m = 0, d = 0;	
	for(int i = 0; i < k; i++) {
		if(vis[i] > ma)
			ma = vis[i];
	}
	
	for(int i = 1; i <= ma; i++) {
		c = 0;    
		for(int j = 0; j < k; j++) {
			if(vis[j] == i)
				c++;
		}
		if(c > m) {
			m = c;
			d = i;
		}
	}
	if(m > 0)
		cout << m << " " << d << endl;
	
	else
		cout << "0" << endl;
	
}

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r",stdin);
	int E;
	cin >> E;
	k = E;
	for(int i = 0; i < E; i++) {
	    int N, x;
	    cin >> N;
	    for(int j = 0; j < N; j++) {
			cin >> x;
			adj[i].push_back(x);
		}
	}
	int T;
	cin >> T;
	while(T--) {
		int S;
		cin >> S;
		BFS(S);
	}
	return 0;
}
