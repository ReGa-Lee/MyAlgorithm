/*
描述：希尔排序是插入排序的升级，是将数组构造成 h-有序 以提升插入排序性能，有效地避免了插入排序交换相邻元素距离（次数）过长的问题
实现：为了插入新元素，迭代交换不相邻元素，形成部分有序（称为h-有序），至h=1时交换的是a[j],a[j-1] 即 插入排序
*/
public class Shell{
	public static void sort(Comparable[] a){
		int N = a.length;
		int h = 1;
		while(h < N / 3)	//	1 4 13 40 121 364 1093
			h = 3 * h + 1;
		while(h >= 1){	//	将数组变为h有序
			for(int i = h; i < N; i++){	//	将a[i]插入到a[i-h] a[i-2*h] a[i-3*h]... 之中
				for(int j = i; j >= h && less(a[j], a[j-h]); j -= h)
					exch(a, j, j - h);
			}
			h /= 3;	//	不断迭代至1 即 插入排序
		}
	}
	//	less() exch() isSorted() main()方法见 2.0 排序算法类模板
}