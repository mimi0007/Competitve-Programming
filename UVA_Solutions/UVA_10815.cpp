#include <bits/stdc++.h>

using namespace std;

int main() {
	//freopen("/home/mimi0007/Desktop/in.txt", "r", stdin);
	string s, s1;
	vector <string> v; // will take the input line by line, give output in a whole
	while(getline(cin,s)) { 
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
				v.push_back(s1);  //pushing the string in a vector 
				s1= ""; // null //again making it null, to make it prepare for next string
			}	
		}
    /*if(s1 != "") {
			v.push_back(s1); //another way (without pushing '.' in line 10)
		}*/   
	}
	
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size()-1; i++) {
		if(v[i] == v[i+1]) { //if two string matches, it will ignore to have only one value
			continue;
		}
		
		else {
			cout << v[i] << endl;
		}
	}
	cout << v[v.size() - 1] << endl; // for the last string 
	return 0;
}
