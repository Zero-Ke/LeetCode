#pragma once
//链表
class ListNode
{
public:
	/*
		当前节点的值
	*/
	int* value;
	/*
		下一个节点
	*/
	ListNode* next;
	/*
		新建或初始化一个节点
		value:对应的值
	*/
	ListNode * CreateNode(int value);
	/*
		向链表中第几个节点后插入一条数据
		value:节点的值
		index:插入在第几个节点
	*/
	void InsertNode(int value, int index);
	/*
		从链表中删除索引对应的节点
		Index:节点索引
	*/
	void DeleteNode(int index);
	/*
		链表长度
	*/
	int Count();
	/*
		获得链表值所对应的索引
	*/
	int IndexOf(int value);
	/*
		生成一个链表
	*/
	void  CreateListNode(int* value, int num);
	/*
	释放内存
	*/
	void Dispose();
	/*
	Reverse
	*/
	ListNode* Reverse();
	/*
	是否有环
	*/
	bool IsLoop();
};

