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

//�����г��ִ�������һ�������(��λ������)
int HalfNUmber(int[] arr, int length){
	if(CheckInvalidArray(arr, length))	//	NULL����
		return -1;
	
	int mid = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(arr, length, start, end);
	while(index != mid){	//	������λ��
		if(index > mid){
			end = index - 1;
			Partition(arr, length, start, end);
		}else{
			start = index + 1;
			Partition(arr, length, start, end);
		}
	}
	
	int rst = arr[mid];
	if(!CheckHalf(arr, length, rst))
		return -1;
	
	return rst;
}
//	NULL��������
bool bInputInvalid = false;

bool CheckInvalidArray(int[] arr, int length){
	bInputInvalid = false;
	if(NULL == arr || length <= 0)
		bInputInvalid = true;
	
	return bInputInvalid;
}
//	��NULL���뵫���ִ���������һ������
bool CheckHalf(int[] arr, int length, int rst){
	int times = 0;
	for(int i = 0; i < length; i++){
		if(arr[i] == rst)
			times++;
	}
	
	bool isMoreThanHalf = true;
	if(times * 2 <= length){
		bInputInvalid = true;
		isMoreThanHalf = false;
	}
	
	return isMoreThanHalf;
}
//��СK����
void GetLeastNumber(int[] input, int n, int[] output, int k){
	if(NULL == input || NULL == output || k > n || n <= 0 || k <= 0)
		return;
	
	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	while(index != k - 1){	//	0~k-1����
		if(index > k - 1){
			end = index - 1;
			Partition(input, n, start, end);
		}else{
			start = index + 1;
			Partition(input, n, start, end);
		}
	}
	
	for(int i = 0; i < k; i++){
		output[i] = input[i];
	}
}
//	��СK���� ֮ �������ݴ���(���ڶѻ�����)