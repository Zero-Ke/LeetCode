#pragma once
//����
class ListNode
{
public:
	/*
		��ǰ�ڵ��ֵ
	*/
	int* value;
	/*
		��һ���ڵ�
	*/
	ListNode* next;
	/*
		�½����ʼ��һ���ڵ�
		value:��Ӧ��ֵ
	*/
	ListNode * CreateNode(int value);
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

