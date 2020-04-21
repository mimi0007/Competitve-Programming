#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int H, A, c = 0;
		cin >> H >> A;
		while(H > 0 && A > 0) {
			H = H + 3;
			A = A + 2;
			c++;
			if( H-5 > 0 && A-10 > 0) {
				H = H - 5;
				A = A - 10;
				c++;
			}
			
			else if (H - 20 > 0) {
				H = H - 20;
				A = A + 5;	
				c++;
			}
			
			else {
				break;
			}
		}
		
		cout << c << endl;
	}
	
	return 0;
}
