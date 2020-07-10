#include <bits/stdc++.h>
using namespace std;

void num_size(int a, int &cnt)
{
	if (a >= 10)
	{
		num_size(a / 10, cnt);
		num_size(a % 10, cnt);
	}
	else
	{
		cnt++;
		return ;
	}
}

// bool better_num(int a, int b, int first)
// {
// 	int first_size_a = 0, first_size_b = 0;
// 	int size_a = 0, size_b = 0;
// 	int div_a = 0, div_b = 0;
// 	int result_a, result_b;

// 	num_size(a, first_size_a);
// 	num_size(b, first_size_b);
// 	// if (a % 10 == 0 && b % 10 == 0)
// 	// {
// 	// 	if (first_size_a < first_size_b)
// 	// 		return true;
// 	// 	else
// 	// 		return false;
// 	// }
// 	while (1)
// 	{
// 		switch (size_a)
// 		{
// 			case 1:
// 				result_a = first;
// 				break;
// 			default:
// 				size_a = 0;
// 				num_size(a, size_a);
// 				div_a = pow(10, size_a - 1);
// 				result_a = a / div_a;
// 		}
// 		switch (size_b)
// 		{
// 			case 1:
// 				result_b = first;
// 				break;
// 			default:
// 				size_b = 0;
// 				num_size(b, size_b);
// 				div_b = pow(10, size_b - 1);
// 				result_b = b / div_b;
// 		}
// 		// cout << div_a << " " << result_a << " " << div_b << " " << result_b << "\n";
// 		if (result_a == result_b && result_a != first)
// 		{
// 			if (div_a == 0)
// 			{

// 			}
// 			if ((a = a % div_a) == 0)
// 			b = b % div_b;
// 			continue ;
// 		}
// 		else
// 		{
// 			if (result_a == first)
// 			{
// 				if(first_size_a < first_size_b)
// 					return true;
// 				else
// 					return false;
// 			}
// 			return result_a > result_b;
// 		}
// 	}
// 	return false;
// }

// bool better_num(int a, int b, int first)
// {
// 	int size_a, size_b;
// 	int div_a, div_b;
// 	int result_a, result_b;
// 	int done_a = 0, done_b = 0;
// 	int first_size_a = 0, first_size_b = 0;

// 	num_size(a, first_size_a);
// 	num_size(b, first_size_b);
// 	while (1)
// 	{
// 		size_a = 0;
// 		size_b = 0;
// 		num_size(a, size_a);
// 		div_a = a / pow(10, size_a - 1);
// 		num_size(b, size_b);
// 		div_b = b / pow(10, size_b - 1);
// 		result_a = a / div_a;
// 		if (a % div_a == 0)
// 		{
// 			if (size_a == 1)
// 			{
// 				result_a = first;
// 				done_a = 1;
// 			}
// 			// else
// 				// result_a = 0;
// 		}
// 		result_b = b / div_b;
// 		if (b % div_b == 0)
// 		{
// 			if (size_b == 1)
// 			{
// 				result_b = first;
// 				done_b = 1;
// 			}
// 			else
// 				result_b = 0;
// 		}
// 		if (result_a == result_b && result_a != first)
// 		{
// 			if (done_a) //result_a == result_b && result_a != first일때 a,b 동시에 done인 경우는 없다.
// 			{

// 			}
// 			else if (!done_a && done_b)
// 			{
// 				a = a % div_a;
// 				size_a = 0;
// 				num_size(a, size_a);
// 				div_a = a / pow(10, size_a - 1);
// 				result_a = a / div_a;
// 				if (a % div_a == 0)
// 				{
// 					if (size_a == 1)
// 						result_a = first;
// 					else
// 						result_a = 0;
// 				}
// 			}
// 			a = a % div_a;
// 			b = b % div_a;
// 			continue;
// 		}
// 		else if (result_a == result_b)
// 		{
// 			if(first_size_a < first_size_b)
// 				return true;
// 			else
// 				return false;
// 		}
// 		else
// 			return result_a > result_b;
// 	}
// }

