#include <bits/stdc++.h>
using namespace std;

string fit(vector<multiset<int>> bd, vector<int> bv, multiset<int> item, int v) {
    for (int i = 0; i < bv.size(); ++i) {
        if (v <= bv[i]) {
            multiset<int> box = bd[i];
            vector<int> tempb;
            vector<int> tempi;

            for (auto itr = box.begin(); itr != box.end(); ++itr) {
                tempb.push_back(*itr);
            }

            for (auto itr = item.begin(); itr != item.end(); ++itr) {
                tempi.push_back(*itr);
            }

            if (tempi[0] <= tempb[0] && tempi[1] <= tempb[1] && tempi[2] <= tempb[2]) {
                return to_string(bv[i]);
            }
            else {
                tempb.clear();
                tempi.clear();
            }
        }
    }
    return "Item does not fit.";
}

int main()
{
    int nb, ni;
    cin >> nb;
    vector<multiset<int>> bd;
    vector<int> bv;

    for (int i = 0; i < nb; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        multiset<int> temp = { a, b, c };
        int v = a * b * c;
        if (i == 0) {
            bd.push_back(temp);
            bv.push_back(v);
        }
        else if (v >= bv[bv.size() - 1]) {
            bd.push_back(temp);
            bv.push_back(v);
        }
        else {
            for (int j = 0; j < bv.size(); ++j) {
                if (v <= bv[j]) {
                    bd.insert(bd.begin() + j, temp);
                    bv.insert(bv.begin() + j, v);
                    break;
                }
            }
        }
    }

    cin >> ni;

    for (int i = 0; i < ni; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        multiset<int> item = { a, b, c };
        cout << fit(bd, bv, item, a*b*c) << endl;
    }
}
