/*
	最大连续序列和
*/
//动态规划
//	标准做法 把arr[i]放在外面 保证能取到每个数
//  [-1, -10, -10, 11]
//	dp0 = -1 rst = -1
//  dp1 = dp0 + nums1 = -1-10 = -11 rst = -11与-1 选-1
//  dp2 = dp1 + nums2 = max(-11,0)-10 = -10 rst = -10与-1 选-1
//  dp3 = dp2 + nums3 = max(-10,0)+11 = 11 rst = -1与11 选11
//  dp[] = -1 -11 -10 11 rst = -1 -1 -1 11 
int FindGreatestSumOfSubArray2(vector<int> arr){
	int dp[arr.size()];
	dp[0] = arr[0];	//	直接拿arr[0]
	int rst = dp[0];
	for(int i = 1; i < arr.size(); i++){
		//	深度理解dp[]-->保存arr[0...n]的状态而不是arr[n]
		//	深度理解max(dp[i-1],0)-->只有在dp[i-1]为负的情况才被扔掉
		//	从而避免写出会错意的代码~
		dp[i] = max(dp[i-1], 0) + arr[i];
		rst = max(rst, dp[i]);
	}
	return rst;	
}
//	自己做法 小于负数时返回0 容易与[0]混淆
int FindGreatestSumOfSubArray(vector<int> arr){
	int dp[arr.size()];
	dp[0] = max(arr[0], 0);
	int maxlen = dp[0];
	for(int i = 1; i < arr.size(); i++){
		dp[i] = max(dp[i-1] + arr[i], 0);
		maxlen = max(maxlen, dp[i]);
	}
	if(0 == maxlen)	//	数组全为负的情况
		return -1;
	return maxlen;
}