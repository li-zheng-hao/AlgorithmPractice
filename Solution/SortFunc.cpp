#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	void BubbleSort(vector<int>& nums)
	{
		for(auto i=0;i!=nums.size();i++)
		{
			for(auto j=i+1;j!=nums.size();j++)
			{
				if (nums[i] > nums[j])
					swap(nums[i], nums[j]);
			}
		}
	}

	void SelectSort(vector<int>&nums)
	{
		for(auto i=0;i!=nums.size();i++)
		{
			int j = i;
			int min = i;
			while(j<nums.size())
			{
				if (nums[j] < nums[min])
					min = j;
				j++;
			}
			swap(nums[i], nums[min]);
		}
	}

	void BinarySort(vector<int>&nums,int begin,int end)
	{
		if (begin >= end)
			return;
		int mid = (begin + end) / 2;
		BinarySort(nums, begin, mid);
		BinarySort(nums, mid+1, end);

		Merge(nums, begin, mid, end);

	}

	void ShellSort(vector<int>&nums)
	{
		for (int step = nums.size() / 2; step != 1; step /= 2)
		{
			for (int i = step; i < nums.size(); i++)
			{
				int j = i;
				while (j - step >= 0 && nums[j] > nums[j - step])
				{
					swap(nums[j], nums[j - step]);
					j -= step;
				}
			}
		}
	}

	void InsertSort(vector<int>&nums)
	{
		for(int i=1;i<nums.size();i++)
		{
			int j = i;
			while (j - 1 >= 0 && nums[j] < nums[j - 1])
			{
				swap(nums[j], nums[j - 1]);
				j--;
			}
		}
	}


	void QuickSort(vector<int>& nums,int begin,int end)
	{
		if(begin<end)
		{
			int pivot = Partition(nums, begin, end - 1);
			QuickSort(nums,begin,pivot);
			QuickSort(nums, pivot+1, end);


		}
	}


	void HeapSort(vector<int>&nums)
	{
		for (int i = nums.size() / 2-1; i >= 0; i--)
			MaxHeap(nums, i, nums.size());

		for(int i=nums.size()-1;i>0;i--)
		{
			swap(nums[0], nums[i]);
			MaxHeap(nums, 0, i);
		}
	}
private:
	int Partition(vector<int>&nums,int begin,int end)
	{
		while(begin<end)
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
		for(;left<end;begin=left,left=2*left+1)
		{
			if (left + 1 < end && nums[left] < nums[left + 1])
				left++;
			if (nums[begin] >= nums[left])
				break;
			else
			{
				swap(nums[begin], nums[left]);
			}
		}
	}

	void Merge(vector<int>&nums, int begin, int mid, int end)
	{
		vector<int> temp;
		int i = begin;
		int j = mid + 1;
		while (i <= mid && j <= end)
		{
			if (nums[i] < nums[j])
				temp.push_back(nums[i++]);
			else
				temp.push_back(nums[j++]);
		}
		while (i <= mid)
		{
			temp.push_back(nums[i++]);

		}
		while (j <= mid)
		{
			temp.push_back(nums[j++]);
		}

		for (int i = 0; i < temp.size(); i++)
		{
			nums[begin + i] = temp[i];
		}
	}
};


