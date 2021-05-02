#include <bits/stdc++.h>

using namespace std;

map <string, int> m;
map <int, string> mm;
vector <int> adj[100005];
int vis[100005];

void clr() {
	m.clear();
	mm.clear();
	for(int j = 1; j < 100000; j++) 
		adj[j].clear();
}

void bfs(int x) {
	memset(vis, -1, sizeof(vis));
	queue <int> q;
	vis[x] = -2; // making the source differnet for parent finding purpose
	q.push(x);
	while(!q.empty()) {
		int y = q.front();
		q.pop();
		for(int i = 0; i < adj[y].size(); i++) {
			if(vis[adj[y][i]] == -1) {
				q.push(adj[y][i]);
				vis[adj[y][i]] = y;
			}
		}
	}
	
}

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	int T, F = 0; // A flag for printing endline after first test case
	while(1) {
		cin >> T;
		if(T == EOF)//will run till EOF
			break;
		if(F) // this will execute for values any values except 0 or greater than 0
			cout << endl;
		F = 1; //to print endline from the beginning of the 2nd test case
		int i = 1;
		string s1, s2, ss, dd;
		while(T--) {
			cin >> s1 >> s2;
			if(m[s1] == 0) {
				mm[i] = s1; // id to string
				m[s1] = i++; //string to id
			}
			if(m[s2] == 0) {
				mm[i] = s2;
				m[s2] = i++;
			}
			adj[m[s1]].push_back(m[s2]);
			adj[m[s2]].push_back(m[s1]); //as it is a bidirectional graph
		}
		cin >> ss >> dd;
		if(!m[ss] || !m[dd]) { //it is the important part to check whether those given source and destination still exists into the nodes
			cout << "No route\n";
			clr();
			continue; //if it happens , it willl no longer work in further processes
		}
		bfs(m[ss]);
		int k = m[dd];
		vector <int> path;
		path.push_back(k);
		bool f = 0;
		while(vis[k] != -2) { //checking parents of nodes till the source
			path.push_back(vis[k]);
			if(vis[k] == -1) { //if it can't reach the source than there is no route
				f = 1;
				break;
			}
			k = vis[k];
		}
		if(f == 1) {
			cout << "No route\n";
		}
		
		else {
			for(int jj = path.size()-1; jj > 0; jj--) {
				cout << mm[path[jj]] << " " << mm[path[jj-1]] << endl;
			}
		}
		clr(); //clearing all the containers
	}
	return 0;
}












