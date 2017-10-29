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
// BinNode的插入接口 未列出的还有：succ直接后继接口
template <typename T> 
BinNodePosi(T) BinNode<T>::insertAsLC (T const& e) {
    return lc = new BinNode (e, this); //将e作为当前节点的左孩子插入二叉树
}
template <typename T> 
BinNodePosi(T) BinNode<T>::insertAsRC (T const& e) {
    return rc = new BinNode (e, this); 
}
// BinNode的中序遍历接口 其他类似
template <typename T> template <typename VST>
void BinNode<T>::travIn (VST& visit) {
    switch (rand() % 5) {
        case 1: travIn_I1(this, visit); break;
        case 2: travIn_I2(this, visit); break;
        case 3: travIn_I3(this, visit); break;
        case 4: travIn_I4(this, visit); break;
        default: travIn_R(this, visit); break;
    }
}


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
    _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc; 
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
// 先、后、中序遍历 递归
template <typename T, typename VST> //元素类型、操作器
void travPre_R (BinNodePosi(T) x, VST& visit) {
    if (!x) return;
    visit ( x->data ); //visit为函数对象，访问当前节点
    travPre_R(x->lc, visit);
    travPre_R(x->rc, visit);
}
template <typename T, typename VST> 
void travPost_R (BinNodePosi(T) x, VST& visit) {
    if (!x) return; 
    travPost_R(x->lc, visit);
    travPost_R(x->rc, visit);
    visit ( x->data );
}
template <typename T, typename VST> 
void travIn_R (BinNodePosi(T) x, VST& visit) {
    if (!x) return;
    travIn_R(x->lc, visit);
    visit ( x->data ); 
    travIn_R(x->rc, visit);
}
// 先序遍历 迭代
template <typename T, typename VST> //从当前节点出发，沿左子深入，直到无左子；沿途节点遇到后立刻访问
static void visitAlongLeftBrach (BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S) {
    while (x) {
        visit ( x->data );
        S.push(x->rc);
        x = x->lc;
    }
}
template <typename T, typename VST> 
void travPre_I2 (BinNodePosi(T) x, VST& visit) {
    Stack<BinNodePosi(T)> S;
    while (true) {
        visitAlongLeftBrach(x, visit, S);
        if (S.empty()) break; //直到栈空
        x = S.pop(); //弹出下一批起点
    }
}
// 后序遍历 迭代
template <typename T> //在以S栈顶节点为根的子树中，找最高左侧可见叶节点，并使
static void gotoHLVFL (Stack<BinNodePosi(T)>& S) { //沿途遇见节点依次入栈
    while (BinNodePosi(T) x = S.top()) { //自顶向下，反复检查当前节点
        if (HasLChild(*x)) { //尽可能向左(找的是最高左侧...)
            if (HasRChild(*x)) S.push(x->rc); //有右子 先push
            S.push(x->lc); 
        } else //实在不得已
            S.push(x->rc); //才向右
    }
    S.pop(); //返回之前，弹出栈顶的空节点(while在S.top为空时才结束)
} 
template <typename T, typename VST> 
void travPost_I (BinNodePosi(T) x, VST& visit) {
    Stack<BinNodePosi(T)> S;
    if (x) S.push(x);
    while (!S.empty()) {
        if (S.top() != x->parent) //若栈顶非当前节点之父(必是其右兄)
            gotoHLVFL(S); //在以其右兄为根的子树中，找到HLVFL(递归深入其中并依次入栈)
        x = S.pop(); visit ( x->data ); //弹出栈顶(即前一节点之后继?)，并访问之
    }
}
// 中序遍历 迭代1
template <typename T> //从当前节点出发，沿左分支不断深入，直到没有左分支的节点
static void goAlongLeftBrach (BinNodePosi(T) x, Stack<BinNodePosi(T)>& S) {
    while (x) { S.push(x); x = x->lc; } 
}
template <typename T, typename VST>
void travIn_I1 (BinNodePosi(T) x, VST& visit) {
    Stack<BinNodePosi(T)> S;
    while (true) {
        goAlongLeftBrach(x, S); //从当前节点出发，逐批入栈
        if (S.empty()) break; //直到栈空退出
        x = S.pop(); visit ( x->data ); //弹出栈顶并访问
        x = x->rc; //转入其右子
    }
}
// 中序遍历 迭代2 
template <typename T, typename VST>
void tarvIn_I2 (BinNodePosi(T) x, VST& visit) {
    Stack<BinNodePosi(T)> S;
    while (ture) {
        if (x) {
            S.push(x); //当前根节点入栈
            x = x->lc; //深入遍历左子树
        } else if (!S.empty()) {
            x = S.pop(); //尚未访问的最低祖先节点出栈
            visit ( x->data ); //访问该祖先节点
            x = x->rc; //遍历祖先的右子
        } else 
            break;
    }
}
// 中序遍历 迭代3 无栈的就地算法
template <typename T> //定位节点v的直接后继
BinNodePosi(T) BinNode<T>::succ() { 
    BinNodePosi(T) s = this; //记录后继的临时变量
    if (rc) { //若有右子，直接后继必在右子树中的最靠左(最小)的节点
        s = rc;
        while (HasLChild(*s)) s = s->lc;
    } else { //否则，直接后继是"将当前节点包含于其左子树中的最低祖先"，即
        while (IsRChild(*s)) s = s->parent; //逆向地沿父分支，不断朝左上移动
        s = s->parent; //再往上一步，即直接后继(如果存在)
    }
    return s;
}
template <typename T, typename VST> //由于v直接后继无非为 v的右子 或 v的某一祖先 可用回溯标记
void tarvIn_I3 (BinNodePosi(T) x, VST& visit) {
    bool backtrack = false; //前一步是否刚从右子树回溯(即右子为空的情况)
    while (true) {
        if (!backtrack && HasLChild(*x)) //若有左子且不是刚刚回溯
            x = x->lc; //深入左子
        else { //否则为无左子或者刚刚回溯(相当于无左子树)
            visit ( x->data );
            if (HasRChild(*x)) { //若右子非空
                x = x->rc; //深入右子
                backtrack = false; 
            } else { //右子为空
                if (!(x = x->succ())) break; //回溯(包含抵达中序意义下最后一个节点时退出返回)
                backtrack = true; 
            }
        }
    }
}
// 层次遍历
template <typename T, typename VST> 
void BinNode<T>::travLevel (VST& visit) {
    Queue<BinNodePosi(T)> Q;
    Q.enqueue(this); //根节点入队
    while (!Q.empty()) {
        BinNodePosi(T) x = Q.dequeue(); visit (x->data);
        if (HasLChild(*x)) Q.enqueue(x->lc);
        if (HasRChild(*x)) Q.enqueue(x->rc);
    }
}
