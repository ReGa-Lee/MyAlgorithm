/*
快排算法核心 划分为3个区域 <区[left..j-1] >区[j+1..right] 划分点区[j]
*/
public static int partition(Comparable[] a, int left, int right){
	int i = left, j = right + 1;	//	左右扫描指针
	Comparable v = a[left];	//	切分元素
	
	while(true){
		while(less(a[++i], v))
			if(i == right)
				break;
		while(less(v, a[--j]))
			if(j == left)
				break;
		
		if(i >= j)
			break;
		
		exch(a, i, j);
	}
	exch(a, left, j);
	return j;
	//	less() exch() isSorted() main()方法见 2.0 排序算法类模板
}