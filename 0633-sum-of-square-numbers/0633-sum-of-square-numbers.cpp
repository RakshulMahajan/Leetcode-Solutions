
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<0) return false;
        
        long left = 0;
        long right = (int)sqrt(c);
        
        while(left<= right){
            long sum = left*left + right*right;
            
            if(sum == c) return true;
            else if(sum<c) left++;
            else right--;
        }
        return false;
    }
};