/*
API - Stack
void push(T temp)
T pop()
boolean isEmpty()
int size()
*/

//	！为了方便 Node *next; fisrt->value 等指针操作先以以下表示 暂可以理解

template <class T> 
class Stack {
public:
	void push(T temp)(){
		Node oldfirst = first;
		first = new Node();
		first.value = temp;
		first.next = oldfirst;
		
		N++;
	}
	T pop(){
		T rst = first.value;
		first = first.next;
		
		N--;
		return rst;
	}
	
	bool isEmpty(){ return N == 0; }
	int size(){ return N; }
private:
	struct Node{
		T value;
		Node next;
	}
private:
	int N;
	Node first;
	
	
	
	//	iterator()之后实现
}