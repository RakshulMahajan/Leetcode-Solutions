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

    vector<TreeNode*> generateTrees(int end, int start = 1) {
        vector<TreeNode*> ans;  
        if ( start> end)
            return {nullptr};\
        for (int i = start; i <= end; i++) {
            for (auto left : generateTrees(i - 1, start)) {
                for (auto right : generateTrees(end, i + 1))
                
                    ans.push_back(new TreeNode(i, left, right));
            }
        }
        return ans;
    }
};