#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	string s;
	while(cin >> s) {
		vector <int> v;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == 'B' || s[i] == 'F' || s[i] == 'P' || s[i] == 'V') {
				v.push_back(1);
			}
			
			else if (s[i] == 'C' || s[i] == 'G' || s[i] == 'X' || s[i] == 'Z' || s[i] == 'J' || s[i] == 'K' || s[i] == 'Q' || s[i] == 'S') {
				v.push_back(2);
			}
			
			else if(s[i] == 'D' || s[i] == 'T') {
				v.push_back(3);
			}
			
			else if(s[i] == 'L') {
				v.push_back(4);
			}
			
			else if(s[i] == 'M' || s[i] == 'N') {
				v.push_back(5);
			}
			
			else if (s[i] == 'R') {
				v.push_back(6);
			}
			
			else {
				v.push_back(0);
			}
		}
		if(v[0] != 0) 
			cout << v[0];
		for(int i = 1; i < v.size(); i++) {
			if(v[i] == v[i-1]) {
				continue;
			}
			
			else {
				if(v[i] != 0) 
					cout << v[i];
			}
		}
		cout << endl;
		v.clear();
	}
	return 0;
}


















