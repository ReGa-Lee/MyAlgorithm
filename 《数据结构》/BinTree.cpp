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
*/

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
// 二叉树节点的插入
template <typename T> 
BinNodePosi(T) BinNode<T>::insertAsLC (T const& e) {
    return lc = new BinNode (e, this);
}
template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC (T const& e) {
    return rc = new BinNode (e, this);
}

//