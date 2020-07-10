#include <bits/stdc++.h>
using namespace std;
const int ALPA = 26;

class Tri_Node {
private:
	Tri_Node * child[ALPA];
public:
	Tri_Node() {
		for (int i = 0; i < ALPA; i++)
			child[i] = NULL;
	}

	~Tri_Node() {
		for (int i = 0; i < ALPA; i++)
			if (child[i] != NULL)
				delete child[i];
	}

	int tonum(char c) {
		return tolower(c) - 'a';
	}

	void insert(const char * words) {
		if (*words == '\0')
			return;
		
		int next = tonum(*words);

		if (child[next] == NULL){
			child[next] = new Tri_Node();
			child[next]->insert(words +  1);
		}
		child[next]->insert(words + 1);
	}

	bool find(const char* words)
	{
		int next = tonum(*words);

		if (*words == '\0')
			return true;

		if (child[next] == NULL)
			return false;

		return child[next]->find(words + 1);
	}
};

int main(void) {
	Tri_Node tri;

	tri.insert("like");

	if (tri.find("like"))
		cout << true << "\n";
	else
		cout << false << "\n";
	if (tri.find("lion"))
		cout << true << "\n";
	else
		cout << false << "\n";
	return 0;
}																																								