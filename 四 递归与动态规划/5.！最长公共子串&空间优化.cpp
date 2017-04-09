/*
	最长公共子串
*/
//动态规划
int[][] getdp(char[] str1, char[] str2){
	//int maxlen = 0;
	int dp[str1.length][str2.length];
	dp[0][0] = str1[0] == str2[0] ? 1 : 0;
	//	老套路第一行第一列
	for(int i = 1; i < str1.length; i++){
		dp[i][0] = str1[i] == str2[0] ? 1 : 0;
	}
	for(int j = 1; j < str2.length; j++){
		dp[0][j] = str2[j] == str1[0] ? 1 : 0;
	}
	for(int i = 0; i < str1.length; i++){
		for(int j = 0; j < str2.length; j++){
			if(str1[i] == str2[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = 0;
			//maxlen = max(maxlen, dp[i][j]);	//	√	获得长度
		}
	}
	//sort(dp, dp + str1.length * str2.length - 1);	//	×	多维数组不能这么排序
	//return dp[str1.length-1][str2.length-1];	//	×	想要得到长度直接遍历dp
	return dp;
}
//遍历dp得到最大值及其位置->自然获得公共子串
char[] lcst1(char[] str1, char[] str2){
	if(NULL == str1 || NULL == str2 || 0 == str1.length || 0 == str2.length)
		return -1;
	int dp[][] = getdp(str1, str2);
	int end = 0;
	int max = 0;
	for(int i = 0; i < str1.length; i++){
		for(int j = 0; j < str2.length; j++){
			if(dp[i][j] > max){
				end = i;	//	end作为子串截止位置
				max = dp[i][j];	//	max作为子串的长度
			}
		}
	}
	int rst[str1.length];
	strncpy(rst, str1 + end - max, max);	//	实现从str1的第end-max个字符开始复制max个字符给rst
	return rst;
}
//根据dp[i-1][j-1]进行空间优化	O-(M*N) --> O-(1)
char[] lcst2(char[] str1, char[] str2){
	
}