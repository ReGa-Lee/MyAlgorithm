/*
API - Bag
void push(T temp)
*/

template <class T> 
class Stack {
public:
	void push(T temp)(){
		Node oldfirst = first;
		first = new Node();
		first.value = temp;
		first.next = oldfirst;
	}
private:
	struct Node{
		T value;
		Node next;
	}
private:
	Node first;
	
	
	
	//	iterator()之后实现
}