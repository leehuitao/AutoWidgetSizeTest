#pragma once
/*
	��ת����cur ��ֵroot�ĵ�ַ��
	1.����cur��һλָ��ĵ�ַ
	2.����ǰָ��ָ��pre����һλpreΪnullptr��
	3.pre��ֵcurָ��ĵ�ַ
	4.curָ�򻺴���һλ�ĵ�ַ
	5.��curΪnullptrʱ�˳�ѭ��
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

