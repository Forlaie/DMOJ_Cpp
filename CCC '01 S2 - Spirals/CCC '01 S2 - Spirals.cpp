#include <bits/stdc++.h>
using namespace std;

int main()
{
    int start, end;
    cin >> start >> end;
    vector<vector<int>> spiral(12);
    for (int i = 0; i < 12; ++i) {
        vector<int> temp = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
        spiral[i] = temp;
    }

    int r = 5, c = 5;
    int num = start+1;
    int count = 1;
    int down = 0, right = 0, up = 0, left = 0;
    spiral[5][5] = start;
    while (num <= end) {
        if (down != 0) {
            r++;
            spiral[r][c] = num;
            down--;
            num++;
        }
        else if (right != 0) {
            c++;
            spiral[r][c] = num;
            right--;
            num++;
        }
        else if (up != 0) {
            r--;
            spiral[r][c] = num;
            up--;
            num++;
        }
        else if (left != 0){
            c--;
            spiral[r][c] = num;
            left--;
            num++;
        }
        else {
            down = count;
            right = count;
            up = down + 1;
            left = right + 1;
            count += 2;
        }
    }

    for (int i = 0; i < 12; ++i) {
        string s = "";
        for (int j = 0; j < 12; ++j) {
            if (spiral[i][j] != -1) {
                s += to_string(spiral[i][j]) + " ";
            }
        }
        if (s != "") {
            cout << s << '\n';
        }
    }
}
