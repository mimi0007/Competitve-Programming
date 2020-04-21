#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	string s, s1;
	set <string> st; //declaring set, set will take only distinct values, and keeps sorting the values
	while(getline(cin,s)) { // will take the input line by line, give output in a whole
		s.push_back('.'); //to eradicate catenation of the last word of previous line to the first word of present line
		for(int i = 0; i < s.size(); i++) {
			if(s[i]>= 'A' && s[i] <= 'Z') {
				s[i] += 32;
				s1.push_back(s[i]);
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				s1.push_back(s[i]);
			}
			else {
				if(s1 == "") //if string becomes null, it will ignore it , like lines with no alphabets 
					continue;
				st.insert(s1);  //inserting the string to set 
				s1= ""; // again making it null, to make it prepare for next string
			}	
		}
    /*if(s1 != "") {
			v.push_back(s1); //another way (without pushing '.' in line 10)
		}*/   
	}
	for(auto i: st) {
		cout << i << endl; //multiset will take all values, and keeps sorting the values
	}
	return 0;
}
