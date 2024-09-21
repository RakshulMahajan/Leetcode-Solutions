class Solution {
public:
    void solve(vector<int>&ans,int n,string &temp){
        int x=stoi(temp);
        if(x>n) return;
        ans.push_back(x);
        for(int i=0;i<=9;i++){
            temp.push_back(i+'0');
            solve(ans,n,temp);
            temp.pop_back();
        }
        if(temp.size()==1 && x!=9){
            temp=to_string(x+1);
            solve(ans,n,temp);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        string c="1";
        solve(ans,n,c);
        return ans;
    }
};