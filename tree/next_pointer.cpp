#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

queue<pair<int, Node *>> q;

class Solution {
public:
    void    BFS(Node* &root, int level)
    {
        Node* temp = NULL;

        if (root != NULL)
        {
            if (root->left != NULL)
                q.push(make_pair(level + 1, root->left));
            if (root->right != NULL)
                q.push(make_pair(level + 1, root->right));
            if (q.front().first != level)
            {
                root->next = NULL;
                level += 1;
            }
            else
                root->next = q.front().second;
            if (!q.empty())
            {
                temp = q.front().second;
                q.pop();
                BFS(temp, level);
            }
        }
    }
    Node* connect(Node* root) {
        BFS(root, 0);
        return root;
    }
};

// int main()
// {
//     Solution *sol = new Solution();

//     sol->connect(root);
//     return 0;
// }