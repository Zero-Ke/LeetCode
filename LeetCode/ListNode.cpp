#include "ZKhead.h"

ListNode* ListNode::CreateNode(int value)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
	{
		cout << "空间缓存不足" << endl;
		return head;
	}
	head->value = &value;
	head->next = NULL;
	return head;
}
void ListNode::InsertNode(int value, int index)
{
	int i = 1;
	ListNode* currentNode = this;
	while (currentNode && i < index - 1)//指向被操作节点的前一个节点
	{
		currentNode = currentNode->next;//指针移到下一个节点
		i++;
	}
	ListNode* newNode = CreateNode(value);
	newNode->next = currentNode->next;
	currentNode->next = newNode;
}
void ListNode::DeleteNode(int index)
{
	int i = 1;
	ListNode* currentNode = (ListNode*)this;
	while (currentNode&&i < index - 1)//指向被操作节点的前一个节点
	{
		currentNode = currentNode->next;//指针移到下一个节点
		i++;
	}
	ListNode* deleteNode = currentNode->next;
	currentNode->next = deleteNode->next;//currentNode->next=currentNode->next->next;此处是为了释放内存空间
	free(deleteNode);
}
int ListNode::Count()
{
	int length = 0;
	ListNode*current = (ListNode*)this;
	while (current)
	{
		length++;
		current = current->next;//指针移到下一个节点
	}
	return length;
}
int ListNode::IndexOf(int value)
{
	int i = 1;
	ListNode* currentNode = (ListNode*)this;
	while (currentNode)
	{
		if (currentNode->value == &value)
			return i;
		currentNode = currentNode->next;
		i++;
	}
	return -1;
}

void ListNode::CreateListNode(int* value, int num)
{
	ListNode* currentNode = (ListNode*)this;
	for (size_t i = 0; i < num; i++)
	{
		currentNode->next = CreateNode(value[i]);
		if (i == 0)this->next = currentNode->next;
		currentNode = currentNode->next;//指针移到下一个节点

	}
}

void ListNode::Dispose()
{
	ListNode* current = (ListNode*)this;
	ListNode* temp;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	//this->next = NULL;
}

ListNode * ListNode::Reverse()
{
	ListNode *currentNode = this;
	ListNode *p_current_next = this;
	ListNode *p_res = CreateNode(0);
	p_res->next = this;
	currentNode = this;
	//A1 A2 A3 A4 A5
	//A2 A1 A3 A4 A5
	//A3 A2 A1 A4 A5
	//A4 A3 A2 A1 A5
	//A5 A4 A3 A2 A1
	while (currentNode->next)//操控的是p_current_next,便于控制前后节点
	{
		p_current_next = currentNode->next;
		currentNode->next = p_current_next->next;//将指针指向的节点置于
		p_current_next->next = p_res->next;
		p_res->next = p_current_next;
	}
	return p_res->next;
}

bool ListNode::IsLoop()
{
	/*
	快慢指针
	*/
	ListNode * fast, *slow;
	fast = this;
	slow = this;
	while (fast&&slow)
	{
		slow = slow->next;
		if (fast->next)
		{
			fast = fast->next->next;
		}
		else
		{
			fast = fast->next;
		}
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}
