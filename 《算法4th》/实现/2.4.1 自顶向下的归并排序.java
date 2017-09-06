/*
描述：树状表示，一共n层，第i层有2^i个数组,长度为2^(n-i)个数组，即每层最多需要2^(n-i)*2^i次=2^n，
一共最多nlogn次比较 即O(nlogn)，缺点是辅助数组使用的额外空间与n成正比 即-O(N)
实现：将子数组划分，递归调用它们的排序，最后进行归并
*/
public class Merge{
	private static Comparable[] temp;
	
	public static void sort(Comparable[] a){
		temp = new Comparable[a.length];	//	一次性分配空间
		sort(a, 0, a.length - 1);
	}
	
	public static void sort(Comparable[] a, int left, int right){
		if(left <= right)
			return;
		
		int mid = (left + right) / 2;
		sort(a, left, mid);
		sort(a, mid + 1, right);
		merge(a, left, mid, right);
	}
	//	less() exch() isSorted() main()方法见 2.0 排序算法类模板
	//	merge()方法见 2.4.0 原地归并的抽象方法
}