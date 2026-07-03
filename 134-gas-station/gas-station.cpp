class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0, st = 0;

        for(int i=0; i<n; i++) {
            tank += gas[i] - cost[i];

            if(tank < 0) {
                tank = 0;
                st = (i+1)%n;
            }
        }

        int step = 0;
        int i = st;
        tank = 0;

        while(step < n) {
            tank += gas[i] - cost[i];
            step++;
            i = (i+1)%n;

            if(tank < 0) return -1;
        }

        return st;
    }
};