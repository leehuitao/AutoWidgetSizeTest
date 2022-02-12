// AlgorithmLearning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ReverseLink.h"
#include "BubbleSort.h"
#include "QuickSort.h"
int main()
{
    vector<int> popVector{ 4,2,5,7,9,1 };

    //反转链表
    ReverseLink reverseLink;
    reverseLink.printLinkNode();
    reverseLink.printReverseLinkNode();
    //冒泡排序（从小到大）
    BubbleSort();
    //快排
    cout << "source " << endl;
    for (auto it : popVector) {
        cout << it;
    }
    quickSort(0, popVector.size()-1, popVector);
    cout << endl;
    cout << "result " << endl;
    for (auto it : popVector) {
        cout << it;
    }
}

