#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<int>> lights;
set<vector<int>> combos;

void possibleStates() {
    int count = 0;
    for (int i = 0; i < r-1; ++i) {
        vector<vector<int>> l = lights;
        for (int j = 0; j <= count; ++j) {
            for (int k = 0; k < c; ++k) {
                if (l[count-j][k] == l[count-j+1][k]) {
                    l[count-j][k] = 0;
                }
                else {
                    l[count-j][k] = 1;
                }
            }
        }
        count++;
        combos.insert(l[0]);
    }
}

int main()
{
    cin >> r >> c;
    vector<int> temp;
    
    // get initial lights
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int s;
            cin >> s;
            temp.push_back(s);
        }
        lights.insert(lights.begin(), temp);
        temp.clear();
    }

    // find # of combos
    combos.insert(lights[0]);

    possibleStates();

    cout << combos.size();
}
