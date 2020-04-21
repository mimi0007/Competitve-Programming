#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	int T, a, b, a1, b1, sum;
	cin >> T;
	string s[65], junk, ss;
	for(int k = 1; k <= T; k++) {
		cin >> a1 >> b1;
		getline(cin, junk); //for taking the junk string for enter
		sum = 0;
		for(int i = 0; i < a1; i++) {
			getline(cin, s[i]);
		}
		int f = 1;
		char c;
		cin >> a >> b;
		a--; //as we are starting with 0,0. we have to decrement the values
		b--;
		while(cin >> ss) {
			for(int i = 0; i < ss.size(); i++) {
				if(ss[i] == 'R') 
					sum += 1;
				else if(ss[i] == 'L') 
					sum -= 1;
				else if(ss[i] == 'F') {
					if(sum > 0) {
						sum %= 4;
					}
					
					else if (sum < 0) {
						sum =(sum * (-1)) % 4;
						sum *= (-1);
					}
					if(sum == 0) {
						c = 'N';
						if(s[a-1][b] != '*') {
							a -= 1; // to go up
						}
					}
					
					else if(sum == -3 || sum == 1) {
						c = 'E';
						if(s[a][b+1] != '*' && (b+1<b1 && b> 0)) {
							b += 1; //to go right
						}
					}
					
					else if(sum == 3 || sum == -1) {
						c = 'W';
						if(s[a][b-1] != '*' && (b-1<b1 && b > 0)) {
							b -= 1; //to go left
						}
					}
					
					else if(sum == 2 || sum == -2){
						c = 'S';
						if(s[a+1][b] != '*' && (a+1<a1 && a > 0)) {
							a += 1; //to go down
						}
					}  
				}
				else if(ss[i] == 'Q') {
					f = 0;
					break;
				}
			}
			if(f == 0)
				break;
		}
		//Again doing the same thing for tast cases like FRLRLQ etc to count R/L after F till Q
		if(sum > 0) {
			sum %= 4;
		}
					
		else if (sum < 0) {
			sum =(sum * (-1)) % 4;
			sum *= (-1);
		}
					
		if(sum == 0) 
			c = 'N';
					
		else if(sum == -3 || sum == 1) 
			c = 'E';
				
		else if(sum == 3 || sum == -1) 
			c = 'W';
					
		else if(sum == 2 || sum == -2)
			c = 'S';
		cout << a+1 << " " << b+1 << " " << c << endl;
		if(k!= T)
			cout << endl;
	}
	return 0;
}

