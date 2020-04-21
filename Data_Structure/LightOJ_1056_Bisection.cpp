#include <bits/stdc++.h>

using namespace std;

double bisection(double x, double y) {
	double hi = 400.00, lo = 0.0, mid, v, l, w, kon, s;
	while(hi-lo > 0.000000000001) { // this range should be increased to get the perfect value
		 mid = (hi+lo)/2.00;
		 l = mid * x;
		 w = mid * y;
		 v = (sqrt((l*l + w*w)*1.)) / 2.00;
		 kon = acos(((2.00 * v * v) - (w * w)) / (2.00 * v * v));
		 s = v * kon * 2.00;
		 if((s + (2.00*l)) > 400.000) {
			 hi = mid;
		 }
		 
		 else {
			 lo = mid;
		 }
	}
	return mid;
}

int main() {
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++) {
		double a , b, pmeter;
		char c;
		cin >> a >> c >> b;
		pmeter = bisection(a, b);
		cout << setprecision(10) << fixed; // without fixed, .999 will be 1.000, with fixed, .999 will be .999 (fixed for actual value)
		cout << "Case " << i << ": " << a*pmeter << " " << b*pmeter << endl;
	} 
	return 0;
}








