#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    for (long long i = 0; i < t; ++i) {
        long long n;
        cin >> n;

        if (n < 10) {
            cout << "NO\n";
        }

        // check if composite
        else {
            bool composite = false;
            for (long long j = 2; j <= n / 2; ++j) {
                if (n % j == 0) {
                    composite = true;
                    break;
                }
            }
            if (!composite) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
    }
}