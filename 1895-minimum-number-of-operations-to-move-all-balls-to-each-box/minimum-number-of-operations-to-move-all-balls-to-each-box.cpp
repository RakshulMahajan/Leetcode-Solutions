
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int x = 0;// previous contributions
        int y = 0;//number of ones
        // Calculating Prefix Sums
        for(int i = 0 ;i < n;i++){
            x += y;
            prefix[i] += x;
            if(boxes[i]=='1') y++;
        }
        for(int i = 0 ; i < n;i++)cout<<prefix[i]<<" ";
        x = 0;//previous contributions
        y = 0;//number of ones
        // Calculating Prefix Sums
        for(int i = n-1; i >= 0;i--){
            x+=y;
            suffix[i] += x;
            if(boxes[i]=='1') y++;
        }
        for(int i = n-1 ; i >=0 ;i--)cout<<suffix[i]<<" ";
        vector<int> ans(n,0);
        for(int i = 0 ; i < n;i++){    
             ans[i] =prefix[i] + suffix[i];
        }
        return ans;
    }
};