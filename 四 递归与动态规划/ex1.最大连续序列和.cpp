/*
	����������к�
*/
//��̬�滮
//	��׼���� ��arr[i]�������� ��֤��ȡ��ÿ����
//  [1, 10, -10, 11]
//	dp0 = 1 rst = 1
//  dp1 = dp0 + nums1  1+10 = 11 rst = 11��1 ѡ11
//  dp2 = dp1 + nums2  11-10 = 1 rst = 0��11 ѡ11
//  dp3 = dp2 + nums3  1+11 = 12 rst = 12��11 ѡ12
//  dp[] = 11 1 12 rst = 11 11 12 
int FindGreatestSumOfSubArray2(vector<int> arr){
	int dp[arr.size()];
	dp[0] = arr[0];	//	ֱ����arr[0]
	int maxlen = dp[0];
	for(int i = 1; i < arr.size(); i++){
		//	������dp[]-->����arr[0...n]��״̬������arr[n]
		//	������max(dp[i-1],0)-->ֻ����dp[i-1]Ϊ��������ű��ӵ�
		//	�Ӷ�����д�������Ĵ���~
		dp[i] = max(dp[i-1], 0) + arr[i];
		maxlen = max(maxlen, dp[i]);
	}
	return rst;	
}
//	�Լ����� С�ڸ���ʱ����0 ������[0]����
int FindGreatestSumOfSubArray(vector<int> arr){
	int dp[arr.size()];
	dp[0] = max(arr[0], 0);
	int maxlen = dp[0];
	for(int i = 1; i < arr.size(); i++){
		dp[i] = max(dp[i-1] + arr[i], 0);
		maxlen = max(maxlen, dp[i]);
	}
	if(0 == maxlen)	//	����ȫΪ�������
		return -1;
	return maxlen;
}