class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int check = numBottles;
        int ans = numBottles;
        while(check>=numExchange){
            ans+= check/numExchange;
            check = check%numExchange + check/numExchange;
        }
        return ans;
    }
};