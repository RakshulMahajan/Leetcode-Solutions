class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0;
        stack<int> st;
        for(int i = 0; i < pushed.size(); i++){
            st.push(pushed[i]);
            if(st.top() == popped[j]){ 
                // st.pop();
                // j++;
                while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
                }
            }
        }
        while(j < popped.size()){
            if(st.top() == popped[j]){
                st.pop();
            }
            j++;
        }
        return st.empty();
    }
};