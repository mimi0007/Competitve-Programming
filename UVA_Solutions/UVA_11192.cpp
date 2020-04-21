#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	int T, n;
	string s;
	while(cin >> T) {
		if(T == 0) {
			break;
		}
		cin >> s;
		n = s.size() / T;
		for(int i = 0; i < s.size(); i++) {
			//reverse(s.begin()+i,s.begin()+(i+n)); can be done instead of 2nd loop                      
			for(int j = i, k = (i+n) - 1; j <= ((2*i + n) - 1)/2; j++, k--) { //condition is the most important part here
				swap(s[j], s[k]);
			}
			i = (i + n) - 1;
		}
		
		cout << s << endl;
	}
	return 0;
}
