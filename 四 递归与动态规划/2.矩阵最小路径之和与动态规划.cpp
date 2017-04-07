/*
	��С·��֮��
*/
//��̬�滮 O(M*N) O-(M*N)
int minPathSum1(int[][] m){
	if(NULL == m || 0 == m.length || NULL == m[0] || 0 == m[0].length)
		return -1;
	int row = m.length;
	int col = m[0].length;
	int dp[row][col];
	dp[0][0] = m[0][0];
	for(int i = 1; i < row; i++){
		dp[i][0] = m[i][0] + dp[i-1][0];	//	�ж�Ӧ[i][0]
	}
	for(int j = 1; j < col; i++){
		dp[0][j] = m[0][j] + dp[0][j-1];	//	�ж�Ӧ[0][j]
	}
	for(int i = 1; i < row; i++){
		for(int j = 1; j < col; j++){
			dp[i][j] = m[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[row-1][col-1];	//	���ؾ������½�
}

//��̬�滮+�ռ�ѹ�� O(M*N) O-(min(M,N))
int minPathSum2(int[][] m){
	if(NULL == m || m.length == 0 || NULL == m[0] || m[0].length == 0)
		return -1;
	//	less��Ϊ���鳤�� more��Ϊ���鶯̬�仯���� ���ձ仯�������ܻ����� ֻ��������һЩ�ڴ�ռ�
	int more = max(m.length, m[0].length);	//	�����������ϴ�Ϊmore
	int less = min(m.length, m[0].length);	//	��СΪless
	bool rowmore = more == m.length;	//	�ж������Ƿ���ڵ�������
	int arr[less];	//	�����ռ�ȡ��С����
	arr[0] = m[0][0];
	for(int i = 1; i < less; i++){
		arr[i] = arr[i-1] + (rowmore? m[0][i] : m[i][0]);	//	��Ϊ����Ҫȡ��Сֵ rowmoreΪtrueʱȡ��ֵ ��֮ȡ��ֵ
	}
	for(int i = 1; i < more; i++){	
		//	����arr[]�Ӿ����һ�б仯����i��
		arr[0] = arr[0] + (rowmore? m[i][0] : m[0][i]);	//	��Ϊ�仯����Ҫȡ���ֵ rowmoreΪtrueʱȡ��ֵ ��֮ȡ��ֵ
		for(int j = 1; j < less; j++){
			//	��i�е�������ȡֵ������ѡ�� һ��10����11 dp10+m11 һ��01����11 dp01+m11
			//	��ʱarr[0]�Ѿ����³���dp[1][0] arr[1]��û�и��� ����arr[1]����dp[0][1] arr[1] = min(arr[0], arr[1])+m[1][1]
			arr[j] = min(arr[j-1], arr[j]) + (rowmore? m[i][j] : m[j][i]);	//	������
		}
	}
	return arr[less - 1];	//	���ص�ǰ�仯���������ֵ
}