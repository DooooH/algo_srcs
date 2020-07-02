#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode{
	int index;
	pair<int, int> location;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : index(-1), location(0,0), left(nullptr), right(nullptr) {} //location 초기화??
    TreeNode(int x) : index(x), location(0,0), left(nullptr), right(nullptr) {}
    TreeNode(int x, int y) : index(x), location(y,0), left(nullptr), right(nullptr) {}
    TreeNode(int x, int y, int z) : index(x), location(y,z), left(nullptr), right(nullptr) {}
    TreeNode(int x, int y, int z, TreeNode *left, TreeNode *right) : index(x), location(y,z), left(left), right(right) {}
};

// bool comp(pair<int, int> a, pair<int, int> b)
// {
// 	return a.first < b.first;
// }

void tree_insert(TreeNode *parent, TreeNode *child)
{
	if (child->location.first < parent->location.first)
	{
		if (parent->left != nullptr)
		{
			parent->left = child;
			return ;
		}
		else
		{
			parent = parent->left;
			tree_insert(parent, child);
		}
	}
	else
	{
		if (parent->right != nullptr)
		{
			parent->right = child;
			return ;
		}
		else
		{
			parent = parent->right;
			tree_insert(parent, child);
		}
	}
}

TreeNode *make_node(int x, int y, int z)
{
	TreeNode *ptr;
	
	if ((ptr = (TreeNode *)malloc(sizeof(TreeNode))) == 0)
		return nullptr;
	ptr->index = x;
	ptr->location.first = y;
	ptr->location.second = z;
	return ptr;
}

void preorder(TreeNode *node, vector<int> &answer)
{
	if (node != nullptr)
	{
		answer.push_back(node->index);
		preorder(node->left, answer);
		preorder(node->right, answer);
	}
}

void postorder(TreeNode *node, vector<int> &answer)
{
	if (node != nullptr)
	{
		preorder(node->left, answer);
		preorder(node->right, answer);
		answer.push_back(node->index);
	}
}
struct comparator{
	bool operator()(pair<int, int> a, pair<int, int> b) const
	{
		if (a.second != b.second)
			return a.second > b.second;
		else
			return a.first < b.first;
	}
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
	TreeNode *root;
	map<pair<int, int>, int, comparator> m;
	pair<int, int> temp;
	pair<pair<int, int>, int> m_temp;

	for (int i = 0; i < nodeinfo.size(); i++)
	{
		temp = make_pair(nodeinfo[i][0], nodeinfo[i][1]);
		m_temp = make_pair(temp, i + 1);
		m.insert(m_temp);
	}


	// for (auto t = m.begin(); t != m.end(); t++)
	// {
	// 	cout << (*t).second << " ";
	// }
	map<pair<int, int>, int, comparator>::iterator it;
	// root->index = (*it).second;
	// root->location.first = (*it).first.first;
	// root->location.second = (*it).first.second;
	// cout << root->index << " " << root->location.first << " " << root->location.second << "\n";
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it == m.begin())
			root = make_node((*it).second, (*it).first.first, (*it).first.second);
		else
			tree_insert(root, make_node((*it).second, (*it).first.first, (*it).first.second));
	}
	
	vector<int> temp_vector;
	preorder(root, temp_vector);
	answer.push_back(temp_vector);
	for (auto t = temp_vector.begin(); t != temp_vector.end(); t++)
	{
		cout << *t << " ";
	}
	cout << "\n";
	temp_vector.clear();
	postorder(root, temp_vector);
	answer.push_back(temp_vector);

	for (auto t = temp_vector.begin(); t != temp_vector.end(); t++)
	{
		cout << *t << " ";
	}
	cout << "\n";
    return answer;
}

int main()
{
	vector<vector<int>> nodeinfo = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
	solution(nodeinfo);
	return 0;
}


// vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
//     vector<vector<int>> answer;

// 	// cout << (*max(answer.begin(), answer.end(), cmp))[1] << "\n";
  
// 	for (auto iter = m.begin(); iter != m.end(); iter++)
// 	{
// 		cout << (*iter).second << " / " << (*iter).first.first << " " << (*iter).first.second << "\n";
// 	}
//     return answer;
// }
