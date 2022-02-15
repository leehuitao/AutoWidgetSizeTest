#pragma once

enum RBTColor { RED, BLACK };

template <class T>
class RBTNode {
public:
    RBTColor color;    // ��ɫ
    T key;            // �ؼ���(��ֵ)
    RBTNode* left;    // ����
    RBTNode* right;    // �Һ���
    RBTNode* parent; // �����

    RBTNode(T value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
        key(value), color(c), parent(), left(l), right(r) {}
};

template <class T>
class RBTree {
private:
    RBTNode<T>* mRoot;    // �����

public:
    RBTree();
    ~RBTree();

    // ǰ�����"�����"
    void preOrder();
    // �������"�����"
    void inOrder();
    // �������"�����"
    void postOrder();

    // (�ݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
    RBTNode<T>* search(T key);
    // (�ǵݹ�ʵ��)����"�����"�м�ֵΪkey�Ľڵ�
    RBTNode<T>* iterativeSearch(T key);

    // ������С��㣺������С���ļ�ֵ��
    T minimum();
    // ��������㣺���������ļ�ֵ��
    T maximum();

    // �ҽ��(x)�ĺ�̽�㡣��������"�����������ֵ���ڸý��"��"��С���"��
    RBTNode<T>* successor(RBTNode<T>* x);
    // �ҽ��(x)��ǰ����㡣��������"�����������ֵС�ڸý��"��"�����"��
    RBTNode<T>* predecessor(RBTNode<T>* x);

    // �����(keyΪ�ڵ��ֵ)���뵽�������
    void insert(T key);

    // ɾ�����(keyΪ�ڵ��ֵ)
    void remove(T key);

    // ���ٺ����
    void destroy();

    // ��ӡ�����
    void print();
private:
    // ǰ�����"�����"
    void preOrder(RBTNode<T>* tree) const;
    // �������"�����"
    void inOrder(RBTNode<T>* tree) const;
    // �������"�����"
    void postOrder(RBTNode<T>* tree) const;

    // (�ݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
    RBTNode<T>* search(RBTNode<T>* x, T key) const;
    // (�ǵݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
    RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

    // ������С��㣺����treeΪ�����ĺ��������С��㡣
    RBTNode<T>* minimum(RBTNode<T>* tree);
    // ��������㣺����treeΪ�����ĺ����������㡣
    RBTNode<T>* maximum(RBTNode<T>* tree);

    // ����
    void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);
    // ����
    void rightRotate(RBTNode<T>*& root, RBTNode<T>* y);
    // ���뺯��
    void insert(RBTNode<T>*& root, RBTNode<T>* node);
    // ������������
    void insertFixUp(RBTNode<T>*& root, RBTNode<T>* node);
    // ɾ������
    void remove(RBTNode<T>*& root, RBTNode<T>* node);
    // ɾ����������
    void removeFixUp(RBTNode<T>*& root, RBTNode<T>* node, RBTNode<T>* parent);

    // ���ٺ����
    void destroy(RBTNode<T>*& tree);

    // ��ӡ�����
    void print(RBTNode<T>* tree, T key, int direction);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};