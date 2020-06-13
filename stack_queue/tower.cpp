// #include <string>
// #include <vector>
// #include <stack>

// using namespace std;

// vector<int> solution(vector<int> heights) {
//     vector<int> answer;
// 	stack<int> s;
// 	int bound;

// 	for (unsigned int i = 0; i < heights.size(); i++)
// 	{
// 		s.push(heights[i]);
// 	}
// 	bound = s.top();
// 	s.pop();
// 	while(!s.empty())
// 	{
// 		if (s.top() > bound)
// 		{
// 				bound = s.
// 		}
// 		else
// 		{
// 			s.pop();
// 			answer.push_back(0);
// 		}
// 	}
//     return answer;
// }


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
	int send;
	int pushed;

	while (!heights.empty())
	{
		pushed = 0;
		send = *(heights.end() - 1);
		heights.pop_back();
		for (int i = heights.size() - 1; i >= 0; i--)
		{
			if (heights[i] > send)
			{
				answer.push_back(i + 1);
				pushed = 1;
				break ;
			}
		}
		if (pushed == 0)
			answer.push_back(0);
	}
	reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{

}