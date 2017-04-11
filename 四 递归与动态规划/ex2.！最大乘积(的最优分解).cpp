/*
http://discuss.acmcoder.com/topic/58ecd4fe243952b61f1a2851
	有一个整数n，将n分解成若干个不同自然数之和，
	问如何分解能使这些数的乘积最大，输出这个乘积m
	
	第一题做法就是  
	求出以2起始的最大连续自然数序列之和sum，使得sum的值不超过输入数n，?  
    设此最大序列为2、3、……、w，则：?  
    若剩余值（n-sum）等于w，则最后输出序列为：3、4、……、w、w+2，即将原最大序列每项加1，?  
    若剩余值（n-sum）小于w，则从序列的最大项i开始，从大到小依次将每项加1，直到剩余值用完。
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