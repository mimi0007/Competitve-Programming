#include <bits/stdc++.h>

using namespace std;

int LD(string s, int n) {
	vector <int> ans; //the quotient(vagfol) will be stored in this vector
	int num = 0;
	for(int i = 0; i < s.size(); i++) {
		num = (s[i] - '0') + num * 10;
		if(num >= n) {
			ans.push_back(num/n);
			num %= n;
		}
		
		else
			ans.push_back(0);
	}
	return num;
} 


int main() {
	freopen("/home/mimi0007/Desktop/Temp/in", "r", stdin);
    int f = 0;
    string s1;
    while(cin >> s1) {
        if(f > 0)
            cout << endl;
         
        int fr = LD(s1, 4), fft = LD(s1, 15), fftf = LD(s1, 55), hn = LD(s1, 100), frhn = LD(s1, 400);
        if ((fr == 0 && hn != 0) || (frhn == 0)) {
            cout << "This is leap year." << endl;
            if (fft == 0)
                cout << "This is huluculu festival year." << endl;
            if (fftf == 0)
                cout << "This is bulukulu festival year." << endl;
        }

        else {
            if (fft == 0)
                cout << "This is huluculu festival year." << endl;
            
            else
                cout << "This is an ordinary year." << endl;
        }
        f++;
    }
    return 0;
}
