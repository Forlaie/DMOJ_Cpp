#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> worstRank(n+1);
    worstRank.push_back(0);
    map<int, int> points;
    vector<int> top;
    for (int i = 0; i < k; ++i) {
        // seperate line into an array
        string info, point;
        getline(cin >> ws, info);
        vector<int> roundPoints;
        roundPoints.push_back(0);
        stringstream s(info);
        while (getline(s, point, ' ')) {
            roundPoints.push_back(stoi(point));
        }

        // update points
        for (int j = 1; j <= n; ++j) {
            points[j] += roundPoints[j];
        }

        // update best yodeller

        // sort all points to rank it
        set<int> ranks;
        for (auto it = points.begin(); it != points.end(); ++it) {
            ranks.insert(it->second);
        }

        // update worst rank
        int rank = 1;
        for (auto itr = ranks.rbegin(); itr != ranks.rend(); ++itr) {
            for (auto it = points.begin(); it != points.end(); ++it) {
                if (*itr == it->second) {
                    worstRank[it->first] = max(worstRank[it->first], rank);
                    if (rank == 1 && i == k-1) {
                        top.push_back(it->first);
                    }
                }
            }
            rank++;
        }
    }

    // print all winners
    for (int i = 0; i < top.size(); ++i) {
        cout << "Yodeller " << top[i] << " is the TopYodeller: score " << points[top[i]] << ", worst rank " << worstRank[top[i]] << '\n';
    }
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    int n, k;
//    cin >> n >> k;
//    vector<int> worstRank(n);
//    vector<int> points(n);
//    int top = 0;
//    for (int i = 0; i < k; ++i) {
//        // seperate line into an array
//        string info, point;
//        getline(cin >> ws, info);
//        vector<int> roundPoints;
//        stringstream s(info);
//        while (getline(s, point, ' ')) {
//            roundPoints.push_back(stoi(point));
//        }
//
//        // update points
//        for (int j = 0; j < n; ++j) {
//            points[j] += roundPoints[j];
//        }
//
//        // update best yodeller
//
//        // update worst ranks
//        // initialize
//        vector<int> roundRanks(n);
//        for (int j = 0; j < n; ++j) {
//            roundRanks[j] = j+1;
//        }
//        // insertion sort
//        for (int index = 0; index < n; ++index) {
//            int currentIndexValue = points[roundRanks[index]-1];
//            int yodeller = roundRanks[index];
//            int sortedIndex = index - 1;
//            while (sortedIndex > -1 && points[roundRanks[sortedIndex] - 1] < currentIndexValue) {
//                roundRanks[sortedIndex + 1] = roundRanks[sortedIndex];
//                sortedIndex--;
//            }
//            roundRanks[sortedIndex + 1] = yodeller;
//        }
//        // update accordingly
//        for (int j = 0; j < n; ++j) {
//            worstRank[j] = max(worstRank[j], roundRanks[j]);
//        }
//
//        // update top yodeller
//        top = roundRanks[0];
//    }
//
//    cout << "Yodeller " << top << " is the TopYodeller: score " << points[top-1] << ", worst rank " << worstRank[top-1];
//    //Yodeller 5 is the TopYodeller: score 996, worst rank 5
//}