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
	ListNode *n1 = (ListNode *)malloc(sizeof(ListNode));
	ListNode *n2 = (ListNode *)malloc(sizeof(ListNode));
	int num1[3]{ 2,4,6 };
	int num2[3]{ 5,6,4 };
	n1->InsertNode(2, 1);
	n1->InsertNode(4, 2);
	n1->InsertNode(5, 3);
	n2->InsertNode(5, 1);
	n2->InsertNode(6, 2);
	n2->InsertNode(4, 3);
	//n1.CreateListNode(num1, 3);
	//n2.CreateListNode(num2,3);
	delete(n1);
	delete(n2);
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	return nullptr;
}
