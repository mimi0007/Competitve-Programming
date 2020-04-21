#include <bits/stdc++.h>

using namespace std;

double Bisection(double x, double y, double c) {
	double hi, lo, xx, yy, b;
	hi = x; // as the ladder can fall int the ground, so the highest ladder will be the hi value
	lo = 0.0;
	while(hi - lo > 0.0000001) {
		b = (hi + lo) / 2.00; // assuming 4 points, (0,0) , (b, 0) , (0,h1), (b, h2) and then making two equation of straight line
	    double h1 = sqrt((y*y - b*b)* 1.0), h2 = sqrt((x*x - b*b) * 1.0);
	    xx = (b*h1)/(h1+h2); // having x, y for the crossing point
	    yy = (h2 * xx) / b; //value of y = c
	    if(yy >= c) {
			lo = b;
		}
		
		else {
			hi = b;
		}
	}
	return b;
}

int main() {
	int T;
	double x, y, c, x1, y1;
	cin >> T;
	for(int i = 1; i <= T; i++) {
		cin >> x >> y >> c;
		x1 = max(x, y);
		y1 = min(x, y);
		cout << "Case " << i << ": " << setprecision(10) << fixed << Bisection(x1, y1, c) << endl;
	}
	return 0;
}
