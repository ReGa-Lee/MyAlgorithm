/*
	快排算法核心 Partition函数 的多种应用
*/
//实现一个快排
//	快排的partition
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
//	快排的递归实现
void QuickSort(int[] arr, int length, int start, int end){
	if(start == end)
		return;
	
	int index = Partition(arr, length, start, end);
	if(index > start)
		Partition(arr, length, start, index - 1);
	if(index < end)
		Partition(arr, length, index + 1, end);
}

//数组中出现次数超过一半的数字(中位数问题)
int HalfNUmber(int[] arr, int length){
	if(CheckInvalidArray(arr, length))	//	NULL输入
		return -1;
	
	int mid = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(arr, length, start, end);
	while(index != mid){	//	查找中位数
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
//	NULL输入的情况
bool bInputInvalid = false;

bool CheckInvalidArray(int[] arr, int length){
	bInputInvalid = false;
	if(NULL == arr || length <= 0)
		bInputInvalid = true;
	
	return bInputInvalid;
}
//	非NULL输入但出现次数不超过一半的情况
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
//最小K个数
void GetLeastNumber(int[] input, int n, int[] output, int k){
	if(NULL == input || NULL == output || k > n || n <= 0 || k <= 0)
		return;
	
	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	while(index != k - 1){	//	0~k-1个数
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
//	最小K个数 之 海量数据处理(基于堆或红黑树)