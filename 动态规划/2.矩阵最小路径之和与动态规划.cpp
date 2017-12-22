/*
	最小路径之和
*/
//动态规划 O(M*N) O-(M*N)
int minPathSum1(int[][] m){
	if(NULL == m || 0 == m.length || NULL == m[0] || 0 == m[0].length)
		return -1;
	int row = m.length;
	int col = m[0].length;
	int dp[row][col];
	dp[0][0] = m[0][0];
	for(int i = 1; i < row; i++){
		dp[i][0] = m[i][0] + dp[i-1][0];	//	行对应[i][0]
	}
	for(int j = 1; j < col; i++){
		dp[0][j] = m[0][j] + dp[0][j-1];	//	列对应[0][j]
	}
	for(int i = 1; i < row; i++){
		for(int j = 1; j < col; j++){
			dp[i][j] = m[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[row-1][col-1];	//	返回矩阵右下角
}

//动态规划+空间压缩 O(M*N) O-(min(M,N))
int minPathSum2(int[][] m){
	if(NULL == m || m.length == 0 || NULL == m[0] || m[0].length == 0)
		return -1;
	//	less作为数组长度 more作为数组动态变化次数 最终变化次数可能会增多 只是少用了一些内存空间
	int more = max(m.length, m[0].length);	//	行数与列数较大为more
	int less = min(m.length, m[0].length);	//	较小为less
	bool rowmore = more == m.length;	//	判断行数是否大于等于列数
	int arr[less];	//	辅助空间取最小即可
	arr[0] = m[0][0];
	for(int i = 1; i < less; i++){
		arr[i] = arr[i-1] + (rowmore? m[0][i] : m[i][0]);	//	因为数组要取最小值 rowmore为true时取列值 反之取行值
	}
	for(int i = 1; i < more; i++){	
		//	数组arr[]从矩阵第一行变化到第i行
		arr[0] = arr[0] + (rowmore? m[i][0] : m[0][i]);	//	因为变化次数要取最大值 rowmore为true时取行值 反之取列值
		for(int j = 1; j < less; j++){
			//	第i行的数组中取值有两种选择 一种10到达11 dp10+m11 一种01到达11 dp01+m11
			//	此时arr[0]已经更新成了dp[1][0] arr[1]还没有更新 所以arr[1]还是dp[0][1] arr[1] = min(arr[0], arr[1])+m[1][1]
			arr[j] = min(arr[j-1], arr[j]) + (rowmore? m[i][j] : m[j][i]);	//	正常加
		}
	}
	return arr[less - 1];	//	返回当前变化数组的最右值
}