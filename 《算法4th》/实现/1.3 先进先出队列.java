/*
API - Queue
void enqueue(T temp)
T dequeue()
boolean isEmpty()
int size()
*/

import java.util.Iterator;

public class Queue<T> implements Iterable<T>{
	private class Node{
		T value;
		Node next;
	}
	private int N;
	private Node first;	//	指向最早添加的结点的链接 即 表头作为队尾
	private Node last;	//	指向最晚添加的结点的链接 即 表尾作为队头
	
	public void enqueue(T temp){	//	表尾入队
		Node oldlast = last;
		last = new Node();
		last.value = temp;
		last.next = null;
		
		if(isEmpty())
			first = last;
		else
			oldlast.next = last;
		
		N++;
	}
	public T dequeue(){				//	表头出队
		T rst = first.value;
		fisrt = first.next;
		
		if(isEmpty())
			last = null;
		
		N--;
		return rst;
	}
	
	public boolean isEmpty(){ return N == 0; }
	public int size(){ return N; }
	
	//	hasNext() next() remove()供用例的foreach语法使用
	public Iterator<T> iterator(){ return new ListIterator(); }
	Private class ListIterator implements Iterator<T>{
		private Node current = first;
		public boolean hasNext(){ return current != NULL }
		public T next(){
			T rst = current.value;
			current = current.next;
			return rst;
		}
		public void remove(){}
	}
}