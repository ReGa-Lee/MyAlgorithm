public class Insertion{
	public static void sort(Comparable[] a){
		int N = a.length;
		for(int i = 1; i < N; i++){	//	将a[i]插入到a[i-1] a[i-2] a[i-3]... 之中
			for(int j = i; j > 0 && less(a[j], a[j-1]); j--)
				exch(a, j, j-1);	//	通过依次交换的方式
		}
	}
	//	less() exch() isSorted() main()方法见 2.0 排序算法类模板
}