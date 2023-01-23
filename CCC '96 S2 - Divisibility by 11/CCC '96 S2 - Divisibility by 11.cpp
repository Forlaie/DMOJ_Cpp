#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string num;
        cin >> num;
        cout << num << '\n';
        vector<int> digits;
        for (int j = 0; j < num.size(); ++j) {
            digits.push_back(num[j]-'0');
        }

        while (digits.size() > 2) {
            int removed = digits[digits.size()-1];
            digits.pop_back();
            bool done = false;
            while (!done) {
                if (digits[digits.size() - 1] < removed) {
                    digits[digits.size() - 1] += 10;
                    for (int j = digits.size() - 2; j >= 0; --j) {
                        if (digits[j] != 0) {
                            digits[j]--;
                            if (digits[j] == 0 && j == 0) {
                                digits.erase(digits.begin());
                            }
                            done = true;
                            break;
                        }
                        else {
                            digits[j] = 9;
                        }
                    }
                }
                else {
                    done = true;
                }
            }
            digits[digits.size() - 1] -= removed;
            
            for (auto itr = digits.begin(); itr != digits.end(); ++itr) {
                cout << *itr;
            }
            cout << '\n';
        }

        string newNum = "";
        for (auto itr = digits.begin(); itr != digits.end(); ++itr) {
            newNum += to_string(*itr);
        }
        int finalNum = stoi(newNum);

        if (i != n - 1) {
            if (finalNum % 11 == 0) {
                cout << "The number " << num << " is divisible by 11.\n\n";
            }
            else {
                cout << "The number " << num << " is not divisible by 11.\n\n";
            }
        }
        else {
            if (finalNum % 11 == 0) {
                cout << "The number " << num << " is divisible by 11.\n";
            }
            else {
                cout << "The number " << num << " is not divisible by 11.\n";
            }
        }
    }
}
