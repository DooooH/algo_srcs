#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one, zero, two;
		zero = -1;
		one = 0;
		two = nums.size();
		
		while (one < two)
		{
			if (nums[one] == 1)
				one++;
			else if (nums[one] == 0)
			{
				zero++;
				swap(nums[one], nums[zero]);
				one++;
			}
			else
			{
				two--;
				swap(nums[one], nums[two]);
			}
		}
    }
};

int main()
{
	Solution *sol = new Solution;
	vector<int> nums = {2, 0 ,2 ,1, 1, 0};
	sol->sortColors(nums);
	// swap(nums[0], nums[1]);
	for (auto t : nums)
	{
		cout << t << " ";
	}
}