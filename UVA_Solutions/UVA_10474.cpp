#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
    int N, Q, m, k;
    vector <int> v;
    int j = 1;
    while(cin >> N >> Q) {
		if(N == 0 && Q == 0) {
			break;
		}
		for(int i = 0; i < N; i++) {
			cin >> m;
			v.push_back(m);
		}
		sort(v.begin(), v.end());
		cout << "CASE# " << j << ":\n";
		while(Q--) {
			cin >> k;
			int f = 0;
			for(int i = 0; i < v.size();i++) {
				if(v[i] == k) {
					cout << k << " found at " << i+1 << endl;
					f = 1;
					break;
				}
			}
			if(f != 1) 
			cout << k << " not found\n";
		}
		v.clear();
		j++;
	}
	return 0;
}
