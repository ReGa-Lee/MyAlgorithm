/* 先记录具体实现步骤或是注意事项在xmind里，后实现一遍，再比较一遍书上的

//BinNode (二叉树节点)
#define BinNodePosi(T) BinNode<T>* //节点位置
#define stature(p) ((p) ? (p)->height : -1) //节点高度
typedef enum { RB_RED, RB_BLACK } RBcolor; //字节颜色

T data; 
BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;
int height;
int npl; //null path length (左式堆，可用height代替)
RBcolor color;

//BinTree

int _size; BinNodePosi(T) _root;
virtual int updateHeight (BinNodePosi(T) x); //更新节点x高度
void updateHeightAbove (BinNodePosi(T) x); //更新节点x及其祖先高度
*/
#include "BinNode.h"
#include "BinTree.h"

// BinNode状态与性质判断
#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))
// 与BinNode具有特定关系的节点及指针
#define sibling(p) /*兄弟*/ \ 
    (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)
#define uncle(x) /*叔叔*/ \ 
    (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)
#define FromParentTo(x) /*来自父亲的引用*/ \ 
    (IsRoot(x) ? _root : (IsLChild(x) ? (x)->parent->lc : (x)->parent-rc))

// 高度更新
template <typename T>
int BinTree<T>::updateHeight (BinNodePosi(T) x) { //更新节点x高度
    return x->height = 1 + max(stature(x->lc), stature(x->rc)); //因树而异 可重写
}
template <typename T>
int BinTree<T>::updateHeightAbove (BinNodePosi(T) x) { //更新高度记录
    while (x) { updateHeight(x); x = x->parent; } //从x出发 遍历祖先 可优化
}
// 节点插入
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot (T const& e) {
    _size = 1; return _root = new BinNode<T> (e); //插入到根
}
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC (BinNodePosi(T) x, T const& e) {
    _size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc; //插入到x的左孩子
}
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC (BinNodePosi(T) x, T const& e) {
    _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc; //插入到x的右孩子
}
// 子树接入
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC (BinNodePosi(T) x, BinTree<T>* &S) {
    if (x->lc = S->_root) x->lc->parent = x; //接入
    _size += S->_size; updateHeightAbove(x); //更新
    S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; //释放并返回
}
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC (BinNodePosi(T) x, BinTree<T>* &S) {
    if (x->rc = S->_root) x->rc->parent = x; 
    _size += S->_size; updateHeightAbove(x); 
    S->_root = NULL; S->_size = 0; release(S); S = NULL; return x; 
}
// 子树删除
template <typename T>
int BinTree<T>::remove (BinNodePosi(T) x) {
    FromParentTo(*x) = NULL; //切断来自父节点的指针
    updateHeightAbove(x->parent); //更新
    int n = removeAt(x); _size -= n; return n; //删除子树↓ 更新并返回
} 
template <typename T>
static int removeAt (BinNodePosi(T) x) {
    if (!x) return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc); //递归释放左右子树
    release(x->data); release(x); return n; 
}
// 子树分离
template <typename T>
BinTree<T>* BinTree<T>::secede (BinNodePosi(T) x) {
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent);
    BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //新树以x为根
    S->_size = x->_size(); _size -= S->_size; return S;
}

// 遍历
