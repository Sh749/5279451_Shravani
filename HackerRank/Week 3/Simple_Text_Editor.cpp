#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

#include <stack>


int main() {
    int q;
    cin >> q;
    string s = "";
    stack<pair<int, string>> history; 

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            string w;
            cin >> w;
            history.push({1, w});
            s += w;
        } 
        else if (type == 2) {
            int k;
            cin >> k;
            string deleted = s.substr(s.size() - k, k);
            history.push({2, deleted});
            s.erase(s.size() - k, k);
        } 
        else if (type == 3) {
            int k;
            cin >> k;
            cout << s[k - 1] << endl;
        } 
        else if (type == 4) {
            if (!history.empty()) {
                auto last = history.top();
                history.pop();
                if (last.first == 1) {
                    
                    s.erase(s.size() - last.second.size(), last.second.size());
                } else if (last.first == 2) {
                    
                    s += last.second;
                }
            }
        }
    }

    return 0;
}
