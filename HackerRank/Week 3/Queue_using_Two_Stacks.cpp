#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int q;
    cin >> q;
    stack<int>s1, s2;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            s1.push(x);
        } else if (type == 2) {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if (!s2.empty()) {
                s2.pop();
            }
        }
        else if (type == 3) {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                
                }
                if (!s2.empty()) {
                    cout << s2.top() << endl;
            }
        }
    }   
    return 0;
}