/*
	�����㷨���� Partition���� �Ķ���Ӧ��
*/
//ʵ��һ������
//	���ŵ�partition
int Partition(int[] arr, int length, int start, int end){
	if(NULL == arr || length <= 0 || start < 0 || end >= length)
		return -1;
	
	int index = RandomInRange(start, end);
	Swap(&arr[index], &arr[end]);
	int small = start - 1;
	
	for(int i = start; i < end; i++){
		if(arr[i] < arr[end]){
			small++;
			if(i != small)
				Swap(&arr[i], &arr[small]);
		}
	}
	
	small++;
	Swap(&arr[small], &arr[end]);
	
	return small;
}
//	���ŵĵݹ�ʵ��
void QuickSort(int[] arr, int length, int start, int end){
	if(start == end)
		return;
	
	int index = Partition(arr, length, start, end);
	if(index > start)
		Partition(arr, length, start, index - 1);
	if(index < end)
		Partition(arr, length, index + 1, end);
}

//ʵ��