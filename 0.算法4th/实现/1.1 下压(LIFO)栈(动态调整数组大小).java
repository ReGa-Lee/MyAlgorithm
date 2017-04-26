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

import java.util.Iterator;

public class ResizingArrayStack<T> implements Iterable<T> {
	private T[] arr = (T[]) new Object[1];	//	栈元素
	private int N = 0;						//	元素数量
	
	public boolean isEmpty() { return N == 0; }
	public int size() { return N; }
	private void resize(int len) {			//	将栈re移动到一个大小为len的新数组
		T[] temp = (T[]) new Object[len];
		for(int i = 0; i < N; i++)
			temp[i] = arr[i];
		arr = temp;							//	数组拷贝不仅仅拷贝N个值，还要拷贝len长度的空间
	}
	
	public void push(T temp) {				//	将元素加入栈顶
		if(N == arr.length)
			resize(arr.length * 2);
		arr[N++] = temp;					//	N++是其index
	}
	public T pop() {						//	将元素从栈顶取出
		T temp = arr[--N];					//	temp保存即将删除的元素，且--N是其index
		arr[N] = null;						//	避免对象游离即野指针
		if(N > 0 && N == a.length / 4)
			resize(arr.length / 2);
		return temp;
	}
	
	public T top() { return arr[N-1]; }
	
	//	额外的可迭代实现
	public Iterator<T> iterator() { return new ReverseArrayIterator(); }
	private class ReverseArrayIterator implements Iterator<T> {	//	嵌套类逆序迭代
		private int i = N;
		public boolean hasNext() { return i > 0; }
		public T next() { return arr[--i]; }	//	--i是其index
		public void remove() {}				//	一般不用因为remove数组可能会发生resize使迭代器失效	
	}
}