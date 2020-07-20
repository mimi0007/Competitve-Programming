#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define ull unsigned long long int

//multiplication between a digit and a string
string fun(string s, int x) { 
	string ss;
	int c = 0, y, mul;
	for(int i = s.size()-1; i >= 0; i--) {
		y = s[i] - '0';
		mul = (x*y) + c;
		ss.push_back((mul % 10)+'0');   
		c = mul / 10;			
	} 
				
	if(c > 0) 
		ss.push_back(c + '0');
		
	reverse(ss.begin(), ss.end());
	return ss;
}
 
int main()    {
	//freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
	string a, b;
	while(cin >> a >> b) {
		if(a == "0" || b == "0") {
			cout << 0 << endl;
			continue;
		}
		string s1, s, s3;
		int x, sum, cc, k = 0;
		for(int i = b.size()-1; i >= 0; i--) {
			x = b[i] - '0';
			string s2;
			s2 = fun(a, x);
			for(int m = 0; m < k; m++)
				s2.push_back('0');
			k++;	
			cc = 0;	
      //big sum starts here
			while(!s3.empty() && !s2.empty()) {
				sum = (s3.back() - '0') + (s2.back() - '0') + cc;
				s.push_back((sum%10)+'0');
				cc = sum / 10;
				s3.pop_back();
				s2.pop_back();
			}
			while(!s3.empty()) {
				sum = (s3.back() - '0') + cc;
				s.push_back((sum%10) + '0');
				cc = sum/10;
				s3.pop_back();
			}
				
			while(!s2.empty()) {
				sum = (s2.back() - '0') + cc;
				s.push_back((sum%10) + '0');
				cc = sum/10;
				s2.pop_back();
			}
			if(cc > 0) 
				s.push_back(cc + '0'); //if there exist any carry then have to put it into the string (ex: 856+234)
									
			reverse(s.begin(), s.end());
			s3 = s;
			s.clear();
		}
		cout << s3 << endl;
	}
	return 0;
}


