#include "common.h"

namespace reference
{
#include "add-two-numbers.cpp"
}

namespace usercode
{
	class Solution
	{
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* leftCurrent = l1;
			ListNode* rightCurrent = l2;
			ListNode* head = nullptr;
			ListNode* headCurrent = nullptr;
			int sum = 0;
			while (leftCurrent != nullptr || rightCurrent != nullptr)
			{
				if (leftCurrent != nullptr)
				{
					sum += leftCurrent->val;
					leftCurrent = leftCurrent->next;
				}
				if (rightCurrent != nullptr)
				{
					sum += rightCurrent->val;
					rightCurrent = rightCurrent->next;
				}
				int v = sum > 9 ? sum - 10 : sum;
				sum = sum > 9 ? 1 : 0;
				auto temp = new ListNode(v);
				if (head == nullptr)
				{
					head = headCurrent = temp;
				}
				else
				{
					headCurrent->next = temp;
					headCurrent = temp;
				}
			}
			if (sum != 0)
			{
				auto temp = new ListNode(1);
				headCurrent->next = temp;
				headCurrent = temp;
			}
			return head;
		}
	};
}

void testData(ListNode* l1, ListNode* l2)
{
	auto left = reference::Solution();
	auto right = usercode::Solution();
	ListNode* leftFlag;
	ListNode* rightFlag;
	double leftTime = 0, rightTime = 0;
	{
		ElapseTimeHelper helper;
		leftFlag = left.addTwoNumbers(l1, l2);
		leftTime = helper.GetElapseMilliSeconds();
	}
	{
		ElapseTimeHelper helper;
		rightFlag = right.addTwoNumbers(l1, l2);
		rightTime = helper.GetElapseMilliSeconds();
	}

	std::cout << leftTime << " " << rightTime << std::endl;
	assert(isEqual(leftFlag, rightFlag));
}

ListNode* generateExampleData(std::vector<int> list)
{
	ListNode* head = nullptr;
	ListNode* current = nullptr;
	for (auto v : list)
	{
		if (head == nullptr)
		{
			head = new ListNode;
			head->val = v;
			head->next = nullptr;
			current = head;
		}
		else
		{
			auto temp = new ListNode;
			temp->val = v;
			temp->next = nullptr;
			current->next = temp;
			current = temp;
		}
	}
	return head;
}

ListNode* generateRandomData()
{
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distributionCount(1, 100);
	std::uniform_int_distribution<int> distributionAll(0, 9);
	std::uniform_int_distribution<int> distributionNonZero(1, 9);

	auto count = distributionCount(generator);
	vector<int> list;
	list.resize(count);
	for (int j = 0; j < count; j++)
	{
		int v = 0;
		if (j == 0 && count != 1)
			v = distributionAll(generator);
		else v = distributionNonZero(generator);
		list[j] = v;
	}
	return generateExampleData(list);
}

int main()
{
	testData(generateExampleData({ 2, 4, 3 }), generateExampleData({ 5, 6,4 }));
	testData(generateExampleData({ 0 }), generateExampleData({ 0 }));
	testData(generateExampleData({ 9,9,9,9,9,9,9 }), generateExampleData({ 9,9,9,9 }));
	for (int i = 0; i < 100; i++)
	{
		testData(generateRandomData(), generateRandomData());
	}

	return 0;
}