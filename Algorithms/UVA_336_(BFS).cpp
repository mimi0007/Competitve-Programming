#include <bits/stdc++.h>

using namespace std;

map <long long int,int> m; //first item = real node, 2nd item = id
vector <int> adjlist[50]; //1st item can call 2nd item, but 2nd item cannot call 1st item
int vis[50]; //Creating a map, to store those node in a serial/id or assigning all the nodes in a unique id

void BFS(int s) {
	memset(vis, -1, sizeof(vis));
	vis[s] = 0;
	queue <int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < adjlist[u].size(); i++) {
			if(vis[adjlist[u][i]] == -1) {
				vis[adjlist[u][i]] = vis[u] + 1; //vis[u] means the parent of it
				q.push(adjlist[u][i]);
			} 
		}
	}
}

int main() {
	freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	int k = 1;
	while(1) {
		int n, c = 1; // keeping c = 1 to start id from 1
		cin >> n;
		if(n == 0) 
			break;	
		long long int a, b;
		for(int i = 1; i <= n; i++) {
			cin >> a >> b;
			if(m[a] == 0) {
				m[a] = c++; //if the map is empty then , we make a id for it using c++
			}
		
			if(m[b] == 0) {
				m[b] = c++; //So, if a node comes twice or further, the id will be unique and one!
			}
			int u = m[a], v = m[b]; //now we are assuming those nodes to our id, and working with it
			adjlist[u].push_back(v); //pushing the id! which will denote the node
			adjlist[v].push_back(u);
		}
		long long int t, x, y;
		while(1) {
			cin >> x >> y;
			if(x == 0 && y == 0) {
				break;
			}
			
			BFS(m[x]); // giving the node to the function as a id
			t = 0;
			for(int i = 1; i < c;i++) {
				if(vis[i] > y || vis[i] == -1) { //vis[i] == -1 is also going to checked to see whether there is any unvisited node
					t++; //unvisited node is also out of reach, thats why we have to cunt it too!
				}
			}
			
			cout <<"Case " << k++ << ": " << t << " nodes not reachable from node " << x <<  " with TTL = " << y << "." << endl;
		}
	
		for(int i = 0; i < c; i++) {
			adjlist[i].clear(); //clearing the adjlist for every test cases
		}
		
		m.clear(); //clearing the map
	
	}
	return 0;
}
