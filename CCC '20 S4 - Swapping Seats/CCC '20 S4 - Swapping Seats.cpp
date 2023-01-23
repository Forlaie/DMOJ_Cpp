#include <bits/stdc++.h>
using namespace std;

int main()
{
    string initialseats;
    cin >> initialseats;
    map<char, int> groupA;
    map<char, int> groupB;
    map<char, int> groupC;
    set<int> swaps;

    // how big groups need to be
    int a, b, c;
    a = count(initialseats.begin(), initialseats.end(), 'A');
    b = count(initialseats.begin(), initialseats.end(), 'B');
    c = count(initialseats.begin(), initialseats.end(), 'C');
    
    // A B C organization
    // find inital # of letters in each group
    for (int i = 0; i < a; ++i) {
        groupA[initialseats[i]]++;
    }
    for (int i = a; i < a+b; ++i) {
        groupB[initialseats[i]]++;
    }
    for (int i = a+b; i < a+b+c; ++i) {
        groupC[initialseats[i]]++;
    }

    for (int i = 0; i < initialseats.size(); ++i) {
        // formula
        int num = (groupA['B'] + groupA['C']) + (groupB['A'] + groupB['C']) - min(groupA['B'], groupB['A']);
        swaps.insert(num);

        // sliding window (change group position)
        int oldAp = i;
        if (oldAp >= initialseats.size()) {
            oldAp -= initialseats.size();
        }
        char oldAc = initialseats[oldAp];
        int oldBp = a + i;
        if (oldBp >= initialseats.size()) {
            oldBp -= initialseats.size();
        }
        char oldBc = initialseats[oldBp];
        int oldCp = a + b + i;
        if (oldCp >= initialseats.size()) {
            oldCp -= initialseats.size();
        }
        char oldCc = initialseats[oldCp];
        // old for A -> new for C
        // old for B -> new for A
        // old for C -> new for B
        groupA[oldAc]--;
        groupA[oldBc]++;
        groupB[oldBc]--;
        groupB[oldCc]++;
        groupC[oldCc]--;
        groupC[oldAc]++;
    }

    // C B A organization
    // find inital # of letters in each group
    groupA.clear();
    groupB.clear();
    groupC.clear();
    for (int i = 0; i < c; ++i) {
        groupC[initialseats[i]]++;
    }
    for (int i = c; i < c + b; ++i) {
        groupB[initialseats[i]]++;
    }
    for (int i = c + b; i < c + b + a; ++i) {
        groupA[initialseats[i]]++;
    }

    for (int i = 0; i < initialseats.size(); ++i) {
        // formula
        int num = (groupA['B'] + groupA['C']) + (groupB['A'] + groupB['C']) - min(groupA['B'], groupB['A']);
        swaps.insert(num);

        // sliding window (change group position)
        int oldCp = i;
        if (oldCp >= initialseats.size()) {
            oldCp -= initialseats.size();
        }
        char oldCc = initialseats[oldCp];
        int oldBp = c + i;
        if (oldBp >= initialseats.size()) {
            oldBp -= initialseats.size();
        }
        char oldBc = initialseats[oldBp];
        int oldAp = c + b + i;
        if (oldAp >= initialseats.size()) {
            oldAp -= initialseats.size();
        }
        char oldAc = initialseats[oldAp];
        // old for C -> new for A
        // old for B -> new for C
        // old for A -> new for B
        groupC[oldCc]--;
        groupC[oldBc]++;
        groupB[oldBc]--;
        groupB[oldAc]++;
        groupA[oldAc]--;
        groupA[oldCc]++;
    }
    std::cout << *swaps.begin();
}
// could have done both organizations simultaneously in one loop
