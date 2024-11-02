class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        int space = 0;
        for(int i = 0; i<n; i++){
            if(sentence[i] == ' '){
                space++;
            }
        }
        
        if(sentence[0] != sentence[n-1]){
            return false;
        }
        
        
        if(space>0){
             for(int i = 0; i<n; i++){
                 if(sentence[i] == ' '){
                     if(sentence[i-1] != sentence[i+1]){
                         return false;
                         break;
                     }
                 }
             }
        }
        
        return true;
    }
};