#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int numOfStations, numOfWalkways, numOfDays;
    cin >> numOfStations >> numOfWalkways >> numOfDays;

    // make time of all walkways to get to final destination
    // make adjacency list (reverse search, from destination to ones its connected to, to make it easier)
    vector<vector<int>> adjList(numOfStations+1);
    for (int i = 0; i < numOfWalkways; ++i) {
        int stationA, stationB;
        cin >> stationA >> stationB;
        adjList[stationB].push_back(stationA);
    }
    // initialize walking time array
    vector<int> walkTime(numOfStations + 1);
    for (int i = 1; i < numOfStations; ++i) {
        walkTime[i] = 1e9;
    }
    walkTime[numOfStations] = 0;

    //bfs to find walking time
    queue<int> queue;
    vector<bool> visited(numOfStations + 1);
    queue.push(numOfStations);
    visited[numOfStations] = true;

    while (!queue.empty()) {
        int station = queue.front();
        queue.pop();

        for (int s : adjList[station]) {
            if (!visited[s]) {
                queue.push(s);
                walkTime[s] = walkTime[station] + 1;
                visited[s] = true;
            }
        }
    }
    
    // get subway locations
    vector<int> subways(numOfStations + 1);
    multiset<int> totalTime;
    for (int i = 1; i < numOfStations+1; ++i) {
        cin >> subways[i];
        totalTime.insert(i - 1 + walkTime[subways[i]]);
    }

    for (int i = 0; i < numOfDays; ++i) {
        int index1, index2;
        cin >> index1 >> index2;

        int oldDistIndex1 = index1 - 1 + walkTime[subways[index1]];
        int oldDistIndex2 = index2 - 1 + walkTime[subways[index2]];
        totalTime.erase(totalTime.find(oldDistIndex1));
        totalTime.erase(totalTime.find(oldDistIndex2));

        swap(subways[index1], subways[index2]);

        int newDistIndex1 = index1 - 1 + walkTime[subways[index1]];
        int newDistIndex2 = index2 - 1 + walkTime[subways[index2]];
        totalTime.insert(newDistIndex1);
        totalTime.insert(newDistIndex2);

        cout << *totalTime.begin() << '\n';
    }
}
