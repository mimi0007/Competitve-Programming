#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int
#define fasterInOut ios::sync_with_stdio(false); cin.tie(0);
#define pi acos(-1)
 
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	fasterInOut;
	int n;
	cin >> n;
	int ar[n+2][n+2];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> ar[i][j];
		}
	}
	//2D cumutaive sum 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i > 0) 
				ar[i][j] += ar[i-1][j];
			if(j > 0) 
				ar[i][j] += ar[i][j-1];
			if(i > 0 && j > 0) 
				ar[i][j] -= ar[i-1][j-1]; //As we are summing same value twice, that's why it needs to be substract once

		}
	}

int ma = INT_MIN, sum;
	for(int i = 0; i < n; i++) { //for the starting co ordinate
		for(int j = 0; j < n; j++) {
			for(int k = i; k < n; k++) { //for the destination co ordinate
				for(int l = j; l < n; l++) { // k= i, l = j, as destination can be same or greater than starting, but not less than that
					sum = ar[k][l]; //from 0,0 to k,l summation in sum
					if(i > 0) 
						sum -= ar[i-1][l]; 
					if(j > 0) 
						sum -= ar[k][j-1];
					if(i > 0 && j > 0) 
						sum += ar[i-1][j-1]; //as it will be substract twice, need to sum it once
					ma = max(ma, sum);
				}
			}
		}
	}
	cout << ma << endl;
	return 0;
}

/*
n = 3, a 3*3 matrix

0,0  0,1  0,3
1,0  1,1  1,3
2,0  2,1  2,3

starting - 1,1
destination - 2,3
ar[i-1][l] = 0,3
ar[k][j-1] = 2,0
ar[i-1][j-1] = 0,0
*/
