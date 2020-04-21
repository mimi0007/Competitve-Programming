#include <bits/stdc++.h>

using namespace std;

#define ll long long int

vector < pair < ll, int> > adj[100005]; //pair is a customized datatype here for this adj vector
ll dis[100005], vv[100005], f, n, m;

void dijkstra(int x) {
	f = 0;
	priority_queue < pair <ll, int>, vector <pair < ll, int> >, greater <pair <ll, int> > > pq; //min priority queue that prioritize from min to max 
	pq.push({0, x}); //pushing the source node second, weight first as pair into the priority queue
	dis[x] = 0;
	vv[x] = -1; //to identify the end
	while(!pq.empty()) {
		int u = pq.top().second; //queue - front, Priority Queue - top, top first index , second index is the node
		pq.pop();
		if(u == 1) return; //u = 1 means it comes to the end, no need to make further process(this will make TLE),as it dijkstra is a void function
		for(int i = 0; i < adj[u].size(); i++) {
			int w = adj[u][i].first; //weight of v node from u node
			int v = adj[u][i].second; //child node of u parent node
			if(dis[u] + w < dis[v]) {
				vv[v] = u; //vv[parent] = child, vv[child] = parent is not possible, cause a parent can have many childs
				dis[v] = dis[u] + w;
				pq.push({dis[v], v}); //pushing as a pair in node second, new weight first index
			}
		}
	}
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int a , b;
	ll w;
	cin >> n >> m;
	while(m--) {
		cin >> a >> b >> w; //as it is undirected/bidirectional
		adj[a].push_back({w, b}); //pair wise pushing first weight/cost, second node
		adj[b].push_back({w, a}); // as we will min priority queue prioritizes by first index
	}
	for(int i = 1; i <= n; i++) {
		vv[i] = -1;
		dis[i] = LONG_LONG_MAX; //cause summation of all big weights can beat INT_MAX
	}
	dijkstra(n); //destination became source ------ source became destination
	int y = 1;
	if(vv[1] != -1) { //if vv[1] == 0, that means it cannot reach the end or there is no shortest path
		cout << 1;
		while(vv[y] != -1) {
			cout << " " << vv[y];
			if(vv[y] == n) //if it reaches to the end, no need to print more
				break;
			y = vv[y];
		}
		
	}
	
	else 
		cout << "-1" << endl;
	cout << endl;
	for(ll i = 1; i <= n; i++) {
		adj[i].clear();
	}
	return 0;
}

/*
1-----4
source------destination
dir[v] = u; child, parent
dir[2] = 1
dir[3] = 2
dir[4] = 3
4 3 2 1


--------------
4-----1
destination-----source
dir[3] = 4 parent, child
dir[2] = 3
dir[1] = 2
1 2 3 4
*/













