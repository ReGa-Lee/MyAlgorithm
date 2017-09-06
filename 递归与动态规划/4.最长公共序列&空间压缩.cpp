/*
	最长公共序列
*/
//动态规划
int[][] getdp(char[] str1, char[] str2){
	int dp[str1.length][str2.length];
	dp[0][0] = str1[0] == str2[0] ? 1 : 0;	//	dp[0][0]的取值问题
	for(int i = 1; i < str1.length; i++){
		dp[i][0] = max(dp[i-1][0], str1[i] == str2[0] ? 1 : 0);	//	第一列的取值
	}
	for(int j = 1; j < str2.length; j++){
		dp[0][j] = max(dp[0][j-1], str2[j] == str1[0] ? 1 : 0);	//	第一行的取值
	}
	for(int i = 1; i < str1.length; i++){
		for(int j = 1; j < str2.length; j++){
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);	
			if(str1[i] == str2[j])
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);	//	dp[i][j]的三种取值
		}
	}
	//return dp[str1.length-1][str2.length-1];	//	返回最长公共序列长度
	return dp;
}
char[] lcse(char[] str1, char[] str2){
	if(NULL == str1 || NULL == str2 || 0 == str1.length || 0 == str2.length)
		return -1;
	int dp[][] = getdp(str1, str2);
	int m = str1.length - 1;
	int n = str2.length - 1;
	char rst[dp[m][n]];
	int index = rst.length - 1;	//从后往前找
	while(index >= 0){
		if(n > 0 && dp[m][n] == dp[m][n-1])	
			n--;
		else if(m > 0 && dp[m][n] == dp[m-1][n])
			m--;
		else{	//	dp由左or上得到的情况下，其值是不会增加的，只有找到左上的情况才会将值+1
			res[index--] = str1[m];
			m--;
			n--;
		}
	}
	return rst;
}