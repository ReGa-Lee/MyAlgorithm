/*
�����㷨���� ����Ϊ3������ <��[left..j-1] >��[j+1..right] ���ֵ���[j]
*/
public static int partition(Comparable[] a, int left, int right){
	int i = left, j = right + 1;	//	����ɨ��ָ��
	Comparable v = a[left];	//	�з�Ԫ��
	
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
	//	less() exch() isSorted() main()������ 2.0 �����㷨��ģ��
}