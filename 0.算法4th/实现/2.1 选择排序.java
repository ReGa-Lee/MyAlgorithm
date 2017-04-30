public class Selection{
	public static void sort(Comparable[] a){
		int N = a.length;
		for(int i = 0; i < N; i++){	//	将a[i]与a[i+1...N]中最小的数交换
			int min = i;
			for(int j = i+1; j < N; j++)
				if(less(a[j]), a[min])
					min = j;
			exch(a, i, min);
		}
	}
	//	less() exch() isSorted() main()方法见 2.0 排序算法类模板
}