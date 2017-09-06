/*
	���������
*/
//��̬�滮
int[][] getdp(char[] str1, char[] str2){
	int dp[str1.length][str2.length];
	dp[0][0] = str1[0] == str2[0] ? 1 : 0;	//	dp[0][0]��ȡֵ����
	for(int i = 1; i < str1.length; i++){
		dp[i][0] = max(dp[i-1][0], str1[i] == str2[0] ? 1 : 0);	//	��һ�е�ȡֵ
	}
	for(int j = 1; j < str2.length; j++){
		dp[0][j] = max(dp[0][j-1], str2[j] == str1[0] ? 1 : 0);	//	��һ�е�ȡֵ
	}
	for(int i = 1; i < str1.length; i++){
		for(int j = 1; j < str2.length; j++){
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);	
			if(str1[i] == str2[j])
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);	//	dp[i][j]������ȡֵ
		}
	}
	//return dp[str1.length-1][str2.length-1];	//	������������г���
	return dp;
}
char[] lcse(char[] str1, char[] str2){
	if(NULL == str1 || NULL == str2 || 0 == str1.length || 0 == str2.length)
		return -1;
	int dp[][] = getdp(str1, str2);
	int m = str1.length - 1;
	int n = str2.length - 1;
	char rst[dp[m][n]];
	int index = rst.length - 1;	//�Ӻ���ǰ��
	while(index >= 0){
		if(n > 0 && dp[m][n] == dp[m][n-1])	
			n--;
		else if(m > 0 && dp[m][n] == dp[m-1][n])
			m--;
		else{	//	dp����or�ϵõ�������£���ֵ�ǲ������ӵģ�ֻ���ҵ����ϵ�����ŻὫֵ+1
			res[index--] = str1[m];
			m--;
			n--;
		}
	}
	return rst;
}