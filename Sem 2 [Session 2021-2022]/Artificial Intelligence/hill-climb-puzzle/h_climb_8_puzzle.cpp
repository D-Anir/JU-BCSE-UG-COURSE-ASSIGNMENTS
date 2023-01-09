#include <bits/stdc++.h>

using namespace std;

// 8 Puzzle Problem
// Heuristic h(n)
int hn(vector<vector<int>> state, vector<vector<int>> goal) {
    int manhattan = 0;
    for (int i1 = 0; i1 < 3; ++i1) {
        for (int j1 = 0; j1 < 3; ++j1) {
            for (int i2 = 0; i2 < 3; ++i2) {
                for (int j2 = 0; j2 < 3; ++j2) {
                    if (state[i1][j1] == goal[i2][j2]) {
                        manhattan += abs(i2 - i1) + abs(j2 - j1);
                    }
                }
            }
        }
    }
    return manhattan;
}

// Get Neighbours
vector<vector<vector<int>>> getNeighbours(vector<vector<int>> state) {
    int i1, j1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state[i][j] == 0)
                i1 = i, j1 = j;
        }
    }
    vector<vector<vector<int>>> neighbours;
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    for (int i = 0; i < 4; ++i) {
        int x = i1 + dx[i], y = j1 + dy[i];
        if (x >= 0 && x < 3 && y >= 0 && y < 3) {
            vector<vector<int>> newState = state;
            swap(newState[i1][j1], newState[x][y]);
            neighbours.push_back(newState);
        }
    }
    return neighbours;
}

// Show State
void showState(vector<vector<int>> state) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << state[i][j] << " ";
        }
        cout << "\n";
    }
}

// Compare State
bool compareState(vector<vector<int>> state, vector<vector<int>> goal) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state[i][j] != goal[i][j])
                return false;
        }
    }
    return true;
}

// Get Move
string getMove(vector<vector<int>> state, vector<vector<int>> prev) {
    int i1, j1, i2, j2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state[i][j] == 0)
                i1 = i, j1 = j;
            if (prev[i][j] == 0)
                i2 = i, j2 = j;
        }
    }
    string s = "";
    if (i1 = i2 + 1 && j1 == j2)
        s = "MOVE DOWN";
    else if (i1 = i2 - 1 && j1 == j2)
        s = "MOVE UP";
    else if (i1 = i2 && j1 == j2 + 1)
        s = "MOVE RIGHT";
    else if (i1 = i2 && j1 == j2 - 1)
        s = "MOVE LEFT";
    return s;
}

// Hill Climbing
void hillClimbing(vector<vector<int>> init, vector<vector<int>> goal) {
    cout << "Step - 0\n";
    showState(init);
    int limit = 20;
    while (!compareState(init, goal)) {
        vector<vector<vector<int>>> neighbours = getNeighbours(init);
        int sz = neighbours.size();
        vector<vector<int>> opMove = init;
        int opVal = hn(init, goal);
        for (int i = 0; i < sz; ++i) {
            int temp = hn(neighbours[i], goal);
            if (temp <= opVal) {
                opVal = temp;
                opMove = neighbours[i];
            }
        }
        if (compareState(init, opMove)) {
            break;
        }
        cout << "\nStep - " << 21 - limit << "\n";
        cout << getMove(opMove, init) << "\n";
        init = opMove;
        showState(init);
        --limit;
        if (limit == 0)
            break;
    }
}

int main() {

    vector<vector<int>> init = {{2, 8, 3}, {1, 6, 4}, {7, 0, 5}}, goal = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
    hillClimbing(init, goal);

    return 0;
}