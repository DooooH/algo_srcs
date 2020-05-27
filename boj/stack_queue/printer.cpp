#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef struct s_element{
	int priority;
	int location;
}				t_element;

struct compare
{
	bool operator()(t_element &a, t_element &b)
	{
		// if (a.priority != b.priority)
			return a.priority < b.priority;
	}
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 0;
	priority_queue<t_element, vector<t_element>, compare> pq;
	t_element temp;

	
	for (unsigned int i = 0; i < priorities.size(); i++)
	{
		temp.priority = priorities[i];
		temp.location = i;
		pq.push(temp);
	}
	while(!pq.empty())
	{
		// cnt++;
		// temp = pq.top();
		// pq.pop();
		// std::cout << temp.priority << " " << temp.location << "\n";
		// if (temp.location == location)
		// 	answer = cnt;
		
		for (unsigned int i = 0; i < priorities.size(); i++)
		{
			if (priorities[i] == pq.top().priority)
			{
				answer++;
				if (i == location)
					return answer;
				pq.pop();
			}
		}
	}
    return answer;
}

int main()
{
	vector<int> a = { 1, 1, 9, 1, 1, 1};
	int loc = 0;
	int answer =  solution(a, loc);
	std::cout << "\nanswer:" << answer << "\n";
	return 0;
}