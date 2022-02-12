#pragma once
#include "define.h"
//快速排序（从小到大） 0 ,5 ,{ 4,2,5,7,9,1 };
void quickSort(int left, int right, vector<int>& arr)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)//找到左边比基准值大的 右边比基准值小的互换
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位   将当前位置的值和较大的值的位置互换
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边 从找到的较大的那个值的左右分别递归
	quickSort(i + 1, right, arr);//递归右边
}
