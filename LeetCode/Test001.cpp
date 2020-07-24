#include "ZKhead.h"
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
示例 :
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回[0, 1]
*/
vector<int> twoSum0(vector<int>& nums, int target);
vector<int> twoSum1(vector<int>& nums, int target);
vector<int> twoSum2(vector<int>& nums, int target);
vector<int> twoSum3(vector<int>& nums, int target);
//两数之和//https://leetcode-cn.com/problems/two-sum/
void Test001_Two_Sum()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(15);
	nums.push_back(11);
	nums.push_back(7);
	twoSum2(nums, 9);
}
//暴力法 时间复杂度O(n2)  空间复杂度O(1)
vector<int> twoSum0(vector<int>& nums, int target)
{
	vector<int>res;
	for (size_t i = 0; i < nums.capacity(); i++)
	{
		for (size_t j = i + 1; j < nums.capacity(); j++)
		{
			if (j == i)continue;
			if (nums[i] + nums[j] == target)
			{
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
	}
}
//排序+双指针 时间复杂度O(nlogn) 空间复杂度O(n)
vector<int> twoSum1(vector<int>& nums, int target)
{
	vector<int> res;
	vector<int> temp;
	temp = nums;
	std::sort(temp.begin(), temp.end());//用最小的和最大的加和
	int count = nums.size();
	int m = 0; int n = count - 1;
	while (m < n)
	{
		if (temp[m] + temp[n] > target)
			n--;
		else if (temp[m] + temp[n] < target)
			m++;
		else
			break;
	}
	if (m < n)
	{
		for (size_t i = 0; i < temp.size(); i++)
		{
			if (temp[m] == nums[i] || temp[n] == nums[i])
				res.push_back(i);
			if (res.size() > 2)return res;
		}
	}
	return res;
}
//Hash表 一遍哈希表
vector<int> twoSum2(vector<int>& nums, int target)
{
	unordered_map<int, int> hash;
	/*
		这里是Hash表边赋值，边判断Hash[differ]是否存在Index，且Index!=i
	*/
	for (int i = 0; i < nums.size(); i++)//和Dictionary类似
	{
		int differ = target - nums[i];
		if (hash[differ] && hash[differ] != i + 1)
		{
			return{ i,hash[differ] - 1 };
		}
		hash[nums[i]] = i + 1;
	}
	return {};
}
//Hash表(低配)  两遍哈希表
vector<int> twoSum3(vector<int>& nums, int target)
{
	/*
	我的想法是先将数据全部拷贝给hashs<nums[i],i>
	int differ=target-nums[i]
	然后遍历hashs,求出hashs[differ]的Index,且Index!=i;
*/
	vector<int>	res;
	unordered_map<int, int> hashs;//<nums[i],Index>
	for (size_t i = 0; i < nums.size(); i++)
	{
		hashs[nums[i]] = i;
	}
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (hashs[target - nums[i]] && hashs[target - nums[i]] != i)
		{
			res.push_back(i);
			res.push_back(hashs[target - nums[i]]);
			return res;
		}
	}
	return res;
}