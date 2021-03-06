/*
	最长递增子序列
*/
//动态规划 总O(N^2)-->O(NlogN)
int[] lis1(int [] arr){
	if(NULL == arr || arr.length = 0)
		return -1;
	int dp[] = getdp1(arr);
	return generateLIS(arr, dp);
}
//	求最长递增子序列 O(N)	逆序还原决策路径
int[] generateLIS(int[] arr, int[] dp){
	int len = 0;
	int index = 0;
	for(int i = 0; i < dp.length; i++){
		if(dp[i] > len){
			len = dp[i];	//	最大长度
			index = i;	//	最大长度的index
		}
	}
	int lis[len];
	lis[--len] = arr[index];
	for(int i = index; i >= 0; i--){
		if(arr[i] < arr[index] && dp[i] == dp[index] - 1){
			lis[--len] = arr[i];	
			index = i;
		}
	}
	return lis;
}
//	暴力法直接得dp O(N^2)	正序生成决策路径
int[] getdp1(int[] arr){
	int dp[arr.length];
	for(int i = 0; i < arr.length; i++){
		dp[i] = 1;	
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j])	//	求的是递增序列 所以决策路径首先是arr[i] > arr[j]
				dp[i] = max(dp[i], dp[j] + 1);	// dp[i]的前j项在dp[j]中 (循环地)取其中一个dp[j]+1 > dp[i] ? dp[j]+1 : dp[i];
		}
	}
	//sort(dp, dp+arr.length-1);	//	排序dp可以方便获得最大序列长度
	return dp;
}
//	二分法优化计算dp的过程 O(NlogN)	有效区
int[] getdp2(int[] arr){
	int dp[arr.length];
	int ends[arr.length];
	ends[0] = arr[0];
	dp[0] = 1;
	int valid = 0;	//	有效区右边界
	int left = 0;	
	int right = 0;
	int mid = 0;
	for(int i = 1; i < arr.length; i++){
		left = 0;
		right = valid;
		while(left <= right){
			mid = (left + right) / 2;
			if(arr[i] > ends[mid])	//	(循环)arr[i]与ends有效区内      元素比较
				left = mid + 1;			
			else
				right = mid - 1;	
		}
		valid = max(valid, left);
		end[left] = arr[i];
		dp[i] = left + 1;
	}
	return dp;
}