#include <bits/stdc++.h>
using namespace std;
stack<char> s_valid;

int divide(string s) //u가 오른쪽에 생기는 경우가 없나?
{
	int i = 0;
	int open = 0;
	int close = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
			close++;
		i++;
		if (open != 0 && open == close) // 같은 거 이후 한칸 더가서 리턴 (사이즈를 리턴하는 셈)
			return i;
	}
	return i;
}

bool is_valid(string s)
{
	for (auto t: s)
	{
		if (t == '(')
			s_valid.push('(');
		else if (t == ')')
		{
			if (!s_valid.empty())
				s_valid.pop();
			else
				return false;
		}
	}
	if (s_valid.empty())
		return true;
	return false;
}

void reverse(string &s)
{
	for (auto &t : s)
	{
		if (t == '(')
			t = ')';
		else if (t == ')')
			t = '(';
	}
}

string convert(string p)
{
	string u, v;
	string temp = "";
	int div_idx;

	if (p.compare("") == 0)
		return p;
	div_idx = divide(p);
	u = p.substr(0, div_idx);
	// cout << u << "\n";
	v = p.substr(div_idx, p.size());
	// cout << v << "\n";
	if (is_valid(u))
		return u + convert(v);
	else
	{
		temp.push_back('(');
		temp = temp + convert(v);
		temp.push_back(')');
		u = u.substr(1, u.size());
		u.pop_back();
		reverse(u);
		temp = temp + u;
		return temp;
	}
}

string solution(string p) {
    string answer = "";
	answer = convert(p);
    return answer;
}

int main()
{
	cout << solution("()))((()") << "\n";
	return 0;
}