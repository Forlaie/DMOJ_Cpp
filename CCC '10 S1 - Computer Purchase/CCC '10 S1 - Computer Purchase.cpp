#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int num;
    cin >> num;
    string first, second;
    int fval = 0, sval = 0;

    for (int i = 0; i < num; ++i) {
        string name; int r, s, d;
        cin >> name >> r >> s >> d;
        int value = 2 * r + 3 * s + d;
        if (value > fval) {
            sval = fval;
            second = first;

            fval = value;
            first = name;
        }
        else if (value == fval) {
            if (name < first) {
                sval = fval;
                second = first;

                fval = value;
                first = name;
            }
            else{
                if (value > sval) {
                    sval = value;
                    second = name;
                }
                else if (value == sval) {
                    if (name < second) {
                        sval = value;
                        second = name;
                    }
                }
            }
        }
        else if (value > sval) {
            sval = value;
            second = name;
        }
        else if (value == sval) {
            if (name < second) {
                sval = value;
                second = name;
            }
        }
    }

    if (num == 1) {
        cout << first << endl;
    }
    if (num > 1) {
        cout << first << endl;
        cout << second << endl;
    }
}
