#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triangle;

void compute_maximum(int size) {
    if (size == 1) {
        return;
    }
    int sub_size = (2 * size + 2) / 3; // ceiling of 2n/3 (aka the sub-triangles that fit everything)
    if (size == 2) {
        sub_size = 1; // if the triangle is just a 2 row triangle, the subs are just each individal element
    }
    compute_maximum(sub_size); // recursion (divide and conquer method) to keep getting smaller sub-triangles
    for (int i = 0; i <= triangle.size()-size; ++i) {
        for (int j = 0; j <= i; ++j) {
            // get the max of the three sub-triangles (the tips)
            triangle[i][j] = max(triangle[i][j], max(triangle[i + size - sub_size][j], triangle[i + size - sub_size][j + size - sub_size]));
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    triangle.resize(n);

    // store triangle
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int e;
            cin >> e;
            triangle[i].push_back(e);
        }
    }

    // find sub-triangles
    compute_maximum(k);

    // calculate sum
    long long sum = 0;
    for (int i = 0; i <= n - k; ++i) {
        for (int j = 0; j <= i; ++j) {
            sum += triangle[i][j];
        }
    }
    cout << sum << '\n';
}

//int main()
//{
//    int n, k;
//    cin >> n >> k;
//
//    // store triangle
//    vector<vector<int>> triangle;
//    for (int i = 0; i < n; ++i) {
//        vector<int> temp;
//        for (int j = 0; j <= i; ++j) {
//            int e;
//            cin >> e;
//            temp.push_back(e);
//        }
//        triangle.push_back(temp);
//    }
//
//    // find sub-triangles of size k
//    long long sum = 0;
//    int r = 0, c = 0;
//
//    // choose root node
//    while (true) {
//        if (c == (int)triangle[r].size()) {
//            r++;
//            if (r == (int)triangle.size() - k + 1) {
//                break;
//            }
//            c = 0;
//        }
//        int tr = r, tc = c;
//        set<int> elements;
//        // find sub-triangle at chosen "root" node
//        for (int i = 0; i < k; ++i) {
//            for (int j = 0; j <= i; ++j) {
//                elements.insert(triangle[tr][tc]);
//                tc++;
//            }
//            tr++;
//            tc = c;
//        }
//        sum += *elements.rbegin();
//        c++;
//    }
//    cout << sum;
//}