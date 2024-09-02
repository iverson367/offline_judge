#include "common.h"

namespace reference
{
#include "neighboring-bitwise-xor.cpp"
}

namespace usercode
{
	class Solution {
	public:
		bool doesValidArrayExist(vector<int>& derived) {
			return false;
		}
	};
}

void testData(std::vector<int>& dataList)
{
	auto left = reference::Solution();
	auto right = usercode::Solution();
	assert(left.doesValidArrayExist(dataList) == right.doesValidArrayExist(dataList));
}

int main()
{
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distributionCount(1, 1e5);
	std::uniform_int_distribution<int> distributionData(0, 1);

	testData(std::vector<int>{ 1, 1, 0 });
	testData(std::vector<int>{ 1, 1 });
	testData(std::vector<int>{ 1, 0 });
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