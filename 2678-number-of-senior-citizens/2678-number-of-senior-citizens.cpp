class Solution {
public:
    int countSeniors(vector<string>& details) {
        vector <int> age;
        for(auto ele: details){
            string r = ele.substr(11,2);
            age.push_back(stoi(r));
        }
        int ans = 0;
        for(auto ele: age){
            if(ele>60) ans++;
        }
        return ans;
    }
};