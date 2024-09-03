#include "common.h"

namespace reference
{
#include "two-sum.cpp"
}

namespace usercode
{
	class Solution
	{
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> res;
			for (int i = 0; i < nums.size(); i++)
			{
				for (int j = i + 1; j < nums.size(); j++)
				{
					if (nums[i] + nums[j] == target)
					{
						return vector<int>{i, j};
					}
				}
			}
			return vector<int>();
		}
	};
}

void testData(std::vector<int>& dataList, int target)
{
	auto left = reference::Solution();
	auto right = usercode::Solution();
	vector<int> leftFlag, rightFlag;
	double leftTime = 0, rightTime = 0;
	{
		ElapseTimeHelper helper;
		leftFlag = left.twoSum(dataList, target);
		leftTime = helper.GetElapseMilliSeconds();
	}
	{
		ElapseTimeHelper helper;
		rightFlag = right.twoSum(dataList, target);
		rightTime = helper.GetElapseMilliSeconds();
	}

	std::cout << leftTime <<" " << rightTime << std::endl;
	assert(leftFlag == rightFlag);
}

int main()
{
	testData(std::vector<int>{2, 7, 11, 15}, 9);
	testData(std::vector<int>{3, 2, 4}, 6);
	testData(std::vector<int>{3, 3}, 6);
	{
		std::vector<int> inputList;
		int size = 10000000;
		inputList.resize(size);
		inputList[0] = inputList[size-1] = 3;
		testData(inputList, 6);
	}

	return 0;
}