/*
	龙与地下城游戏 给定二维数组，往右下角走，血量不能低于1
*/
//动态规划
//	从dp[row][col] 倒推 dp[0][0]需要的HP
int MinHP1(int[][] map){
	if(NULL == map || map.length <= 0 || NULL == map[0] || map[0].length <= 0)
		return -1;
	int row = map.length;
	int col = map[0].length;
	int dp[row--][col--];
	int dp[row][col] = map[row][col] > 0 ? 1 : 1 - map[row][col];
	//	骑士可向右、向下走，分别遍历dp[row][j..] dp[i..][col]
	for(int j = col - 1; j >= 0; j--){
		dp[row][j] = max(dp[row][j+1] - map[row][j], 1);	//	注意是倒推
	}
	for(int i = row - 1; i >= 0; i--){
		dp[i][col] = max(dp[i+1][col] - map[i][col], 1);
		for(int j = col - 1; j >= 0; j--){
			dp[i][j] = max(max(dp[i+1][j] - map[i][j], 1), max(dp[i][j+1] - map[i][j], 1));	//	向下和向右的值比较决定dp[i][j]
		}
	}
	return dp[0][0];
}
//！空间压缩