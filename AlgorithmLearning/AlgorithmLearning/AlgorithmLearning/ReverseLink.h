#pragma once
/*
	��ת����cur ��ֵroot�ĵ�ַ��
	1.����cur��һλָ��ĵ�ַ
	2.����ǰָ��ָ��pre����һλpreΪnullptr��
	3.pre��ֵcurָ��ĵ�ַ
	4.curָ�򻺴���һλ�ĵ�ַ
	5.��curΪnullptrʱ�˳�ѭ��
**/
#include "define.h"
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

