// AlgorithmLearning.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ReverseLink.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "CircularLink.h"
#include "RBTree.h"
void RBTreeTest() {
    int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
    int check_insert = 0;    // "插入"动作的检测开关(0，关闭；1，打开)
    int check_remove = 0;    // "删除"动作的检测开关(0，关闭；1，打开)
    int i;
    int ilen = (sizeof(a)) / (sizeof(a[0]));
    RBTree<int>* tree = new RBTree<int>();

    cout << "== 原始数据: ";
    for (i = 0; i < ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    for (i = 0; i < ilen; i++)
    {
        tree->insert(a[i]);
        // 设置check_insert=1,测试"添加函数"
        if (check_insert)
        {
            cout << "== 添加节点: " << a[i] << endl;
            cout << "== 树的详细信息: " << endl;
            tree->print();
            cout << endl;
        }

    }

    cout << "== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;

    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();

    // 设置check_remove=1,测试"删除函数"
    if (check_remove)
    {
        for (i = 0; i < ilen; i++)
        {
            tree->remove(a[i]);

            cout << "== 删除节点: " << a[i] << endl;
            cout << "== 树的详细信息: " << endl;
            tree->print();
            cout << endl;
        }
    }

    // 销毁红黑树
    tree->destroy();
}

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

    cout << endl;
    cout << "---------------------RBTree-------------------------------" << endl;
    RBTreeTest();
}

