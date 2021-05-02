#include <bits/stdc++.h>

using namespace std;

vector <int> adj[20005];
int n, vis[20005], cr, cb; //-1 = white/unvisited/uncolored, 0 = red, 1 = blue

int bicoloring(int x) {
	cr = 1, cb = 0; //cr = count of red = 1 because of source having red 
	vis[x] = 0;
	queue <int> q;
	q.push(x);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int i = 0; i < adj[v].size(); i++) {
			if(vis[adj[v][i]] == -1) {
				if(vis[v] == 0) {
					vis[adj[v][i]] = 1;
					cb++;
				}
				else {
					vis[adj[v][i]] = 0;
					cr++;
				}
				q.push(adj[v][i]);
			}
			
			/*if(vis[v] == vis[adj[v][i]]) //this portion is not used because we have to find the max
				return 0;*/    //not the fact that whether the graph is bicolorable or not 
		}
	}
	return max(cr, cb);
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		memset(vis, -1, sizeof(vis)); // memset in the function, cam make error to disconnected graphs and also occurs TLE for nodes like 10^5
		set <int> s; //set that will take unique values
		scanf("%d", &n);
		int a, b;
		while(n--) {
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
			s.insert(a);
			s.insert(b);
		}
		int m = 0;
		for(auto j: s) { //loop from set's first element to last element
			if(vis[j] == -1) //if it is unvisited/uncolored , if it occurs more than one, then there will be disjoint graphs 
				m += bicoloring(j); //to have the maximum value, one of the corner cases is:
		}
		/*1
		6
		1 1
		2 2
		3 3
		4 4
		5 5
		6 6*/
		cout << "Case " << i << ": " << m << endl;
		for(auto j: s) {
			adj[j].clear();
		}
	}
	return 0;
}















