/*
	�����������
*/
//��̬�滮 ��O(N^2)-->O(NlogN)
int[] lis1(int [] arr){
	if(NULL == arr || arr.length = 0)
		return -1;
	int dp[] = getdp1(arr);
	return generateLIS(arr, dp);
}
//	������������е���βֵ	��dpֱ��sort
//	������������� O(N)	����ԭ����·��
int[] generateLIS(int[] arr, int[] dp){
	int len = 0;
	int index = 0;
	for(int i = 0; i < dp.length; i++){
		if(dp[i] > len){
			len = dp[i];	//	��󳤶�
			index = i;	//	��󳤶ȵ�index
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
//	������ֱ�ӵ�dp O(N^2)	�������ɾ���·��
int[] getdp1(int[] arr){
	int dp[arr.length];
	for(int i = 0; i < arr.length; i++){
		dp[i] = 1;	
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j])	//	����ǵ������� ���Ծ���·��������arr[i] > arr[j]
				dp[i] = max(dp[i], dp[j] + 1);	// dp[i]��ǰj����dp[j]�� (ѭ����)ȡ����һ��dp[j]+1 > dp[i] ? dp[j]+1 : dp[i];
		}
	}
	//sort(dp, dp+arr.length-1);	//	����dp���Է�������βֵ
	return dp;
}
//	!	���ַ��Ż�����dp�Ĺ��� O(NlogN)	��Ч��
int[] getdp2(int[] arr){
	
}