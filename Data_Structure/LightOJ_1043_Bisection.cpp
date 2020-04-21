#include <bits/stdc++.h>

using namespace std;

double rtio;
double ab, ac, bc, a, abc;

double bisection(double x) {
	double hi = x, lo = 0.0; //this is generally the way to make an assumption on AD to have the correct value for which the r1 will be same as rtio
	double e, ade, ae, de, r1, mid; //initially, mid = ad
	while(hi - lo > 0.000001) {
		mid = (hi + lo)/ 2.00; 
		ae = (mid*ac)/ab; //AD/AB = AE/AC = DE/BC
		de = (mid*bc)/ab; //binary search is the approach having complexity: log(n)
		e = (mid + ae + de) / 2.00;
		ade = sqrt(e*(e-mid)*(e-ae)*(e-de)*1.0);
		r1 = ade/(abc-ade);
		if(r1 >= rtio) {
			hi = mid; //should not break while find r1==rtio because it will give an error/incorrect value in double datatype
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
		cin >> ab >> ac >> bc >> rtio;
		a = (ab+ac+bc)/2.00;
		abc = sqrt(a*(a-ab)*(a-ac)*(a-bc)*1.0);
		cout << "Case "<< i << ": " << setprecision(10) << fixed << bisection(ab) << endl; //fixed is used to ignore precision bug
	}
	return 0;
