/*
API - Bag
void add(T temp)
boolean isEmpty()
int size()
*/

import java.util.Iterator;

public class Bag<T> implements Iterable<T>{
	private class Node{
		T value;
		Node next;
	}
	private Node first;
	
	public void add(T temp){
		Node oldfirst = first;
		first = new Node();
		first.value = temp;
		first.next = oldfirst;
	}
	
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