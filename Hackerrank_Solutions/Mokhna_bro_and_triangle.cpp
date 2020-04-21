//problem link: https://www.hackerrank.com/contests/lets-do-2/challenges/mokhna-bro-and-triangle
#include <bits/stdc++.h>

#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main() {
	fasterInOut;
	//freopen("in.txt", "r", stdin);
		double A, B, C, S, r;
		cin >> A >> B >> C;
		S = (A + B + C) / 2.00;
		A = sqrt(S * (S-A) * (S-B) * (S-C));
		r = A / S;
		cout << setprecision(5) << fixed << 2.00 * 3.14159 * r << endl; // to fix 5 digits after decimel point
	return 0;
}

