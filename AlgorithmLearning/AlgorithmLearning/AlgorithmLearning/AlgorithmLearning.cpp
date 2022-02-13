// AlgorithmLearning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ReverseLink.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "CircularLink.h"
int main()
{
    vector<int> popVector{ 4,2,5,7,9,1 };

    //反转链表
    cout << "-------------------ReverseLink---------------------------- " << endl;
    ReverseLink reverseLink;
    reverseLink.printLinkNode();
    reverseLink.printReverseLinkNode();
    //冒泡排序（从小到大）
    cout << "-------------------bubble---------------------------- " << endl;
    BubbleSort();
    //快排
    cout << "-------------------qucik---------------------------- " << endl;
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
    cout << "-------------------Circular---------------------------- " << endl;
    CircularLink cLink;
    cLink.printIndex(5);
    cout << endl;
    cLink.addNodeIndex(5,100);
    cout << endl;
    cLink.deleteNodeIndex(5);
    cout << endl;
    cLink.addNodeIndex(0, 999);
    cout << endl;
    cLink.deleteNodeIndex(0);
}

