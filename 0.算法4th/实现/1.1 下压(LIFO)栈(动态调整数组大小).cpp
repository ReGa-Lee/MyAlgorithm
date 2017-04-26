/*
API - ResizingArrayStack 
void push(T temp)
T pop()
T top()
boolean isEmpty()
int size()
//动态性
void resize(int len)
*/

template <class T> 
class ResizingArrayStack {
public:
	ResizingArrayStack();
	~ResizingArrayStack();
	
	bool isEmpty() { return N == 0; }
	int size() { return N; }
	
	void push(T& temp) {
		if(N == arr.length)
			resize(arr.length * 2);
		arr[N++] = temp;
	}
	T& pop() {
		T *temp = arr[--N];
		arr[N] = NULL;
		if(N > 0 && N == arr.length / 4)
			resize(arr.length / 2);
		return temp;
	}
	
	T& top() {
		return arr[N-1];
	}
private:
	void resize(int len) {
		T *temp = new T[len];	
		for(int i = 0; i < N; i++)
			temp[i] == arr[i];
		arr = temp;
	}
private:
	T *arr;				//	数组
	int N;
}