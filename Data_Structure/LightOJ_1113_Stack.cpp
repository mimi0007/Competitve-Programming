#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string cur = "http://www.lightoj.com/";
        string S, url;
        cout << "Case " << i << ":" << endl;
        stack <string> B;
        stack <string> F;
        while (cin >> S) {
            if (S == "QUIT") {
                break;
            }

            else if (S == "VISIT") {
                cin >> url;
                B.push(cur);
                cur = url;
                cout << cur << endl;
                while(F.empty() != 1) {
                    F.pop();
                }
            }

            else if (S == "BACK") {
                if (B.empty() == 1) {
                    cout << "Ignored" <<endl;
                }
                else {
                    F.push(cur);
                    cur = B.top();
                    cout << cur << endl;
                    B.pop();
                }
            }

            else if (S == "FORWARD") {
                if (F.empty() == 1) {
                    cout << "Ignored" << endl;
                }

                else {
                    B.push(cur);
                    cur = F.top();
                    cout << cur << endl;
                    F.pop();
                }
            }
        }
    }
    return 0;
}
