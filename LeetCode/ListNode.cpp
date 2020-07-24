#include "ZKhead.h"

ListNode* ListNode::CreateNode(int value)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
	{
		cout << "�ռ仺�治��" << endl;
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
	while (currentNode && i < index - 1)//ָ�򱻲����ڵ��ǰһ���ڵ�
	{
		currentNode = currentNode->next;//ָ���Ƶ���һ���ڵ�
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
	while (currentNode&&i < index - 1)//ָ�򱻲����ڵ��ǰһ���ڵ�
	{
		currentNode = currentNode->next;//ָ���Ƶ���һ���ڵ�
		i++;
	}
	ListNode* deleteNode = currentNode->next;
	currentNode->next = deleteNode->next;//currentNode->next=currentNode->next->next;�˴���Ϊ���ͷ��ڴ�ռ�
	free(deleteNode);
}
int ListNode::Count()
{
	int length = 0;
	ListNode*current = (ListNode*)this;
	while (current)
	{
		length++;
		current = current->next;//ָ���Ƶ���һ���ڵ�
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
		currentNode = currentNode->next;//ָ���Ƶ���һ���ڵ�

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
	while (currentNode->next)//�ٿص���p_current_next,���ڿ���ǰ��ڵ�
	{
		p_current_next = currentNode->next;
		currentNode->next = p_current_next->next;//��ָ��ָ��Ľڵ�����
		p_current_next->next = p_res->next;
		p_res->next = p_current_next;
	}
	return p_res->next;
}

bool ListNode::IsLoop()
{
	/*
	����ָ��
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
