#include <bits/stdc++.h>
using namespace std;

map<char, int> moml, dadl;

string possible(string baby) {
    for (long unsigned int j = 0; j < baby.size(); ++j) {
        if (islower(baby[j])) {
            if (moml[baby[j]] == 0 || dadl[baby[j]] == 0) {
                return "Not their baby!";
            }
        }
        if (isupper(baby[j])) {
            if (moml[baby[j]] == 0 && dadl[baby[j]] == 0) {
                return "Not their baby!";
            }
        }
    }
    return "Possible baby.";
}

int main()
{
    string mom, dad;
    cin >> mom >> dad;

    for (long unsigned int i = 0; i < mom.size(); ++i) {
        moml[mom[i]]++;
        dadl[dad[i]]++;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string baby;
        cin >> baby;
        cout << possible(baby) << endl;
    }
}
