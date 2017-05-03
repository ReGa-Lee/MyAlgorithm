/*
描述：信息量最优，适用于重复元素很多的应用中，将时间复杂度从线性对数降至线性级别
实现：重构Partition函数 划分为3个区域 <区[left..lt-1] =区[lt..gt] >区[gt+1..right]
*/
public class Quick3way{
	private static void sort(Comparable[] a, int left, int right){
		if(right <= left)
			return;
		
		int lt = left, int i = left + 1, int gt = right;	//	lt gt为左右扫描指针 i为中间扫描指针(扫描重复数)
		Comparable v = a[left];
		while(i <= gt){
			int temp = a[i].compareTo(v);
			
			if(temp < 0)
				exch(a, lt++, i++);
			else if(temp > 0)
				exch(a, i, gt--);
			else
				i++;
		}
		sort(a, left, lt - 1);
		sort(a, gt + 1, right);
	}
	//	less() exch() isSorted() main()方法见 2.0 排序算法类模板
}