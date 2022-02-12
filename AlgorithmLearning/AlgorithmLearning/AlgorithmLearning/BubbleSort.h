#pragma once
/*
一次比较两个元素，如果它们的顺序错误就把它们交换过来。
走访数列的工作是重复地进行直到没有再需要交换，
也就是说该数列已经排序完成。
这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。
*/

#include <vector>
#include <iostream>
using namespace std;
vector<int> popVector{ 4,2,5,7,9,1 };

void BubbleSort() {
	cout << "source data " << endl;
	for (auto it : popVector)
	{
		cout << it << endl;
	}
	for (int i = 0; i < popVector.size(); i++) {//已排序个数
		for (int j = 0; j < popVector.size() - 1 - i; j++)//循环与后面的数比对
		{
			if (popVector[j + 1] < popVector[j]) {//每次将最大的数放到最后面
				int temp = popVector[j];
				popVector[j] = popVector[j + 1];
				popVector[j + 1] = temp;
			}
		}
	}
	cout << "result data " << endl;
	for (auto it : popVector)
	{
		cout << it << endl;
	}
}


