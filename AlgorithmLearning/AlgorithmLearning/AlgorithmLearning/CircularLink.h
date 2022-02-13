#pragma once
#include "define.h"

class CircularLink
{
public:
	CircularLink();

	void printIndex(int index);

	void addNodeIndex(int index,int data);

	void deleteNodeIndex(int index);
private:
	void init() { 
		//初始化循环链表
		root = new LinkNode;
		auto temp = root;
		for (int i = 0; i < 10; i++) {
			LinkNode* child = new LinkNode;
			child->data = i + 1;
			root->next = child;
			root = child;
		}
		root->next = temp;
		root = temp;
	}
	void print(LinkNode*);
private:
	LinkNode* root;
};

CircularLink::CircularLink()
{
	init();
}

inline void CircularLink::printIndex(int index)
{
	auto temp = root;
	for (size_t i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	print(temp);
}

inline void CircularLink::addNodeIndex(int index, int data)
{
	auto temp = root;//缓存头指针
	if (index <= 0) {
		//找到最后一位
		while (temp->next != root)
		{
			temp = temp->next;
		}
	}
	else
	{
		for (size_t i = 0; i < index-1; i++)
		{
			temp = temp->next;
		}
	}
	auto next = temp->next;
	LinkNode* node = new LinkNode;
	node->data = data;
	node->next = next;
	temp->next = node;
	if (index <= 0) root = node;
	print(root);
}

inline void CircularLink::deleteNodeIndex(int index)
{
	auto temp = root;//缓存头指针
	if (index <= 0) {
		//找到最后一位
		while (temp->next != root)
		{
			temp = temp->next;
		}
		auto next = root;
		root = root->next;
		temp->next = root;
		delete next;
	}
	else
	{
		for (size_t i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
		auto next = temp->next;
		temp->next = temp->next->next;
		delete next;
		next = nullptr;
	}

	print(root);
}

inline void CircularLink::print(LinkNode* node)
{
	auto tmp = node;
	while (1)
	{
		cout << tmp->data;
		if (tmp->next == node)return;
		tmp = tmp->next;
	}
}
