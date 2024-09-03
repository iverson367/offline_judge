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
			std::vector<int> result;
			result.resize(derived.size());
			result[0] = 0;
			for (int i = 0; i < derived.size(); i++)
			{
				if (i < derived.size() - 1)
				{
					if (derived[i])
						result[i + 1] = 1 - result[i];
					else result[i + 1] = result[i];
				}
			}
			return derived[derived.size() - 1] == (result[derived.size() - 1] ^ result[0]);
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