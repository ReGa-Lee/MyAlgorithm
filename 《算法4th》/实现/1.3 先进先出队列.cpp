/*
API - Queue
void enqueue(T temp)
T dequeue()
boolean isEmpty()
int size()
*/

template <class T> 
class Queue{
public:
	void enqueue(T temp)(){
		Node oldlast = last;
		last = new Node();
		last.value = temp;
		last.next = NULL;
		
		if(isEmpty())
			first = last;
		else
			oldlast.next = last;
		
		N++;
	}
	T dequeue(){
		T rst = first.value;
		first = first.next;
		
		if(isEmpty())
			first = NULL;
		
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
	Node last;
	
	
	
	//	iterator()之后实现
}