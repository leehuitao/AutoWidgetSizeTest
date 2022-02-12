#pragma once
#include "define.h"
//�������򣨴�С���� 0 ,5 ,{ 4,2,5,7,9,1 };
void quickSort(int left, int right, vector<int>& arr)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //ȡ����ߵ���Ϊ��׼��
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)//�ҵ���߱Ȼ�׼ֵ��� �ұ߱Ȼ�׼ֵС�Ļ���
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//��׼����λ   ����ǰλ�õ�ֵ�ͽϴ��ֵ��λ�û���
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//�ݹ���� ���ҵ��Ľϴ���Ǹ�ֵ�����ҷֱ�ݹ�
	quickSort(i + 1, right, arr);//�ݹ��ұ�
}
