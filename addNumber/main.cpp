
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode dummy;
		ListNode *current = &dummy;
		int carry = 0;
		while (l1 || l2)
		{
			if (l1)
			{
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				carry += l2->val;
				l2 = l2->next;
			}
			current->next = new ListNode(carry % 10);
			current = current->next;
			carry /= 10;
		}
		if (carry)
			current->next = new ListNode(carry % 10);
		return dummy.next;
	}
};

int main()
{
	ListNode l1Third(3);
	ListNode l1Second(4, &l1Third);
	ListNode l1(2, &l1Second);

	ListNode l2Third(4);
	ListNode l2Second(6, &l2Third);
	ListNode l2(5, &l2Second);

	Solution solution;
	ListNode *result = solution.addTwoNumbers(&l1, &l2);

	for (ListNode *node = result; node; node = node->next)
	{
		std::cout << node->val;
		if (node->next)
			std::cout << " -> ";
	}
	std::cout << std::endl;

	while (result)
	{
		ListNode *next = result->next;
		delete result;
		result = next;
	}

	return 0;
}
