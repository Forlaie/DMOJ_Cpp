#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 1000; i <= 9999; ++i) {
        int sum = -i;
        for (int j = 1; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                sum += j;
                sum += i / j;
            }
        }
        if (sum == i) {
            cout << i << " ";
        }
    }
    cout << '\n';

    for (int i = 100; i <= 999; ++i) {
        int sum = pow(i % 10, 3) + pow(i / 10 % 10, 3) + pow(i / 100 % 10, 3);
        if (sum == i) {
            cout << i << " ";
        }
    }
}
