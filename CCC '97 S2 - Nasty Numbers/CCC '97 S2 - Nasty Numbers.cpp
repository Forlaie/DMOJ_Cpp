#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        set<int> sum;
        set<int> diff;
        for (int j = 1; j < sqrt(num) + 1; ++j) {
            if (num % j == 0) {
                sum.insert(j + num / j);
                diff.insert(j - num / j);
                diff.insert(num / j - j);
            }
        }

        bool nasty = false;
        for (auto itr = sum.begin(); itr != sum.end(); ++itr) {
            if (diff.find(*itr) != diff.end()) {
                nasty = true;
                break;
            }
        }

        if (nasty) {
            cout << num << " is nasty\n";
        }
        else {
            cout << num << " is not nasty\n";
        }
    }
}
