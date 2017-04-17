/*
	��ջ�໥ʵ�� ��Ҫ���ܾ�����ͳ� ����ʵ�ֳ�
*/
class MyQueue{
private:
	stack<int> stk;
public:
	void enqueue(int x){
		stk.push(x);
	}
	
	//	�ݹ鵯�� ���ջ�ǿ� ��ѹ��	
	bool dequeue(int& x){
		if(stk.empty())
			return false;
		
		int temp = skt.top();
		if(!dequeue(x))
			x = temp;
		else
			stk.push(temp);
		
		return true;
	}
};

class MyStack{
private:
	queue<int> que;
public:
	void push(int x){
		que.push(x);
	}
	
	//	ѭ���Ѷ���ͷ��size-1��Ԫ�س��� ����� ��ȡ��ͷ����
	int pop(){	
		int size = que.size() - 1;
		assert(size >= 1);
		
		for(int i = 0; i < size; i++){
			que.push(que.front());
			que.pop();
		}
		
		int x = que.front();
		que.pop();
		return x;
	}
};