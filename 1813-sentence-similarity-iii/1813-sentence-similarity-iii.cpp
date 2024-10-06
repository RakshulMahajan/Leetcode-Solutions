class Solution {
public:
    vector<string> split(string sentence)
    {
        vector<string> s1;
        string s="";
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]!=' ')
                s+=sentence[i];
            else
            {
                s1.push_back(s);
                s="";
            }
        }

        s1.push_back(s);

        return s1;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {

        vector<string> s1=split(sentence1);
        vector<string> s2=split(sentence2);
       
       if(s1.size()>s2.size())
            swap(s1,s2);
        
        int i=0;
        int j=s1.size()-1;
        int k=s2.size()-1;

        while(i<s1.size() && s1[i]==s2[i])
            i++;
        
        while(j>=0 && s2[k]==s1[j])
           { j--;k--;}
        
        if(j<i)return true;
        return false;
    }
};