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

using pp = pair<bool, pair<int, pair<int, int>>> ;

class Solution {
private:
int ans = 0 ;
    
pp dfs(TreeNode *root)
{
    if(!root)  return { true, { INT_MAX, { INT_MIN, 0 } } } ;
    
    auto [isLeft, partL]  = dfs(root -> left) ;
    auto [isRight, partR] = dfs(root -> right) ;
    
    int minL = partL.first, maxL = partL.second.first, sumL = partL.second.second ;
    int minR = partR.first, maxR = partR.second.first, sumR = partR.second.second ;

    int val = root -> val ;
    
    if(isLeft && isRight && val > maxL && val < minR)
    {
        ans = max(ans, sumL + sumR + val) ;
        
        int minA = min(val, minL) ;
        int maxB = max(val, maxR) ;
        
        return { true, { minA, { maxB, sumL + sumR + val } } } ;
    }
    
    return { false, { INT_MIN, { INT_MAX, 0 } } } ;
}
    
public:
    int maxSumBST(TreeNode* root) 
    {
        dfs(root) ;
        
        return ans ;
};

// Time Complexity:  O(N)
// Space Complexity: O(N) [Recursive Stack Space]
