/*
	N*N���̰�N�ʺ�Ľⷨ
*/
//��̬�滮
int NQueen(int n){
	if(n < 1)
		retirm -1;
	int col[n];	//	��¼ÿ�лʺ����ڵ�����
	return process(0, col, n);	//	����i�� ��֪��col���� Ŀ��n��
}
//	���һʺ����
//	���з��ûʺ󣬵ݹ�ʵ�ִ�0��j�У�����������n-1��j�У�����n��ʱ i=n ������� ����һ�ֽⷨ rst+=1;
int process(int i, int[] col, int n){
	if(i == n)
		return 1;	//	i=nʱ������ȫ
	int rst = 0;
	for(int j = 0; j < n; j++){
		if(isValid(col, i, j)){
			col[i] = j;
			rst += process(i + 1, col, n);
		}
	}
	return rst;
}
//	�жϴ����Ƿ��ܹ��Żʺ� ��ͬ���� �ж�j��==��֪��col[k]�� and �ж�(i,j)(k,col[k])�Ƿ�ͬб�� |i-k| == |j-col[k]| 
bool isValid(int[] col, int i, int j){
	for(int k = 0; k < i; k++){
		if(j == col[k] || abs(col[k] - j) == abs(i - k){
			return false;
		}
	}
	return true;
}