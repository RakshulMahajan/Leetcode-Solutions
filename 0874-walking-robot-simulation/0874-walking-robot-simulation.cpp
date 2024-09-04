class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        // create a direction container
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_set<string> obs;

        // Store obstacles as a set of strings for easy lookup
        for (auto& obstacle : obstacles) {
            obs.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        int x = 0, y = 0, dir = 0, maxDistSquare = 0;

        for (auto c : commands) {
            if (c == -1) { // for turn right
                dir = (dir + 1) % 4;
            } else if (c == -2) { // for turn left
                dir = (dir + 3) % 4;
            } else { // move forward
                while (c--) {
                    int nx = x + directions[dir][0];
                    int ny = y + directions[dir][1];

                    if (obs.find(to_string(nx) + "," + to_string(ny)) !=
                        obs.end())
                        break;

                    x = nx;
                    y = ny;
                    maxDistSquare = max(maxDistSquare, x * x + y * y);
                }
            }
        }
        return maxDistSquare;
    }
};