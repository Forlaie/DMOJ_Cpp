#include <bits/stdc++.h>
using namespace std;

int pennies(int r) {
    int total = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 0; j <= r; ++j) {
            if (i * i + j * j <= r * r) {
                total++;
            }
            else {
                break;
            }
        }
    }
    return 4 * total + 1;
}

int main()
{
    int r;
    cin >> r;
    while (r != 0) {
        cout << pennies(r) << endl;
        cin >> r;
    }
}
