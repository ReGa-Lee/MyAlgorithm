/*
API - BinarySearchST
Value get(Key)
void put(Key, Value)
*/

public class BinarySearchST<Key extends Comparable<Key>, value>{
	private Key[] keys;
	private Value[] vals;
	private int N;
	
	public BinarySearchST(int capacity){
		keys = (Key[]) new Comparable[capacity];
		vals = (Value[]) new Object[capacity];
	}
	
	public int size(){ return N; }

	public Value get(Key key){
		if(isEmpty)
			return null;
		int i = rank(key);
		if(i < N && keys[i].compareTo(key) == 0)
			return vals[i];
		else
			return null;
	}
	
	public void put(Key key, Value value){
		int i = rank(key);
		if(i < N && keys[i].compareTo(key) == 0){
			vals[i] = value;
			return;
		}
		for(int j = N; j > i; j--){
			keys[j] = key[j-1];
			vals[j] = key[j-1];
		}
		keys[i] = key;
		vals[i] = value;
		N++;
	}
	
	public int rank(Key key){
		int left = 0, right = N - 1;
		while(left <= right){
			int mid = left + (right - left) / 2;
			int cmp = key.compareTo(key[mid]);
			if(cmp < 0)
				right = mid - 1;
			else(cmp > 0)
				left = mid + 1;
			else 
				return mid;
		}
		return left;
	}	
	
	public void delete(Key key){
		//
	}
	
	public Key min(){}
	
	public Key max(){}
	
	public Key select(int k){}
	
	public Key ceiling(Key key){}
	
	public Key floor(Key key){}
	
	public Iterable<Key> keys(Key left, Key right){
		Queue<Key> q = new Queue<Key>();
		for(int i = rank(left); i < rank(right); i++)
			q.enqueue(keys[i]);
		if(contains(right))
			q.enqueue(keys[rank(right)]);
		return q;
	}
}

public class SequentialSearchST<Key, Value>{
	private Class Node{
		Key key;
		Value value;
		Node next;
		
		public Node(Key key, Value value, Node next){
			this.key = key;
			this.value = value;
			this.next = next;
		}
	}
	
	private Node first;	//	链表首结点
	
	public Value get(Key key){	//	遍历查找给定的键，返回相关联的值
		for(Node x = first; x != null; x = x.next)
			if(key.equals(x.key))
				return x.value;
		return null;
	}
	
	public void put(Key key, Value value){	//	遍历查找给定的键，更新其值，否则创建新键值对在链首
		for(Node x = first; x != null; x = x.next)
			if(key.equals(x.key)){
				x.value = value;
				return;
			}
		first = new Node(key, value, next);
	}
}