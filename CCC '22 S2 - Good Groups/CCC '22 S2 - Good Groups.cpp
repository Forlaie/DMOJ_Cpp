#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
    int count = 0;
    int sn, dn, gn;
    unordered_multimap<string, string> smap, dmap;

    cin >> sn;
    for (int i = 0; i < sn; ++i) {
        string name1, name2;
        cin >> name1 >> name2;
        smap.insert(make_pair(name1, name2));
        smap.insert(make_pair(name2, name1));
    }

    cin >> dn;
    for (int i = 0; i < dn; ++i) {
        string name1, name2;
        cin >> name1 >> name2;
        dmap.insert(make_pair(name1, name2));
        dmap.insert(make_pair(name2, name1));
    }

    cin >> gn;
    for (int i = 0; i < gn; ++i) {
        string name1, name2, name3;
        cin >> name1 >> name2 >> name3;

        // same groups
        auto its = smap.equal_range(name1);
        for (auto it = its.first; it != its.second; ++it) {
            if (it->second != name2 && it->second != name3) {
                count++;
            }
        }
        its = smap.equal_range(name2);
        for (auto it = its.first; it != its.second; ++it) {
            if (it->second != name1 && it->second != name3) {
                count++;
            }
        }
        its = smap.equal_range(name3);
        for (auto it = its.first; it != its.second; ++it) {
            if (it->second != name1 && it->second != name2) {
                count++;
            }
        }

        // different groups
        its = dmap.equal_range(name1);
        for (auto it = its.first; it != its.second; ++it) {
            if (it->second == name2 || it->second == name3) {
                count++;
            }
        }
        its = dmap.equal_range(name2);
        for (auto it = its.first; it != its.second; ++it) {
            if (it->second == name1 || it->second == name3) {
                count++;
            }
        }
        its = dmap.equal_range(name3);
        for (auto it = its.first; it != its.second; ++it) {
            if (it->second == name1 || it->second == name2) {
                count++;
            }
        }
    }
    cout << count/2;
}
