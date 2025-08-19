#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    unordered_map<char,int>freq;
    for(char c:s){
        freq[c]++;
    }
    unordered_map<int, int>countfreq;
    for(auto&pair : freq){
        countfreq[pair.second]++;
    }
    if (countfreq.size() == 1){
        return "YES";
    } else if (countfreq.size() == 2){
        auto it = countfreq.begin();
        int freq1 = it->first;
        int count1 = it->second;
        it++;
        int freq2 = it->first;
        int count2 = it->second;
        if ((freq1 == 1 && count1 == 1)||(freq2 == 1 && count2 == 1)){
            return "YES";
        }
        if (abs(freq1 - freq2) == 1 && (count1 == 1 || count2 == 1)){
            return "YES";
        }
    }
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}