/*
	最大连续序列和
*/
//动态规划
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