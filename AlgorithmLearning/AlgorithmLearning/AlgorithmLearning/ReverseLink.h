#pragma once
/*
	反转链表（cur 赋值root的地址）
	1.缓存cur下一位指针的地址
	2.将当前指针指向pre（第一位pre为nullptr）
	3.pre赋值cur指针的地址
	4.cur指向缓存下一位的地址
	5.当cur为nullptr时退出循环
**/
#include <iostream>

using namespace std;

struct LinkNode
{
	int data = 0;
	LinkNode* next = nullptr;
};


class ReverseLink
{
public:
	ReverseLink();
	~ReverseLink();


	void printLinkNode();

	void printReverseLinkNode();
private:
	LinkNode* root;

private:
	LinkNode* reverse(LinkNode*);
};

