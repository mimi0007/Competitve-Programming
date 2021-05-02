#include <bits/stdc++.h>

using namespace std;

//map <char, int> m; //1st item can call 2nd item, but 2nd item cannot call 1st item, storing character to the id
//map <int, char> m1; //now it stores id to the character too 
vector <int> adjlist[30]; 
int vis[30]; //we can do the whole solve with mostly in 26 characters (A-Z), So, 30 is the safe bound

void BFS(int s) {
	memset(vis, -1, sizeof(vis));
	queue <int> q;
	vis[s] = -2; // to detect the source we used something different like -2
	q.push(s);
	while(!q.empty()) {
		int top = q.front();
		q.pop();
		for(int i = 0; i < adjlist[top].size(); i++) {
			if(vis[adjlist[top][i]] == -1) {
				vis[adjlist[top][i]] = top; //top is stored in vis to detect the parent of the node in that specific index
				q.push(adjlist[top][i]);
			}
		}
	}
}


int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	int t;
	string a, b;
	cin >> t;
	for(int k = 1; k <= t; k++) {
		int m, n;
		cin >> m >> n;
		while(m--) {
			cin >> a >> b;
			int x = a[0]-'A', y = b[0]-'A'; // making those characters as integer/ascii values to work with that
			adjlist[x].push_back(y);
			adjlist[y].push_back(x);	
		}
		
		while(n--) {
		string a1, b1, path;
		cin >> a1 >> b1;
		BFS(a1[0]-'A');	//giving the source node's ascii value to the function 
		int i = b1[0]-'A';
		path.push_back(b1[0]); //this will not include as we're checking vis[this]
		while(vis[i] != -2) { //So we include it at first
			path.push_back(vis[i]+'A'); //using destination to source to have the parents, when vis[parent] = -2, iteration stops
			//printf("%c\n", vis[i]+'A'); //we are having the value/parent in reverse 
			i = vis[i]; // making that parent as the index to have it's parent
		}
		
		for(int i = path.size()-1; i>=0; i--)
			cout << path[i];
			
		cout << endl;
		}
		
		if(k < t) cout << "\n";
		
		for(int i = 0; i < 30; i++) adjlist[i].clear(); //must have to clear the 2D vector
	}
	return 0;
}

