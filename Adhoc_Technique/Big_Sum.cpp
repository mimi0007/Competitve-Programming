#include <bits/stdc++.h>

using namespace std;

int main() {
	string a, b;
	vector <int> z;
	int sum = 0, c = 0;
	cin >> a >> b;
	while(!a.empty() && !b.empty()) {
		c += (a.back() - '0') + (b.back() - '0'); // + '0' makes a number to a character, - '0' makes a character to a number,
		sum = c % 10;
		z.push_back((sum + '0'));
		c /= 10;
		a.pop_back();
		b.pop_back();
	}
	
	while(!a.empty()) {
		c += (a.back() - '0');
		sum = c % 10;
		z.push_back((sum + '0'));
		c /= 10;
		a.pop_back();
	}
	
	while(!b.empty()) {
		c += (b.back() - '0');
		sum = c % 10;
		z.push_back((sum + '0'));
		c /= 10;
		b.pop_back();
	}
	
	if(c > 0) {
		z.push_back((c + '0'));
	}
	
	for(int i = z.size() - 1; i >= 0; i--)
		cout << (char)z[i];
		
	cout << endl;
	return 0;
}
