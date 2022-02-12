#include "ReverseLink.h"


ReverseLink::ReverseLink()
{
	//��ʼ������
	root = new LinkNode;
	auto temp = root;
	for (int i = 0; i < 10; i++) {
		LinkNode * child = new LinkNode;
		child->data = i + 1;
		root->next = child;
		root = child;
	}
	root = temp;
}

ReverseLink::~ReverseLink()
{
}

void ReverseLink::printLinkNode()
{
	auto temp = root;
	while (root != nullptr) {
		std::cout << "data = " << root->data<<std::endl;
		root = root->next;
	}
	root = temp;//��������
}

void ReverseLink::printReverseLinkNode()
{
	auto pre = reverse(root);
	while (pre != nullptr) {
		std::cout << "reverse data = " << pre->data << std::endl;
		pre = pre->next;
	}
}

LinkNode* ReverseLink::reverse(LinkNode* head)
{
	LinkNode* pre = nullptr;//��󷵻صĽڵ�
	LinkNode* cur = head;
	while (cur != nullptr)
	{
		LinkNode* tmp = cur->next;//������һ���ڵ�ĵ�ַ
		cur->next = pre;//ָ��ָ��ǰһλ
		pre = cur;//pre����һλ
		cur = tmp;//cur����һλ
	}
	return pre;
}
