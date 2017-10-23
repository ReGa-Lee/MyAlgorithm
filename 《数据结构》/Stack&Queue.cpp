/* 先记录具体实现步骤或是注意事项在xmind里，后实现一遍，再比较一遍书上的
*/
// Stack模板类
#include "Vector" //以Vector为基类
template <typename T>
class Stack: public Vector<T> {
    void push (T const& e) {
        insert (size(), e); //入栈（等效于将新元素作为向量末元素插入
    }
    T pop () {
        return remove (size() - 1); //出栈（等效于删除向量末元素
    }
    T& top () {
        return (*this)[size() - 1]; //取栈顶（向量末元素
    }
}



// Queue模板类
#include "List" //以List为基类
template <typename T>
class Queue: public List<T> {
    void enqueue (T const& e) {
        insertAsLast (e); //入队（尾部插入
    }
    T dequeue () {
        return remove (first()); //出队（首部删除
    }
    T& front () {
        return first()->data; //队首
    }
}