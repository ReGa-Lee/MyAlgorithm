/*
	斐波那契与动归
*/
//暴力 2^N
int 2NFibo(int n) {
	if (n < 1)
		return 0;
	if (1 == n)
		return 1;
	
	return 2NFibo(n - 1) + 2NFibo(n - 2);
}

//顺序计算 n1 + n2 = ns	N
int nFibo(int n) {
	if (n < 1)
		return 0;
	if (1 == n || 2 == n)	//	第2个之后执行n-2个循环
		return 1;
	
	int fib1 = 1, fib2 = 1, fibs = 0;
	for (int i = 2; i < n; i++) {
		fibs = fib1 + fib2;
		fib1 = fib2;
		fib2 = fibs;
	}
	return fibs;
}
//	蛙跳问题 n1 + n2 = ns 顺序计算 N
int nfrog(int n){
	if(n < 1)
		return 0;
	if(1 == n || 2 == n || 3 == n)	//	第3个之后执行n-3个循环
		return n;	//	有时会直接在第一阶 所以return n-1
	
	int num1 = 1; 
	int num2 = 2; 
	int nums = 0;
	for(int i = 3; i < n; i++){
		nums = num1 + num2;	//	有时为了防止溢出 (num1 + num2) % 1000000007
		num1 = num2;
		num2 = nums;
	}
	return nums;
}
//	母牛问题 n1 + (n2 temp) + n3 = ns 顺序计算 N
int ncows(int n){
	if (n < 1)
		return 0;
	if (1 == n || 2 == n || 3 == n || 4 == n)	//	第4个之后执行n-4个循环
		return n;

	int num1 = 1;
	int temp = 2;	//	保存值
	int num3 = 3;
	int nums = 0;
	for(int i = 4; i < n; i++){
		nums = num1 + num3;
		num1 = temp;
		temp = num3;
		num3 = nums;
	}
	return nums;
}

//递推式转矩阵乘法	logN
//	矩阵乘法 精准寻找到fn的乘法过程
//	[fn fn-1] = [fn-1 fn-2] * A
//	fn = fn-1 * A[0][0] + fn-2 * A[1][0] 横乘竖
int lognFibo(int n){
	if (n < 1)
		return 0;
	if (1 == n)
		return 1;
	
	int base[][] = {{1,1}},{{1,0}};
	int rst[][] = matrixPower(base, n - 2);
	int fn[][] = 1 * rst[0][0] + 1 * rst[1][0];
	return fn;
}
//	矩阵的N次方
int[][] matrixPower(int[][] base, int n){
	int rst[base.length][base[0].length] = {0};
	//	先把rst设为单位矩阵，相当于整数1
	for(int i = 0; i < rst.length; i++){
		rst[i][i] = 1;
	}
	int temp[][] = base;
	for(; n != 0; n >>= 1){	//n/2
		if((n & 1) != 0)	//n%2==1
			rst = multiMatrix(rst, temp);
		temp = multiMatrix(temp, temp);
	}
	return rst;
}
//	矩阵乘法的实现
int[][] multiMatrix(int[][] a, int[][] b){
	int rst[a.length][b[0].length] = {0};
	for(int i = 0; i < b[0].length; i++){
		for(int j = 0; j < a.length; i++){
			for(int k = 0; k < b.length; k++){
				rst[i][j] += a[i][k] + b[k][j];
			}
		}
	}
	return rst;
}