/*
	쳲������붯��
*/
//���� 2^N
int 2NFibo(int n) {
	if (n < 1)
		return 0;
	if (1 == n)
		return 1;
	
	return 2NFibo(n - 1) + 2NFibo(n - 2);
}

//˳����� n1 + n2 = ns	N
int nFibo(int n) {
	if (n < 1)
		return 0;
	if (1 == n || 2 == n)	//	��2��֮��ִ��n-2��ѭ��
		return 1;
	
	int fib1 = 1, fib2 = 1, fibs = 0;
	for (int i = 2; i < n; i++) {
		fibs = fib1 + fib2;
		fib1 = fib2;
		fib2 = fibs;
	}
	return fibs;
}
//	�������� n1 + n2 = ns ˳����� N
int nfrog(int n){
	if(n < 1)
		return 0;
	if(1 == n || 2 == n || 3 == n)	//	��3��֮��ִ��n-3��ѭ��
		return n;	//	��ʱ��ֱ���ڵ�һ�� ����return n-1
	
	int num1 = 1; 
	int num2 = 2; 
	int nums = 0;
	for(int i = 3; i < n; i++){
		nums = num1 + num2;	//	��ʱΪ�˷�ֹ��� (num1 + num2) % 1000000007
		num1 = num2;
		num2 = nums;
	}
	return nums;
}
//	ĸţ���� n1 + (n2 temp) + n3 = ns ˳����� N
int ncows(int n){
	if (n < 1)
		return 0;
	if (1 == n || 2 == n || 3 == n || 4 == n)	//	��4��֮��ִ��n-4��ѭ��
		return n;

	int num1 = 1;
	int temp = 2;	//	����ֵ
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

//����ʽת����˷�	logN
//	����˷� ��׼Ѱ�ҵ�fn�ĳ˷�����
//	[fn fn-1] = [fn-1 fn-2] * A
//	fn = fn-1 * A[0][0] + fn-2 * A[1][0] �����
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
//	�����N�η�
int[][] matrixPower(int[][] base, int n){
	int rst[base.length][base[0].length] = {0};
	//	�Ȱ�rst��Ϊ��λ�����൱������1
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
//	����˷���ʵ��
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