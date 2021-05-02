#include <bits/stdc++.h>

using namespace std;

vector <int> adj[25];
int vis[25];

void bfs(int x) {
	memset(vis, -1, sizeof(vis));
	vis[x] = 0;
	queue <int> q;
	q.push(x);
	while(!q.empty()) {
		int y = q.front();
		q.pop();
		for(int i = 0; i < adj[y].size(); i++) {
			if(vis[adj[y][i]] == -1) {
				q.push(adj[y][i]);
				vis[adj[y][i]] = vis[y] + 1;
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int k = 1;
	while(1) {
		int x, mm;
		for(int i = 1; i <= 19; i++) {
			cin >> x;
			if(x == EOF)
				return 0; // this will terminate the whole program
			while(x--) {
			cin >> mm;
			adj[i].push_back(mm);  
			adj[mm].push_back(i); //as it is a bidirectional graph
			}
		}
		int N, a[105], b[105];
		cin >> N;
		for(int i = 0; i < N; i++) {
			cin >> a[i] >> b[i];
		}
		cout << "Test Set #" << k++ << endl;
		for(int i = 0; i < N; i++) {
			bfs(a[i]); //for shortest path
			cout << setw(2) << right << a[i] << " to " << setw(2) << right << b[i] << ": " << abs(vis[b[i]] - vis[a[i]]) << endl;
			//this "setw(2) << right" will set the output in this same form:
			// 1 to 20: 7
			// 2 to  9: 5
			//19 to  5: 6
			//18 to 19: 2
		}
		for(int i = 1; i <= 20; i++) { //as because from 1 to 19 , 20 can be in adj list
			adj[i].clear();
		}
		cout << endl;
	}
	return 0;
}










