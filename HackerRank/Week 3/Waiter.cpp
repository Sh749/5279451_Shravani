#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */



bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vector<int> generatePrimes(int q) {
    vector<int> primes;
    int num = 2;
    while ((int)primes.size() < q) {
        if (isPrime(num)) primes.push_back(num);
        num++;
    }
    return primes;
}

vector<int> waiter(vector<int> number, int q) {
    vector<int> primes = generatePrimes(q);
    vector<int> answers;
    vector<int> A = number;  // start with given plates

    for (int i = 0; i < q; i++) {
        vector<int> B, nextA;
        // process from top to bottom (last element is top)
        for (int j = (int)A.size() - 1; j >= 0; j--) {
            int plate = A[j];
            if (plate % primes[i] == 0) {
                B.push_back(plate);
            } else {
                nextA.push_back(plate);
            }
        }
        // print B stack (top to bottom)
        for (int j = (int)B.size() - 1; j >= 0; j--) {
            answers.push_back(B[j]);
        }
        A = nextA;
    }

    // finally print remaining A stack (top to bottom)
    for (int j = (int)A.size() - 1; j >= 0; j--) {
        answers.push_back(A[j]);
    }

    return answers;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
