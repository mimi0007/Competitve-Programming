#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++) {
		long double r, a , b, t, a1, b1, pmeter;
		char c;
		cin >> a >> c >> b;
		r = (sqrt((a*a + b*b)*1.)) / 2.0; 
		t = acos(((r*r + r*r) - b*b)/(2.00 * r * r)); //calculated the circumferrance for (assuming x = 1) ratio (ax:bx)  1
		pmeter = 400.00 / ((2.00 * r * t) + (2.00 * a)); //then divided 400 by the found circumferrance to have the actual value of x
		a1 = a * pmeter;
		b1 = b * pmeter;
		cout << setprecision(10) << fixed; // without fixed, .999 will be 1.000, with fixed, .999 will be .999 (fixed for actual value)
		cout << "Case " << i << ": " << a1 << " " << b1 << endl;
	} 
	return 0;
}











