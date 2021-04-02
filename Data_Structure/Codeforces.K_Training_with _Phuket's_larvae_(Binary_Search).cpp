#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false);cin.tie(0);
#define pi acos(-1)
 
int main() {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	//fasterInOut;
 
	ll T;
	cin >> T;
	while (T--) {
		ll n;
		double mi, m;
		cin >> n;
		vector <double> v;
		for (int i = 0; i < n; i++) {
			cin >> m;
			v.push_back(m);
		}
 
		sort(v.begin(), v.end());
		mi = DBL_MAX; // mi for Max value in double datatype
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				ll hi = n-1, lo = j+1, mid;
				while(lo <= hi) {
					mid = (hi+lo)/2;
					if(v[i] + v[j] <= v[mid]) //to find for which one, triangle is not possible, then we'll check till that
						hi = mid-1;
							
					else {
						double k = (v[i] + v[j] + v[mid]) / 2.00;
						double area = sqrt(k * abs(k - v[i]) * abs(k - v[j]) * abs(k - v[mid]) * 1.0);
						mi = min(mi, area);
						lo = mid + 1;
					} 
				}
			}
		}
			
		if (mi == DBL_MAX)
			cout << -1 << endl;
		else
			cout << setprecision(10) << fixed << mi << endl;
	}
	return 0;
}
