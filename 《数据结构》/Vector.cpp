/* 先记录具体实现步骤或是注意事项在xmind里，后实现一遍，再比较一遍书上的

typedef int Rank;
#define DEFAULT_CAPACITY 3

int _size; int _capacity; T* _elem;
*/
#include "Vector.h"

// 默认构造
template <typename T>
Vector<T>::Vector (int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
    _elem = new T[_capacity = c]; //申请并分配空间
    for (_size = 0; _size < s; _elem[_size++] = v);
}
// 拷贝构造
template <typename T>
void Vector<T>::copyFrom (T const* A, Rank lo, Rank hi) { //cosnt* 要防止指针被改变
    _elem = new T[_capacity = (hi - lo) * 2]; //申请并分配空间
    _size = 0; //规模清零为之后依次复制做准备
    while (hi > lo)
        _elem[_size++] = A[lo++];
}
template <typename T>
Vecotr<T>::Vector (T const* A, Rank n) { copyFrom (A, 0, n); }
template <typename T>
Vecotr<T>::Vector (T const* A, Rank lo, Rank hi) { copyFrom (A, lo, hi); }
template <typename T> //向量拷贝，注意copyFrom的参数类型要求——V._elem/V._size
Vecotr<T>::Vector (Vector<T> const& V) { copyFrom (V._elem, 0, V._size); }
template <typename T>
Vecotr<T>::Vector (Vecotr<T> const& V, Rank lo, Rank hi) { copyFrom (V._elem, lo, hi); }
template <typename T> //以上向量拷贝最终都会使用到赋值运算符，默认的赋值运算符不支持向量间直接赋值
Vecotr<T>& Vecotr<T>::operator= (Vector<T> const& V) {
    if (_elem)
        delete [] _elem; //释放原有空间
    copyFrom (V._elem, 0, V.size()); //整体复制
    return *this; //返回当前对象的引用，以便链式赋值
}
// 析构
template <typename T>
Vector<T>::~Vector () { delete [] _elem; }
// 扩容
template <typename T>
void Vector<T>::expand () {
    if (_size < _capacity) 
        return; //不需要扩容
    if (_capacity < DEFAULT_CAPACITY) 
        _capacity = DEFAULT_CAPACITY; //容量未达到默认标准
    T* old_elem = _elem;
    _elem = new T[_capacity <<= 1]; //左移加倍，减少计算量
    for (int i = 0; i < _size; i++)
        _elem[i] = old_elem[i]; //拷贝原向量内容，T为基本类型或已重载赋值运算符
    delete [] old_elem; //释放原有空间
} 
// 缩容
template <typename T>
void Vector<T>::shrink () {
    if (_capacity < DEFAULT_CAPACITY << 1)
        return;
    if (_capacity < _size << 2)
        return;
    T* old_elem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = old_elem[i];
    delete [] old_elem;
}
// 循秩访问
template <typename T>
T& Vector<T>::operator[] (Rank r) const { return _elem[r]; }
// 置乱器
template <typename T>
void Vector<T>::permute (Vector<T>& V) { //此时的V是一个向量，借助重载操作符访问向量元素
    for (int i = V.size(); i > 0; i--) //从后往前
        swap (V[i-1], V[rand() % i]); //V[rand() % i]表示任意元素
}
template <typename T>
void Vecotr<T>::unsort (Rank lo, Rank hi) { //此时的V是一个数组，直接通过下标形式访问数组元素
    T* V = _elem + lo; //将子向量[lo, hi]视作另一个向量V[0, hi-lo]
    for (Rank i = hi - lo; i > 0; i--) 
        swap (V[i-1], V[rand() % i]); 
}
// 判等与比较——重载比较器以便比较对象指针
template <typename T> //less than
static bool Vector<T>::lt (T* a, T* b) { return lt (*a, *b); } 
template <typename T>
static bool Vector<T>::lt (T& a, T& b) { return a < b; }
template <typename T> //equal
static bool Vector<T>::eq (T* a, T* b) { return eq (*a, *b); }
template <typename T>
static bool Vector<T>::eq (T& a, T& b) { return a == b; }
// 无序查找
template <typename T>
Rank Vector<T>::find (T const& e, Rank lo, Rank hi) const {
    while ((lo < hi--) && (_elem[hi] != e)); //从后往前，顺序查找
    return hi; //若hi<lo则失败，否则hi即命中的秩
}
// 插入
template <typename T>
Rank Vector<T>::insert (Rank r, T const& e) {
    expand(); //如有必要，扩容
    for (int i = _size; i > r; i--)
        _elem[i] = _elem[i-1]; //i的初始值为size，故令i-1交换i(赋值)
    _elem[r] = e;
    _size++;
    return r;
}
// 删除
template <typename T>
int Vector<T>::remove (Rank lo, Rank hi) {
    if (lo == hi) //单独处理退化情况，如remove(0, 0)
        return 0;
    while (hi < _size) //将[hi, _size](将其间元素挪光)依次前移hi-lo个单元，次数即size-hi次
        _elem[lo++] = _elem[hi++]; //自前向后移动
    _size = lo; //更新规模，丢弃[lo, _size = hi](此时hi=size)区间
    shrink(); //如有必要，缩容
    return hi - lo; //返回删除元素个数
}
template <typename T>
T Vector<T>::remove (Rank r) {
    T e = _elem[r];
    remove (r, r + 1);
    return e;
}
// 唯一化 
template <typename T>
int Vector<T>::deduplicate () {
    Rank i = 1; //从_elem[1]开始
    int old_size = _size; //记录原规模
    while (i < _size)
        (find (_elem[i], 0, _size)) < 0 ? i++ : remove(i); //在其前缀中寻找雷同，没有雷同继续考察后继，否则删除雷同者
    return old_size - _size; //remove中已经对_size做了操作 
}
// 遍历
template <typename T>
void Vector<T>::traverse (void (*visit) (T&)) { //借助函数指针机制
    for (int i = 0; i < _size; i++)
        visit (_elem[i]); //遍历向量
}
template <typename T> template <typename VST> //元素类型、操作器
void Vector<T>::traverse (VST& visit) { //借助函数对象机制
    for (int i = 0; i < _size; i++)
        visit (_elem[i]); //遍历向量
}
template <typename T> struct Increase { //函数对象——递增一个T类对象
    virtual void operator() (T& e) { e++; }; //假设T可直接递增或已重载++
}
template <typename T> void increase (Vector<T>& V) { //统一递增向量中的各个元素
    V.traverse (Increase<T>()); //以Increase<T>()为基本操作进行遍历
}
// 有序性甄别
template <typename T>
int Vector<T>::disordered () const { //返回逆序对总数
    int n = 0;
    for (int i = 1; i < _size; i++)
        if (_elem[i-1] > _elem[i])
            n++;
    return n; //向量有序当且仅当n = 0
}
// 唯一化
template <typename T>
int Vector<T>::uniquify () { //低效版
    int old_size = _size;
    int i = 1; 
    while (i < _size) //自前往后，逐一比对各对相邻元素
        _elem[i-1] == _elem[i] ? remove(i) : i++; //雷同则删除后者，否则转至后一元素
    return old_size - _size;
}
template <typename T>
int Vector<T>::uniquify () { //高效版
    Rank i = 0, j = 0; //各对互异"相邻"元素的秩
    while (++j < _size) //j逐一扫描，直至末元素
        if (_elem[i] != _elem[j]) //跳过雷同者，只留意互异者
            _elem[++i] = _elem[j]; //向前移至紧邻于前者i右侧
    _size = ++i; //抛弃i之后的重复元素，处理size
    shrink();
    return j - i;
}
// 查找(区间查找接口)
template <typename T>
Rank Vector<T>::search (T const& e, Rank lo, Rank hi) { //确定不大于e的最后一个节点的秩
    return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi); //按各50%的概率随机使用bin or fib search
}   
// 二分查找A
template <typename T>
Rank Vector<T>::binSearch (T* A, T const& e, Rank lo, Rank hi) {
    while (lo < hi) { //每步迭代可能需要做2次比较判断，有3个分支
        Rank mi = (lo + hi) >> 1; //中点作为轴点
        if (e < A[mi])
            hi = mi;
        else if (e > A[mi])
            lo = mi + 1;
        else
            return mi;
    } //成功查找可以提前终止
    return -1;    
} //多个命中时，不能保证返回秩最大者，失败时，返回-1，不返回失败位置
// Fibonacci查找
#include "..\fibonacci\Fib.h"
template <typename T>
static Rank Vector<T>::fibSearch (T* A, T const& e, Rank lo, Rank hi) {
    Fib fib (hi - lo); //用O(log_phi(n = hi - lo))时间创建fib数列
    while (lo < hi) { //每步迭代可能要做2次比较判断，有3个分支
        while (hi - lo < fib.get())
            fib.prev();
        Rank mi = lo + fib.get() - 1; //确定形如fib(k) - 1的轴点
        if (e < A[mi])
            hi = mi;
        else if (e > A[mi])
            lo = mi + 1;
        else 
            return mi;
    }
    return -1;
} //多个命中时，不能保证返回秩最大者，失败时，返回-1，不返回失败位置
// 二分查找B
template <typename T>
static Rank Vector<T>::binSearch (T* A, T const& e, Rank lo, Rank hi) {
    while (lo + 1 < hi) { //每步迭代仅需1次比较判断，有2个分支，只有等到区间宽度不足2个单元时，迭代终止
        Rank mi = (lo + hi) >> 1; //中点为轴点
        (e < A[mi]) ? hi = mi : lo = mi; //比较后确定深入[lo, mi)or[mi, hi) 
    } //出口时hi = lo + 1 查找区间即 lo, lo + 1 只有元素A[lo]
    return (e == A[lo]) ? lo : -1;
} //多个命中时，不能保证返回秩最大者，失败时，返回-1，不返回失败位置
// 二分查找C
template <typename T>
static Rank Vector<T>::binSearch (T* A, T const& e, Rank lo, Rank hi) {
    while (lo < hi) { //每步迭代仅需1次比较判断，有2个分支
        Rank mi = (lo + hi) >> 1;
        (e < A[mi]) ? hi = mi : lo = mi + 1; //比较后确定深入[lo, mi)or(mi, hi)
    }
    return --lo; //循环结束时，lo为大于e的元素的最小秩，lo-1为不大于e的元素的最大秩
} //多个命中时，保证返回秩最大者，失败时，返回失败位置
// 统一入口
template <typename T>
void Vector<T>::sort (Rank lo, Rank hi) {
    switch (rand() % 5) { //随机选取排序算法
        case 1:
            bubbleSort (lo, hi);
            break;
        case 2:
            selectionSort (lo, hi);
            break;
        case 3:
            mergeSort (lo, hi);
            break;
        case 4:
            heapSort (lo, hi);
            break;
        default:
            quickSort (lo, hi);
            break;
    }
}
// 起泡排序
template <typename T>
void Vector<T>::bubbleSort (Rank lo, Rank hi) {
    while ( !bubble(lo, hi--)); //逐趟做扫描交换，直到全有序
}
template <typename T>
bool Vector<T>::bubble (Rank lo, Rank hi) {
    bool sorted = true; //整体有序标志
    while (++lo < hi) { //自左向右检查各对相邻元素
        if (_elem[lo] < _elem[lo-1]) {
            sorted = false; //未有序
            swap (_elem[lo], _elem[lo - 1]); //交换使局部有序
        }
    }
    return sorted;
}
// 归并排序
template <typename T>
void Vector<T>::mergeSort (Rank lo, Rank hi) {
    if (hi - lo < 2)
        return; //跳过单元素区间
    int mi = (hi + lo) >> 1;
    mergeSort(lo, mi);
    mergeSort(mi, hi); //递归分解
    merge(lo, mi, hi); //逐层归并
}
template <typename T>
void Vector<T>::merge (Rank lo, Rank hi) {
    T* A = _elem + lo; //这里不是申请空间，而是合并后用来保存元素的向量A[0, hi - lo] = _elem[lo, hi)
    int lb = mi - lo; T* B = new T[lb]; //申请临时空间给前子向量B[0, lb) = _elem[lo, mi)
    for (Rank i = 0; i < lb; B[i] = A[i++]); //复制前子向量
    int lc = hi - mi; T* C = _elem + mi; //后子向量C[0, lc] = _elem[mi, hi)
    for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) { //ijk作为ABC的秩，B[j]&C[k]中的小者延续到A末尾
        if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) //B还有元素 与 C没有元素 or B中元素小于C
            A[i++] = B[j++];
        if ((k < lc) && (!(j < lb) || (C[k] < B[j]))) //C还有元素 与 B没有元素 or C中元素小于B
            A[i++] = C[k++];
    }
    delete [] B;
} //归并后得到完整有序向量[lo, hi)





