#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	//freopen("/home/mimi0007/Desktop/out.txt", "w", stdout);
	ll T, n, k, o = 1;
	while(1) {
		map <ll, ll> m; //to store map[given value] = group number of given value
	    queue <ll> q[1000]; //queue list to store values that are in those group numbers q[group number] = value1, value2, , , , ,
	    queue <ll> team; //for making queue's of all the queue list to serialize groups on their appearance 
		cin >> T;
		if(T == 0) {
			break;
		}
		ll vis[1007]; //to detect whether the group is visited once in team queue or not
		memset(vis, 0, sizeof(vis));
		ll x = 0;
		while(T--) {
			cin >> n;
			x++;
			for(int i = 0; i < n; i++) {
				cin >> k;
				m[k] = x;
			}
		}
		
		string s;
		ll d;
		cout << "Scenario #" << o++ << endl;
	    while(cin >> s) {
			if(s == "ENQUEUE") {
				cin >> d;
				q[m[d]].push(d);
				if(vis[m[d]] == 0) {
					vis[m[d]] = 1; //making it ntified that this group has been inserted in team queue
					team.push(m[d]); //insering the group number in team queue
				}
			}
			
			else if (s == "DEQUEUE") {				
				if(!q[team.front()].empty()) {
					cout << q[team.front()].front() << endl;
					q[team.front()].pop(); //2 : 201 1 : 102 103
				}
				
				//else means it only executes and sometimes checks one condition
				if(q[team.front()].empty()) { //to eradicate this two if used to check both two of them
					vis[team.front()] = 0; //it is a must to make it notified in vis array for further processing
					team.pop();
				}
			}
			
			else {
				cout << endl;
				break;
			}
		}
	}
	
	return 0;
}




