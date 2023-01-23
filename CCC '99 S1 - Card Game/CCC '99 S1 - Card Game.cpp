#include <iostream>
#include <string>
#include <map>
using namespace std;

int a = 0, b = 0;
map<string, int> ac, bc;

void updatePoints() {
    if (ac.count("ace") != 0 && ac.at("ace") == 5) {
        a += 4;
        ac.erase("ace");
        cout << "Player A scores 4 point(s)." << endl;
    }
    if (bc.count("ace") != 0 && bc.at("ace") == 5) {
        b += 4;
        bc.erase("ace");
        cout << "Player B scores 4 point(s)." << endl;
    }
    if (ac.count("king") != 0 && ac.at("king") == 4) {
        a += 3;
        ac.erase("king");
        cout << "Player A scores 3 point(s)." << endl;
    }
    if (bc.count("king") != 0 && bc.at("king") == 4) {
        b += 3;
        bc.erase("king");
        cout << "Player B scores 3 point(s)." << endl;
    }
    if (ac.count("queen") != 0 && ac.at("queen") == 3) {
        a += 2;
        ac.erase("queen");
        cout << "Player A scores 2 point(s)." << endl;
    }
    if (bc.count("queen") != 0 && bc.at("queen") == 3) {
        b += 2;
        bc.erase("queen");
        cout << "Player B scores 2 point(s)." << endl;
    }
    if (ac.count("jack") != 0 && ac.at("jack") == 2) {
        a += 1;
        ac.erase("jack");
        cout << "Player A scores 1 point(s)." << endl;
    }
    if (bc.count("jack") != 0 && bc.at("jack") == 2) {
        b += 1;
        bc.erase("jack");
        cout << "Player B scores 1 point(s)." << endl;
    }
}

int main()
{
    string card;

    for (int i = 0; i < 52; ++i) {
        cin >> card;

        if (card == "ace") {
            ac.clear();
            bc.clear();
            if (i % 2 == 0) {
                ac["ace"]++;
            }
            else {
                bc["ace"]++;
            }
        }
        else if (card == "king") {
            ac.clear();
            bc.clear();
            if (i % 2 == 0) {
                ac["king"]++;
            }
            else {
                bc["king"]++;
            }
        }
        else if (card == "queen") {
            ac.clear();
            bc.clear();
            if (i % 2 == 0) {
                ac["queen"]++;
            }
            else {
                bc["queen"]++;
            }
        }
        else if (card == "jack") {
            ac.clear();
            bc.clear();
            if (i % 2 == 0) {
                ac["jack"]++;
            }
            else {
                bc["jack"]++;
            }
        }
        else {
            for (auto itr = ac.begin(); itr != ac.end(); ++itr) {
                ac[itr->first]++;
            }
            for (auto itr = bc.begin(); itr != bc.end(); ++itr) {
                bc[itr->first]++;
            }
        }
        updatePoints();
    }
    cout << "Player A: " << a << " point(s)." << endl;
    cout << "Player B: " << b << " point(s)." << endl;
}
