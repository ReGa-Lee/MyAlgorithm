/*
API - MaxPQ
MaxPQ(int)
boolean isEmpty()
int size()
void insert(T)
T delMax()
*/

public class MaxPQ<T extends Comparable<T>>{
	private T[] pq;		//	基于堆的完全二叉树
	private int N = 0;	//	存储在pq[1...N]，不使用pq[0]
	
	public MaxPQ(int maxN){
		pq = (T[]) new Comparable[maxN + 1];
	}
	
	public boolean isEmpty(){ return N == 0; }
	public int size(){ return N; }
	
	public void insert(T temp){
		pq[++N] = temp;
		swim(N);
	}
	public T delMax(){
		T max = pq[1];	//	获取最大元素
		exch(1, N--);	//	与最后一个结点交换
		pq[N+1] = null;	//	防止对象游离
		sink(1);		//	恢复堆的有序性
		return max;
	}
	
	private boolean less(int i, int j){
		return pq[i].compareTo(pq[j]) < 0;
	}
	private void exch(int i, int j){
		T temp = pq[i];
		pq[i] = pq[j];
		pq[j] = temp;
	}
	private void swim(int k){
		while(k > 1 && less(k / 2, k)){
			exch(k / 2, k);
			k = k / 2;
		}
	}
	private void sink(int k){
		while(2 * k <= N){
			int kk = 2 * k;
			if(kk < N && less(kk, kk + 1))	//	找到两个根结点中较大的与k比较
				k++;
			if(!less(k, kk))
				break;
			
			exch(k, kk);
			k = kk;
		}
	}	
}