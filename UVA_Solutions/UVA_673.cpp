#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); //to eradicate space which will be taken by getline!
    while(T--) {
        int c2 = 0;
        string m;
        getline(cin, m);

        stack <char> s; // m[i] = one character, not a string, so the declaration is in character data type
        for(int i = 0; i < m.size(); i++) {
            if(m[i] == '(' || m[i] == '[') {
                s.push(m[i]);
            }

            else if(!s.empty()) {
                if ((m[i] == ']' && s.top() == '[') || (m[i] == ')' && s.top() == '(')) { //Compiler checks (all) the conditions in a conditional logic
                    s.pop();
                }

                else {
                    c2++;
                }
            }

            else {
                c2++;
            }



        }

        if(!s.empty()) {
            c2++;
        }

        if(c2 == 0) {
            cout << "Yes" << endl;
        }

        else {
            cout << "No" << endl;
        }

    }

    return 0;
}
