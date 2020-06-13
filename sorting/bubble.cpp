#include <iostream>
#include <vector>
using namespace std;

void bubble(vector<int> &arr)
{
	for (int i = 0; i < arr.size() - 1; i++){
		for (int j = 0; j < (arr.size() - i) - 1; j++){
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}	
}

int main()
{
	vector<int> arr = {3, 2 , 1, 5 , 7};
	bubble(arr);
	for (auto t : arr)
	{
		cout << t << " ";
	}
	cout << "\n";
	return 0;
}