#include "ZKhead.h"
/*
两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
//https://leetcode-cn.com/problems/add-two-numbers
void Test002_AddTwoNumbers()
{
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(1);
	int num[7]{ 2,3,4,5,6,7,8 };
	n1->CreateListNode(num, 7);
	n2->CreateListNode(num, 7);
	addTwoNumbers(n1, n2);
	n1->Dispose();
	n2->Dispose();
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode*res;
	int i = 0; //原因：342 + 465 = 807
	int sum = 0; int sum1 = 0; int sum2 = 0;
	ListNode * currentNode = l1;
	while (l1)
	{
		sum1 += (l1->val)*(pow(10, i));//超出Int长度
		i++;
		l1 = l1->next;
	}
	i = 0;
	while (l2)
	{
		sum2 += (l2->val)*(pow(10, i));
		i++;
		l2 = l2->next;
	}
	sum = sum1 + sum2;
	int temp = sum / 10;
	res = new ListNode(sum % 10);
	ListNode *current = res;
	while (temp != 0)
	{
		current->next = new ListNode(temp % 10);
		temp = temp / 10;
		current = current->next;
	}
	return res;
}
