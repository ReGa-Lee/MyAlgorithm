/*
描述：比较次数足够大的情况下，可以选用 先下沉后上浮 的方式
实现：根据二叉树性质(n=n0+n1+n2 --- n0=n2+1 --- n=2*n2+n1+1 --- n/2 ~= n2)巧妙地跳过大小为1的子堆，
构造堆后，交换最大元素并N--，进行下沉排序，直到N=0即排序完，使数组由小到大
*/
public static void sort(Comparable[] a){
	int N = a.length;
	for(int k = N / 2; k >= 1; k--)	//	构造堆，扫描数组中一半元素（跳过大小为1的子堆）
		sink(a, k, N);	
	
	while(N > 1){					//	下沉排序
		exch(a, 1, N--);
		sink(a, 1, N);
	}	
}
//	less() exch() isSorted() main()方法见 2.0 排序算法类模板
public void sink(Comparable[] a, int k, int N){
	while(2 * k <= N){
		int kk = 2 * k;				//	取k的子结点
		if(kk < N && less(kk, kk + 1))	//	取较大元素
			kk++;
		if(!less(k, kk))			//	父结点比子结点还大，满足要求，退出
			break;
		
		exch(k, kk);				//	否则，与子结点交换
		k = kk;
	}
}
