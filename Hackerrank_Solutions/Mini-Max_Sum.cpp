#include <bits/stdc++.h>

using namespace std;

int main() {
	long long int c, sum1 = 0, sum2 = 0;
	vector <long long int> v;
	for(int i = 0; i < 5; i++) {
		cin >> c;
		v.push_back(c);
	}
	
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		if(i > 0) {
			sum1+= v[i];
		}
		
		if(i < v.size()-1) {
			sum2 += v[i];
		}
	}
	
	if(sum1 > sum2)
		cout << sum2 << " " << sum1 << endl;
	else 
		cout << sum1 << " " << sum2 << endl;
	
	return 0;
}