// bool compare(int a, int b)
// {
// 	int size_a = 0, size_b = 0;
// 	int first_a, first_b;

// 	num_size(a, size_a);
// 	num_size(b, size_b);
// 	if (size_a == size_b)
// 	{
// 		return a > b;
// 	}
// 	else
// 	{
// 		first_a = a / pow(10, size_a - 1);
// 		first_b = b / pow(10, size_b - 1);
// 		if (first_a == first_b)
// 		{
// 			return better_num(a, b, first_a);
// 		}
// 		else
// 		{
// 			return first_a > first_b;
// 		}
// 	}
// }

bool compare(string a, string b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
	string temp;
	vector<string> string_nums;

	for (auto t: numbers)
	{
		string_nums.push_back(to_string(t));
	}
	sort(string_nums.begin(), string_nums.end(), compare);

	if (string_nums[0] == "0")
		return "0";
	for (auto t: string_nums)
	{
		answer = answer + t;
	}
    return answer;
}

int main()
{
	vector<int> numbers = { 3, 30, 34, 5, 9 };
	// vector<int> numbers = { 12, 121 };

	// if (argc == 3)
	// {
	// 	int a = atoi(argv[1]);
	// 	int b = atoi(argv[2]);
	// 	cout << better_num(a, b, 4);
	// }
	cout << solution(numbers) << "\n";
	return 0;
}


// 하단코드는 처음 테케는 되는 코드 

// #include <bits/stdc++.h>
// using namespace std;

// void num_size(int a, int &cnt)
// {
// 	if (a >= 10)
// 	{
// 		num_size(a / 10, cnt);
// 		num_size(a % 10, cnt);
// 	}
// 	else
// 	{
// 		cnt++;
// 		return ;
// 	}
// }

// bool better_num(int a, int b, int first)
// {
// 	int first_size_a = 0, first_size_b = 0;
// 	int size_a = 0, size_b = 0;
// 	int div_a = 0, div_b = 0;
// 	int result_a, result_b;

// 	num_size(a, first_size_a);
// 	num_size(b, first_size_b);
// 	// if (a % 10 == 0 || b % 10 == 0)
// 	// {
// 	// 	if (first_size_a < first_size_b)
// 	// 		return true;
// 	// 	else
// 	// 		return false;
// 	// }
// 	while (1)
// 	{
// 		switch (size_a)
// 		{
// 			case 1:
// 				result_a = first;
// 				break;
// 			default:
// 				size_a = 0;
// 				num_size(a, size_a);
// 				div_a = pow(10, size_a - 1);
// 				result_a = a / div_a;
// 		}
// 		switch (size_b)
// 		{
// 			case 1:
// 				result_b = first;
// 				break;
// 			default:
// 				size_b = 0;
// 				num_size(b, size_b);
// 				div_b = pow(10, size_b - 1);
// 				result_b = b / div_b;
// 		}
// 		// cout << div_a << " " << result_a << " " << div_b << " " << result_b << "\n";
// 		if (result_a == result_b)
// 		{
// 			a = a % div_a;
// 			b = b % div_b;
// 			continue ;
// 		}
// 		else
// 		{
			
// 			return result_a > result_b;
// 		}
// 	}
// 	return false;
// }

// bool compare(int a, int b)
// {
// 	int size_a = 0, size_b = 0;
// 	int first_a, first_b;

// 	num_size(a, size_a);
// 	num_size(b, size_b);
// 	if (size_a == size_b)
// 	{
// 		return a > b;
// 	}
// 	else
// 	{
// 		first_a = a / pow(10, size_a - 1);
// 		first_b = b / pow(10, size_b - 1);
// 		if (first_a == first_b)
// 		{
// 			return better_num(a, b, first_a);
// 		}
// 		else
// 		{
// 			return first_a > first_b;
// 		}
// 	}
// }

// string solution(vector<int> numbers) {
//     string answer = "";
// 	vector<string> string_nums;

// 	sort(numbers.begin(), numbers.end(), compare);
// 	for (auto t: numbers)
// 	{
// 		answer = answer + to_string(t);
// 	}
//     return answer;
// }