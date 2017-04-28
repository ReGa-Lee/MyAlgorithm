/*
API - Stack
void push(T temp)
T pop()
boolean isEmpty()
int size()
*/

import java.util.Iterator;

public class Stack<T> implements Iterable<T>{
	private class Node{
		T value;
		Node next;
	}
	private int N;
	private Node first;
	
	public void push(T temp){
		Node oldfirst = first;
		first = new Node();
		first.value = temp;
		first.next = oldfirst;
		
		N++;
	}
	public T pop(){
		T rst = first.value;
		fisrt = first.next;
		
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