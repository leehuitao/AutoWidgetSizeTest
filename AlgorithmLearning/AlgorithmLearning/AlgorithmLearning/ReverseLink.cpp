#include "ReverseLink.h"


ReverseLink::ReverseLink()
{
	//初始化链表
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
	root = temp;//重置链表
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
	LinkNode* pre = nullptr;//最后返回的节点
	LinkNode* cur = head;
	while (cur != nullptr)
	{
		LinkNode* tmp = cur->next;//缓存下一个节点的地址
		cur->next = pre;//指针指向前一位
		pre = cur;//pre后移一位
		cur = tmp;//cur后移一位
	}
	return pre;
}
