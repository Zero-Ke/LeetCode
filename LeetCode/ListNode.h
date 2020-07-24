#pragma once
//����
struct ListNode
{
public:
	ListNode(int _value)
	{
		val = _value;
		next = NULL;
	}
	/*
		��ǰ�ڵ��ֵ
	*/
	int val;
	/*
		��һ���ڵ�
	*/
	ListNode* next;
	/*
		�½����ʼ��һ���ڵ�
		value:��Ӧ��ֵ
	*/
	static ListNode * CreateNode(int value);
	/*
		�������еڼ����ڵ�����һ������
		value:�ڵ��ֵ
		index:�����ڵڼ����ڵ�
	*/
	void InsertNode(int value, int index);
	/*
		��������ɾ��������Ӧ�Ľڵ�
		Index:�ڵ�����
	*/
	void DeleteNode(int index);
	/*
		������
	*/
	int Count();
	/*
		�������ֵ����Ӧ������
	*/
	int IndexOf(int value);
	/*
		����һ������
	*/
	void  CreateListNode(int* value, int num);
	/*
	�ͷ��ڴ�
	*/
	void Dispose();
	/*
	Reverse
	*/
	ListNode* Reverse();
	/*
	�Ƿ��л�
	*/
	bool IsLoop();
};

