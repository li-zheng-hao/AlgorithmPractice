// Solution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include "SortFunc.cpp"
using namespace std;


int main()
{
	vector<int> nums = { 1,4,7,2,5,8,3,6,9 };
	Solution s;
	s.BinarySort(nums, 0, nums.size()-1);

	for (auto i : nums)
	{
		cout << i << " ";
	}
}