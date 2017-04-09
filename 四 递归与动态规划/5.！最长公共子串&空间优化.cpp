/*
	������Ӵ�
*/
//��̬�滮
int[][] getdp(char[] str1, char[] str2){
	//int maxlen = 0;
	int dp[str1.length][str2.length];
	dp[0][0] = str1[0] == str2[0] ? 1 : 0;
	//	����·��һ�е�һ��
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
			//maxlen = max(maxlen, dp[i][j]);	//	��	��ó���
		}
	}
	//sort(dp, dp + str1.length * str2.length - 1);	//	��	��ά���鲻����ô����
	//return dp[str1.length-1][str2.length-1];	//	��	��Ҫ�õ�����ֱ�ӱ���dp
	return dp;
}
//����dp�õ����ֵ����λ��->��Ȼ��ù����Ӵ�
char[] lcst1(char[] str1, char[] str2){
	if(NULL == str1 || NULL == str2 || 0 == str1.length || 0 == str2.length)
		return -1;
	int dp[][] = getdp(str1, str2);
	int end = 0;
	int max = 0;
	for(int i = 0; i < str1.length; i++){
		for(int j = 0; j < str2.length; j++){
			if(dp[i][j] > max){
				end = i;	//	end��Ϊ�Ӵ���ֹλ��
				max = dp[i][j];	//	max��Ϊ�Ӵ��ĳ���
			}
		}
	}
	int rst[str1.length];
	strncpy(rst, str1 + end - max, max);	//	ʵ�ִ�str1�ĵ�end-max���ַ���ʼ����max���ַ���rst
	return rst;
}
//����dp[i-1][j-1]���пռ��Ż�	O-(M*N) --> O-(1)
char[] lcst2(char[] str1, char[] str2){
	
}