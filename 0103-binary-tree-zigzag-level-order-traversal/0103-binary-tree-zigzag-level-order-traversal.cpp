/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int f = 0 ;
           queue<TreeNode*>q;
        vector<vector<int>>v;
        if(root == NULL)
            return v;
        q.push(root) ;
       int len ;
        TreeNode * temp;
        while(!q.empty()){
            len = q.size();
            vector<int>help;
            f = (!f);
            for(int i  = 0 ; i < len ; i++){
                temp = q.front();
                q.pop();
                help.push_back(temp->val);
                  if(temp->right) 
                    q.push(temp ->right);
                if(temp->left) 
                    q.push(temp->left);
            }
            if(f == 1)
                reverse(help.begin(), help.end());
          v.push_back(help);
        }
        return v ;
    }
};