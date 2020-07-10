#include <iostream>
#include <vector>
using namespace std;

void insertion(vector<int> &arr)
{
	int insert_data;
	int j;

	for (int i = 1; i < arr.size(); i++){
		insert_data = arr[i];
		for (j = i - 1; j >= 0; j--){
			if (arr[j] > insert_data)
				arr[j + 1] = arr[j];
			else
			{
				break ;
			}
		}
		arr[j + 1] = insert_data;
	}	
}

int main()
{
	vector<int> arr = {3, 2 , 1, 5 , 7};
	insertion(arr);
	for (auto t : arr)
	{
		cout << t << " ";
	}
	cout << "\n";
	return 0;
}
