/*
	堆栈相互实现 主要功能就是入和出 由入实现出
*/
class MyQueue{
private:
	stack<int> stk;
public:
	void enqueue(int x){
		stk.push(x);
	}
	
	//	递归弹出 如果栈非空 再压入	
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
	
	//	循环把队列头的size-1个元素出队 再入队 获取队头即可
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