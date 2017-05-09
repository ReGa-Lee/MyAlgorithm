/*
API - SequentialSearchST
Value get(Key)
void put(Key, Value)
*/

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