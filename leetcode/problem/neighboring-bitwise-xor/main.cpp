#include "common.h"

namespace reference
{
#include "neighboring-bitwise-xor.cpp"
}

namespace usercode
{
	class Solution
	{
	public:
		bool doesValidArrayExist(vector<int> &derived)
		{
			return false;//to do
		}
	};
}

void testData(std::vector<int> &dataList)
{
	auto left = reference::Solution();
	auto right = usercode::Solution();
	bool leftFlag = false, rightFlag = false; 
	double leftTime = 0, rightTime = 0;
	{
		ElapseTimeHelper helper;
		leftFlag = left.doesValidArrayExist(dataList);
		leftTime = helper.GetElapseMilliSeconds();
	}
	{
		ElapseTimeHelper helper;
		rightFlag = right.doesValidArrayExist(dataList);
		rightTime = helper.GetElapseMilliSeconds();
	}

	assert(leftFlag == rightFlag);
}

int main()
{
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distributionCount(1, 1e5);
	std::uniform_int_distribution<int> distributionData(0, 1);

	testData(std::vector<int>{1, 1, 0});
	testData(std::vector<int>{1, 1});
	testData(std::vector<int>{1, 0});
	for (int i = 0; i < 5; i++)
	{
		std::vector<int> inputList;
		inputList.resize(distributionCount(generator));
		for (int j = 0; j < inputList.size(); j++)
			inputList[j] = distributionData(generator);
		testData(inputList);
	}

	return 0;
}