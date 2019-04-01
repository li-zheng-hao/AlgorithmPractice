// Solution.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void BubbleSort(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
				if (nums[i] > nums[j])
					swap(nums[i], nums[j]);
		}
	}

	void InsertSort(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			int j = i;
			while (j - 1 >= 0)
			{
				if (nums[j - 1] > nums[j])
					swap(nums[j - 1], nums[j]);
				j--;
			}
		}
	}

	void SelectSort(vector<int>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			int min = i;
			int j = i;
			while (j < nums.size())
			{
				if (nums[j] < nums[min])
				{
					min = j;
				}
				j++;
			}
			swap(nums[min], nums[i]);
		}
	}

	void QuickSort(vector<int>& nums, int begin, int end)
	{
		if (begin<end)
		{
			int pivot = Partition(nums, begin, end - 1);
			QuickSort(nums, begin, pivot);
			QuickSort(nums, pivot + 1, end);
		}
	}

	void ShellSort(vector<int>&nums)
	{
		for(int gap=nums.size()/2;gap>1;gap/=2)
		{
			int start = gap;
			while(start<nums.size())
			{
				int index = start;
				while(index-gap>=0)
				{
					if (nums[index - gap] > nums[index])
						swap(nums[index - gap], nums[index]);
					index -= gap;
				}
				start++;
			}
		}
	}
	
	void HeadpSort(vector<int>&nums)
	{
		for(int i=nums.size()/2;i>=0;i--)
		{
			MaxHeap(nums, i, nums.size());
		}
		for (int i=nums.size()-1;i>=0;i--)
		{
			swap(nums[i], nums[0]);
			MaxHeap(nums, 0, i);
		}
	}

	void BinarySort(vector<int>&nums,int begin,int end)
	{
		if (!(begin < end-1))
			return;
		int mid = (end + begin) / 2;
		BinarySort(nums, begin, mid);
		BinarySort(nums, mid, end);
		Merge(nums, begin, mid, end);
	}
private:
	int Partition(vector<int>& nums, int begin, int end)
	{
		while (begin < end)
		{
			while (begin < end && nums[begin] < nums[end]) end--;
			swap(nums[begin], nums[end]);
			while (begin < end && nums[begin] < nums[end]) begin++;
			swap(nums[begin], nums[end]);
		}
		return begin;
	}

	void MaxHeap(vector<int>&nums,int begin,int end)
	{
		int left = begin * 2 + 1;
		for(;left<end;begin=left,left=left*2+1)
		{
			if (left+1<end&&nums[left]<nums[left+1])
			{
				left++;
			}
			if (nums[begin] > nums[left])
				break;
			else
			{
				swap(nums[begin], nums[left]);
			}
		}
	}

	void Merge(vector<int>&nums,int begin,int mid,int end)
	{
		vector<int> temp;
		int begin1 = begin;
		int begin2 = mid;
		while(begin1<mid&&begin2<end)
		{
			if (nums[begin1] > nums[begin2])
				temp.push_back(nums[begin2++]);
			else
				temp.push_back(nums[begin1++]);
		}
		while(begin1<mid)
		{
			temp.push_back(nums[begin1++]);
		}
		while(begin2<mid)
		{
			temp.push_back(nums[begin2++]);
		}

		for(int i=0;i<temp.size();i++)
		{
			nums[begin + i] = temp[i];
		}
	}
};


int main()
{
	vector<int> nums = {1, 4, 7, 2, 5, 8, 3, 6, 9};
	Solution s;
	s.BinarySort(nums,0,nums.size());
	// s.HeadpSort(nums);
	for (auto i : nums)
	{
		cout << i << " ";
	}
}
