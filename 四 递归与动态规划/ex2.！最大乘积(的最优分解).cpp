/*
http://discuss.acmcoder.com/topic/58ecd4fe243952b61f1a2851
	��һ������n����n�ֽ�����ɸ���ͬ��Ȼ��֮�ͣ�
	����ηֽ���ʹ��Щ���ĳ˻�����������˻�m
	
	��һ����������  
	�����2��ʼ�����������Ȼ������֮��sum��ʹ��sum��ֵ������������n��?  
    ����������Ϊ2��3��������w����?  
    ��ʣ��ֵ��n-sum������w��������������Ϊ��3��4��������w��w+2������ԭ�������ÿ���1��?  
    ��ʣ��ֵ��n-sum��С��w��������е������i��ʼ���Ӵ�С���ν�ÿ���1��ֱ��ʣ��ֵ���ꡣ
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define maxn 109
using namespace std;
int MaxNum(int n){
	int dp[maxn][maxn];
	int rst = 0;
	for(int i = 0; i < n; i++)
		dp[0][i] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			for(int k = 0 ; k < j; k++){
				dp[i][j] = max(dp[i][j], dp[i - j][k] * j);
				rst = max(rst, dp[i][j]);
			}
		}
	}
    return rst;
}
int main(){
	int n;
	cin >> n;
  	cout << MaxNum(n) << endl;
	return 0;
}