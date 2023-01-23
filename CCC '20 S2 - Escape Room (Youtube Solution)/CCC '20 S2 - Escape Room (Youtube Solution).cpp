#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Cell {
public:
    int r;
    int c;
};

bool searched[1010][1010];
vector<vector<Cell>> vals(1000010);

string is_possible(Cell last_cell) {
    queue<Cell> q;
    q.push(last_cell);
    while (q.size() > 0) {
        Cell cell = q.front();
        q.pop();
        vector<Cell> neighbours = vals[cell.r * cell.c];
        for (Cell neighbour : neighbours) {
            if (neighbour.r == 1 && neighbour.c == 1) {
                return "yes";
            }
            else if (!searched[neighbour.r][neighbour.c]) {
                searched[neighbour.r][neighbour.c] = true;
                q.push(neighbour);
            }
        }
    }
    return "no";
}

int main()
{
    int rows, columns;
    cin >> rows >> columns;
    Cell last_cell;

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= columns; ++j) {
            int value;
            cin >> value;
            Cell cell;
            cell.r = i; cell.c = j;
            vals[value].push_back(cell);

            if (i == rows && j == columns) {
                last_cell = cell;
            }
        }
    }
    cout << is_possible(last_cell);
    return 0;
}