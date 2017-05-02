/*
描述：倒置！树状表示，一共n层，第i层有2^i个数组,长度为2^(n-i)个数组，即每层最多需要2^(n-i)*2^i次=2^n，
一共最多nlogn次比较 即O(nlogn)，缺点是辅助数组使用的额外空间与n成正比 即-O(N)
实现：对数组进行一一排序(共2个数组)、两两排序(共4个数组)、四四、八八等
*/
public class MergeBU{
	private static Comparable[] temp;
	
	public static void sort(Comparable[] a){
		int N = a.length;
		temp = new Comparable[N];	//	一次性分配空间
		for(int sz = 1; sz < N; sz += sz)	//	sz为子数组大小
			for(int i = 0; i < N - sz; i += sz + sz)	//	i为子数组索引
				merge(a, i, i + sz - 1, Math.min(i + sz + sz - 1, N - 1));	//	min防止越界，一般情况使用的是i+2sz-1
	}
	//	less() exch() isSorted() main()方法见 2.0 排序算法类模板
	//	merge()方法见 2.4.0 原地归并的抽象方法
}