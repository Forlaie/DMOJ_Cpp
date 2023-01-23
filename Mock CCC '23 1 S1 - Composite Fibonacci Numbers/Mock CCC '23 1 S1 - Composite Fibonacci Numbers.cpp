#include <bits/stdc++.h>
using namespace std;

vector<string> f;

void fib() {
    int n1 = 0;
    int n2 = 1;
    f.push_back(to_string(n1));
    for (int i = 0; i < 25; ++i) {
        int n3 = n2;
        n2 = n1 + n2;
        n1 = n3;
        f.push_back(to_string(n1));
    }
}

int main()
{
    //fib();
    /*for (auto itr = f.begin(); itr != f.end(); ++itr) {
        cout << *itr << " ";
    }*/
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        if (n < 10) {
            cout << "NO\n";
        }
        else {
            // check if composite
            bool composite = false;
            for (int j = 2; j <= n/2+1; ++j) {
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
        //else {
        //    // check if fibonnaci
        //    bool fibonnaci = false;
        //    string ns = to_string(n);
        //    for (int i = 0; i < ns.size(); ++i) {
        //        string temp = ns.substr(i, 1);

        //        // couldn't find
        //        if (find(f.begin(), f.end(), temp) == f.end()) {
        //            fibonnaci = false;
        //            int begin = i - 1, len = 2;

        //            while (begin >= 0 || len + begin < ns.size()) {
        //                // add end
        //                if (len + i < ns.size()) {
        //                    temp = ns.substr(i, len);
        //                    if (find(f.begin(), f.end(), temp) != f.end()) {
        //                        fibonnaci = true;
        //                        break;
        //                    }
        //                }
        //                // add front
        //                if (begin >= 0) {
        //                    temp = ns.substr(begin, len);
        //                    if (find(f.begin(), f.end(), temp) != f.end()) {
        //                        fibonnaci = true;
        //                        break;
        //                    }
        //                }
        //                len++;
        //                if (begin >= 0 && len + begin < ns.size()) {
        //                    temp = ns.substr(begin, len);
        //                    if (find(f.begin(), f.end(), temp) != f.end()) {
        //                        fibonnaci = true;
        //                        break;
        //                    }
        //                }
        //                begin--;
        //            }
        //            if (!fibonnaci) {
        //                break;
        //            }
        //        }
        //        else {
        //            fibonnaci = true;
        //        }
        //    }
        //    if (fibonnaci && ns.size() > 1) {
        //        cout << "YES\n";
        //    }
        //    else {
        //        cout << "NO\n";
        //    }
        //}
    }
}