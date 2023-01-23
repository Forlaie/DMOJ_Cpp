#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// working backwards
int rows, columns;
bool visited[1010][1010];
vector<vector<vector<int>>> cellValues(1000010);

string search() {
    queue<vector<int>> queue;
    queue.push({ rows, columns });
    visited[rows][columns] = true;

    while (queue.size() > 0) {
        vector<int> location = queue.front();
        queue.pop();
        vector<vector<int>> neighbours = cellValues[location[0] * location[1]];
        for (vector<int> neighbour : neighbours) {
            if (neighbour[0] == 1 && neighbour[1] == 1) {
                return "yes";
            }
            else if (!visited[neighbour[0]][neighbour[1]]) {
                visited[neighbour[0]][neighbour[1]] = true;
                queue.push(neighbour);
            }
        }
    }
    return "no";
}

int main()
{
    //// working forwards

    //// make grid
    //int rows, columns;
    //cin >> rows >> columns;
    //vector<vector<int>> grid(rows + 1);

    //for (int i = 0; i < columns+1; ++i) {
    //    grid[0].push_back(0);

    //}

    //for (int i = 1; i <= rows; ++i) {
    //    grid[i].push_back(0);
    //    for (int j = 1; j <= columns; ++j) {
    //        cin >> value;
    //        grid[i].push_back(value);
    //    }
    //}

    //// do bfs
    //queue<int> queue;

    //vector<vector<bool>> visited(rows+1, vector<bool>(columns+1, false));

    ////vector<vector<bool>> visited(rows + 1);
    //queue.push(grid[1][1]);
    //visited[1][1] = true;
    //bool possible = false;

    //while (!queue.empty()) {
    //    int location = queue.front();
    //    queue.pop();

    //    for (int i = 1; i <= location / 2 + 1; ++i) {
    //        if (location % i == 0) {
    //            int r = i;
    //            int c = location / r;
    //            if (r == rows && c == columns) {
    //                possible = true;
    //                break;
    //            }
    //            if (r == columns && c == rows) {
    //                possible = true;
    //                break;
    //            }
    //            if (r <= rows && c <= columns && !visited[r][c]) {
    //                queue.push(grid[r][c]);
    //                visited[r][c] = true;
    //            }
    //            if (r <= columns && c <= rows && !visited[c][r]) {
    //                queue.push(grid[c][r]);
    //                visited[c][r] = true;
    //            }
    //        }
    //    }
    //}

    // working backwards

    cin >> rows >> columns;

    for (int r = 1; r <= rows; ++r) {
        for (int c = 1; c <= columns; ++c) {
            int value;
            cin >> value;
            cellValues[value].push_back({ r, c });
        }
    }

    cout << search();
}