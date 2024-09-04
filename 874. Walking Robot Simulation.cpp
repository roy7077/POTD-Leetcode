typedef pair<int,int> pi;
class Solution {
    public:
    int directionsR[4]={0,1,0,-1};
    int directionsC[4]={1,0,-1,0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pi> st;
        for (auto& it : obstacles)
        st.insert({it[0], it[1]});

        // Directions: North, East, South, West
        int dir = 0; // Start facing North
        int x = 0, y = 0;
        int maxAns = 0;

        for (auto& c : commands) {
            if (c == -1) {
                // Turn right
                dir = (dir + 1) % 4;
            } else if (c == -2) {
                // Turn left
                dir = (dir + 3) % 4;
            } else {
                // Move forward
                for (int step = 0; step < c; ++step) {
                    int nx = x + directionsR[dir];
                    int ny = y + directionsC[dir];
                    if (st.count({nx, ny})) {
                        break; // Stop if there's an obstacle
                    }
                    x = nx;
                    y = ny;
                    maxAns = max(maxAns, x*x + y*y);
                }
            }
        }
        
        return maxAns;
    }
};
