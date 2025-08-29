#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    multiset<int> heap;  

    while (Q--) {
        int type, v;
        cin >> type;
        if (type == 1) {
            cin >> v;
            heap.insert(v);   
        } else if (type == 2) {
            cin >> v;
            auto it = heap.find(v); 
            if (it != heap.end()) heap.erase(it); 
        } else if (type == 3) {
            cout << *heap.begin() << "\n"; 
        }
    }

    return 0;
}

