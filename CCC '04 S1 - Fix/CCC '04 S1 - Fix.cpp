#include <iostream>
#include <string>
using namespace std;

string fixFree(string w1, string w2, string w3) {
    // prefix
    if (w1.size() <= w2.size()) {
        if (w2.substr(0, w1.size()) == w1) {
            return "No";
        }
    }
    if (w1.size() <= w3.size()) {
        if (w3.substr(0, w1.size()) == w1) {
            return "No";
        }
    }
    if (w2.size() <= w1.size()) {
        if (w1.substr(0, w2.size()) == w2) {
            return "No";
        }
    }
    if (w2.size() <= w3.size()) {
        if (w3.substr(0, w2.size()) == w2) {
            return "No";
        }
    }
    if (w3.size() <= w1.size()) {
        if (w1.substr(0, w3.size()) == w3) {
            return "No";
        }
    }
    if (w3.size() <= w2.size()) {
        if (w1.substr(0, w3.size()) == w3) {
            return "No";
        }
    }

    // suffix
    if (w1.size() <= w2.size()) {
        if (w2.substr(w2.size()-w1.size(), w2.size()) == w1) {
            return "No";
        }
    }
    if (w1.size() <= w3.size()) {
        if (w3.substr(w3.size() - w1.size(), w3.size()) == w1) {
            return "No";
        }
    }
    if (w2.size() <= w1.size()) {
        if (w1.substr(w1.size() - w2.size(), w1.size()) == w2) {
            return "No";
        }
    }
    if (w2.size() <= w3.size()) {
        if (w3.substr(w3.size() - w2.size(), w3.size()) == w2) {
            return "No";
        }
    }
    if (w3.size() <= w1.size()) {
        if (w1.substr(w1.size() - w3.size(), w1.size()) == w3) {
            return "No";
        }
    }
    if (w3.size() <= w2.size()) {
        if (w2.substr(w2.size() - w3.size(), w3.size()) == w3) {
            return "No";
        }
    }

    return "Yes";
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string w1, w2, w3;
        cin >> w1 >> w2 >> w3;
        cout << fixFree(w1, w2, w3) << endl;
    }
}
