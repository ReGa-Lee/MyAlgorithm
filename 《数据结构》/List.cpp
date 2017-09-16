/* 先记录具体实现步骤或是注意事项在xmind里，后实现一遍，再比较一遍书上的

//ListNode
typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

T data; ListNodePosi(T) pred; ListNodePosi(T) succ; 
//List
int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;
*/
#include "List.h"

// 默认构造——统一初始化
template <typename T>
void List<T>::init () {
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->succ = trailer;
    header->pred = NULL;
    trailer->pred = header;
    trailer->succ = NULL:
    _size = 0;
}
// 秩到位置的转换
template <typename T> //重载下标操作符，通过秩直接访问列表节点
T& List<T>::operator[] (Rank r) {
    ListNodePosi(T) p = first(); //首节点出发
    while (0 < r--)
        p = p->succ; //顺数r个节点
    return p->date;
}
// 查找
template <typename T> //无序列表节点p(可能是trailer)的n个前驱中查找等于e的最后一个
ListNodePosi(T) List<T>::find (T const& e, int n, ListNodePosi(T) p) {
    while (0 < n--) //从右往左
        if (e == (p->pred)->data)
            return p;
    return NULL;
}
// 插入
template <typename T> 
ListNodePosi(T) List<T>::insertAsFirst (T const& e) {
    _size++;
    return header->insertAsSucc(e); //把e插入头结点后
}
template <typename T>
ListNodePosi(T) List<T>::insertAsLast (T const& e) {
    _size++;
    return trailer->insertAsPred(e); //把e插入尾节点前
}
template <typename T>
ListNodePosi(T) List<T>::insertA (ListNodePosi(T) p, T cosnt& e) {
    _size++;
    return p->insertAsSucc(e); //把e插入p节点后
}
template <typename T>
ListNodePosi(T) List<T>::insertB (ListNodePosi(T) p, T cosnt& e) {
    _size++;
    return p->insertAsPred(e); //把e插入p节点前
}
template <typename T> //前插入
ListNodePosi(T) List<T>::insertAsPred (T const& e) {
    ListNodePosi(T) x = new ListNode (e, pred, this);
    pred->succ = x; //等效this.pred->succ
    pred = x; //等效this.pred
    return x;
}
template <typename T> //后插入
ListNodePosi(T) List<T>::insertAsSucc (T cosnt& e) {
    ListNodePosi(T) x = new ListNode (e, this, succ);
    succ->pred = x; //等效this.succ->pred
    succ = x; //等效this.succ
    return x;
}
// 拷贝构造
template <typename T>
void List<T>::copyNodes (ListNodePosi(T) p, int n) {
    init();
    while (n--) {
        insertAsLast (p->data);
        p = p->succ;
    }
}
template <typename T> //给定p n的区间拷贝接口
List<T>::List (ListNodePOsi(T) p, int n) {
    copyNodes (p, n);
}
template <typename T> //整体拷贝接口
List<T>::List (List<T> const& L) {
    copyNodes (L.first(), L._size);
}
template <typename T> //给定下标r的区间拷贝接口
List<T>::List (List<T> const& L, int r, int n) {
    copyNodes (L[r], n);
}
// 删除
template <typename T>
T List<T>::remove (ListNodePosi(T) p) {
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}
// 析构
template <typename T>
List<T>::~List () {
    clear(); //清空
    delete header;
    delete trailer;
}
template <typename T>
int List<T>::clear () {
    int old_size = _size;
    while (0 < _size) 
        remove (header->succ); //反复删除首节点，直到列表为空
    return old_size;
}
// 唯一化
template <typename T>
int List<T>::deduplicate () {
    if (_size < 2)
        return 0;
    int old_size = _size;
    ListNodeposi(T) p = header; //p为各区段起点
    Rank r = 0; //r为p的r个前驱
    while (trailer != (p = p->succ)) { //p从首节点开始
        ListNodePosi(T) q = find (p->data, r, p); //查找是从p开始的r个前驱
        q ? remove(q) : r++; //q作为查找的结果，也防止了直接删除p的危险
    }    
    return old_size - _size;
}
// 遍历
template <typename T>
void List<T>::traverse (void (*visit) (T&)) {
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
        visit (p->data);
}
template <typename T> template <typename VST>
void List<T>::traverse (VST& visit) {
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
        visit (p->data);
}
// 有序唯一化
template <typename T>
int List<T>::uniquify () {
    if (_size < 2) 
        return 0;
    int old_size = _size;
    ListNodePosi(T) p = first(); //p为各区段起点
    ListNodePosi(T) q; //q为p的后继
    while (trailer != (q = p->succ)) {
        if (p->data != q->data) //反复考察紧邻节点对 p q
            p = q; //互异则转入下个区段
        else 
            remove (q); //否则删除
    }
    return old_size - _size;
}
// 有序查找
template <typename T>





template <typename T>

