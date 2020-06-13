#include <iostream>
#include <vector>
using namespace std;

void shell_insertion(vector<int> &arr, int first, int gap)
{
	int insert_data;
	int j;

	for (int i = first + gap; i < arr.size(); i = i + gap){
		insert_data = arr[i];
		for (j = i - gap; j >= first; j = j - gap){
			if (arr[j] > insert_data)
				arr[j + gap] = arr[j];
			else
			{
				break ;
			}
		}
		arr[j + gap] = insert_data;
	}
}

void shell(vector<int> &arr)
{
	int gap;

	for (gap = arr.size() / 2; gap > 0; gap = gap / 2){
		if (gap % 2 == 0)
			gap++;
		
		for (int i = 0; i < gap; i++)
		{
			shell_insertion(arr, i, gap);
		}
	}
}

int main()
{
	vector<int> arr = {3, 2 , 1, 5 , 7};
	shell(arr);
	for (auto t : arr)
	{
		cout << t << " ";
	}
	cout << "\n";
	return 0;
}
