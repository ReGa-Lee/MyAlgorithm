/*
描述：两个数组比较，归并生产新数组的过程
实现：需要一个临时数组，
*/
public static void merge(Comparable[] a, int left, int mid, int right){
	int i = left, j = mid + 1;
	
	for(int k = left; k <= right; k++)
		temp[k] = a[k];
	
	for(int k = left; k <= right; k++){
		if(i > mid)
			a[k] = temp[j++];
		else if(j > right)
			a[k] = temp[i++];
		else if(less(temp[j], temp[i]))
			a[k] = temp[j++];
		else
			a[k] = temp[i++];
	}
}