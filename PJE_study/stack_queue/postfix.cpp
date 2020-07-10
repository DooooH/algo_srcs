#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// int prior(char c)
// {
// 	if (c == '+' || c == '-')
// 		return 0;
// 	if (c == '*' || c == '/')
// 		return 1;
// 	return (-1);
// }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	int i = 0;
	stack<char> s;

	cin >> input;
	while (input[i] != 0)
	{
		switch (input[i])
		{
		case '(':
			s.push(input[i]);
			break;
		case ')':
			while (s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.pop(); // pop '('
			break;
		case '+':
		case '-':
			while (!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-'))
			{
				cout << s.top();
				s.pop();
			}
			s.push(input[i]);
			break;
		case '*':
		case '/':
			while (!s.empty() && (s.top() == '*' || s.top() == '/'))
			{
				cout << s.top();
				s.pop();
			}
			s.push(input[i]);
			break;
		default:
			cout << input[i];
		}
		i++;
	}

	// for (unsigned int i = 0; i < input.size(); i++)
	// {
	// 	if (isupper(input[i]))
	// 		cout << input[i];
	// 	else
	// 	{
	// 		if (input[i] == '(' || s.empty())
	// 			s.push(input[i]);
	// 		else
	// 		{
	// 			if (s.top() == '(')
	// 				s.push(input[i]);
	// 			else if (input[i] == ')')
	// 			{
	// 				while (s.top() != '(')
	// 				{
	// 					cout << s.top();
	// 					s.pop();
	// 				}
	// 				s.pop(); // pop '('
	// 			}
	// 			else
	// 			{
	// 				while(!s.empty() && (prior(s.top()) >= prior(input[i])))
	// 				{
	// 					cout << s.top();
	// 					s.pop();
	// 				}
	// 				s.push(input[i]);
	// 			}
	// 		}
	// 	}
	// }
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << "\n";
	return 0;
}