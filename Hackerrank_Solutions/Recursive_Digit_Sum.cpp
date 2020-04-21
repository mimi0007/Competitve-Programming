#include <bits/stdc++.h>

using namespace std;

long long int add(long long int m) {
    long long int s1 = 0, p;
    while(m != 0) {
        p = m % 10;
        s1 += p;
        m /= 10; 
    }
    return s1;
}

int main() {
    string s;
    long long int sum = 0, k, sum1;
    cin >> s >> k;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '9')
            sum += 9;
        else if(s[i] == '8')
            sum += 8;
        else if(s[i] == '7')
            sum += 7;
        else if(s[i] == '6')
            sum += 6;
        else if(s[i] == '5')
            sum += 5;
        else if(s[i] == '4')
            sum += 4;
        else if(s[i] == '3')
            sum += 3;
        else if(s[i] == '2')
            sum += 2;
        else if(s[i] == '1')
            sum += 1;    
        }
        sum1 = sum * k;
        while(1) {
            if(sum1 < 10) {
                cout << sum1 << endl;
                break;
            }
            else 
                sum1 = add(sum1); 
        }

    return 0;
}

