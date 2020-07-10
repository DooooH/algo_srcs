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
#include <stack>
using namespace std;

//  struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

// 후위순회 --> 오름차순 : 왼 -> 오 -> 부모
class Solution {
public:
    void inorder(TreeNode* node, int &k, int &value)
    {
        if (node)
        {
            inorder(node->left, k, value);
            if (k == 1)
            {
                value = node->val;
            }
            k--;
            inorder(node->right, k, value);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int value;
        inorder(root, k, value);
        return value;
    }
};