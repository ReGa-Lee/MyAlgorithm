/*
	N*N棋盘摆N皇后的解法
*/
//动态规划
int NQueen(int n){
	if(n < 1)
		retirm -1;
	int col[n];	//	记录每行皇后所在的列数
	return process(0, col, n);	//	输入i行 已知的col数组 目标n行
}
//	查找皇后过程
//	逐行放置皇后，递归实现从0行j列，条件遍历到n-1行j列，到达n行时 i=n 遍历完成 返回一种解法 rst+=1;
int process(int i, int[] col, int n){
	if(i == n)
		return 1;	//	i=n时遍历完全
	int rst = 0;
	for(int j = 0; j < n; j++){
		if(isValid(col, i, j)){
			col[i] = j;
			rst += process(i + 1, col, n);
		}
	}
	return rst;
}
//	判断此行是否能够放皇后 不同的行 判断j列==已知的col[k]列 and 判断(i,j)(k,col[k])是否同斜线 |i-k| == |j-col[k]| 
bool isValid(int[] col, int i, int j){
	for(int k = 0; k < i; k++){
		if(j == col[k] || abs(col[k] - j) == abs(i - k){
			return false;
		}
	}
	return true;
}