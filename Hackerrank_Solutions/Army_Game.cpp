#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	if(m % 2 == 0 && n%2 == 0)
		cout << (m/2)*(n/2) << endl;
		
	else if(m%2 == 0 && n%2 != 0)
		cout << (m/2)*((n/2)+1) << endl;
		
	else if(m%2 != 0 && n%2 == 0)
		cout << ((m/2)+1)*(n/2) << endl;
		
	else 
		cout << ((m/2)+1)*((n/2)+1) << endl;
		
	return 0;
}

