#pragma once
/*
һ�αȽ�����Ԫ�أ�������ǵ�˳�����Ͱ����ǽ���������
�߷����еĹ������ظ��ؽ���ֱ��û������Ҫ������
Ҳ����˵�������Ѿ�������ɡ�
����㷨��������������ΪԽС��Ԫ�ػᾭ�ɽ������������������еĶ��ˡ�
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
	for (int i = 0; i < popVector.size(); i++) {//���������
		for (int j = 0; j < popVector.size() - 1 - i; j++)//ѭ�����������ȶ�
		{
			if (popVector[j + 1] < popVector[j]) {//ÿ�ν��������ŵ������
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


