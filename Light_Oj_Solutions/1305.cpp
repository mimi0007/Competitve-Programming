#include <bits/stdc++.h>

using namespace std;

int main() {
	int T, ax, ay, bx, by, cx, cy, dx, dy, A;
	cin >> T;
	for(int i = 1; i <= T; i++) {
		cin >> ax >> ay >> bx >> by >> cx >> cy;
		dx = (ax - bx) + cx;
		dy = (cy - by) + ay;
		A = ((ax*by + bx*cy + cx*dy + dx*ay) - (ay*bx + by*cx + cy*dx + dy*ax)) / 2; //abs(A) = 1/2 * |ax bx cx dx ax|
		                                                                                           // |ay by cy dy ay|
		cout << "Case " << i << ": " << dx << " " << dy << " " << abs(A) << endl;
	}
	return 0;
}
