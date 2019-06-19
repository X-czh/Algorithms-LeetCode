class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int N = gas.length;
        
        for (int i = 0; i < N; i++) {
            int gas_amount = 0;
            boolean flag = true;
            for (int j = 0; j < N; j++) {
                int loc = (i + j) % N;
                gas_amount += gas[loc];
                if (gas_amount < cost[loc]) {
                    flag = false;
                    break;
                } else {
                    gas_amount -= cost[loc];
                }
            }
            if (flag) {
                return i;
            }
        }
        
        return -1;
    }
}