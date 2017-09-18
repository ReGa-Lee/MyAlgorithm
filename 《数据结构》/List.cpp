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
template <typename T> //在有序列表节点p的n个前驱中，查找不大于e的最后者
ListNodePosi(T) List<T>::search (T const& e, int n, ListNodePosi(T) p) {
    while (0 < n--) 
        if (((p->pred)->data) <= e) //直到命中、数值越界或者范围越界
            break;
    return p; //返回的是区间左边界的前驱，可能失败也可能成功
}
// 统一入口
template <typename T> //列表区间排序
void List<T>::sort (ListNodePosi(T) p, int n) {
    switch (rand() % 3) {
        case 1:
            insertionSort(p, n); //插入排序
            break;
        case 2:
            selectionSort(p, n); //选择排序
            break;
        default:
            mergeSort(p, n);
            break;
    }
}
// 插入排序
template <typename T> //对起始于位置p的n个元素排序
void List<T>::insertionSort (ListNodePosi(T) p, int n) {
    for (int r = 0; r < n; r++) { //逐一为各节点
        insertA (search (p->data, r, p), p->data); //查找适当的位置插入
        p = p->succ;
        remove(p->pred); //转入下一节点并删除上个节点
    }
}
// 选择排序
template <typename T> 
void List<T>::selectionSort (ListNodePosi(T) p, int n) {
    ListNodePosi(T) head = p->pred;
    ListNodePosi(T) tail = p;
    for (int i = 0; i < n; i++) 
        tail = tail->succ; //至此，待排区间为(head, tail)
    while (1 < n) { //至少还剩2个节点之前，在待排序区间内
        ListNodePosi(T) max = selectMax (head->succ, n); //找出max
        insertB (tail, remove(max)); //将其插入tail前
        tail = tail->pred;
        n--;
    }
}
template <typename T> 
ListNodePosi(T) List<T>::selectMax (ListNodePosi(T) p, int n) {
    ListNodePosi(T) max = p; //暂定
    for (ListNodePosi(T) cur = p; 1 < n; n--) //从首节点p出发，后续节点逐一与max比较
        if (!lt ((cur = cur->succ)->data, max->data) //当前元素不小于max，则
            max = cur; //更新max
    return max; 
}
// 归并排序
template <typename T> //列表的归并排序算法：对起始于位置p的n个元素排序
void List<T>::mergeSort (ListNodePosi(T) & p, int n) {
    if (n < 2)
        return;
    int m = n >> 1; //中点为界
    ListNodePosi(T) q = p;
    for (int i = 0; i < m; i++)
        q = q->succ; //均分列表
    mergeSort (p, m);
    mergeSort (q, n - m); //前后子列表分别递归
    merge (p, m, *this, q, n - m); //归并
} //注意：排序后，p依然指向归并后区间的新起点
template <typename T> //有序列表的归并：当前列表中自p起的n个元素，与列表L中自q起的m个元素归并
void List<T>::merge (ListNodePosi(T) & p, int n, List<T>& L, ListNodePosi(T) q, int m) {
    ListNodePosi(T) pp = p->pred; //借助前驱，可以是header，以便返回
    while (0 < m) { //在q尚未移出区间之前
        if ((0 < n) && (p->data <= q->data)) //若p仍在区间内且v(p) <= v(q)，则
            if (q == (p = p->succ)) { //p归入合并的列表，并替换为其直接后继
                break;
                n--;
            }
        else { //若p已经超出右界或v(q) < v(p)，则
            insertB (p, L.remove((q = q->succ)->pred)); //将q转移到p之前
            m--;
        }
    }
    p = pp->succ; //确定归并后区间的新起点
}

