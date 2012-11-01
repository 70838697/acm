#include <iostream>
using namespace std;
const int MAX = 21;


int main(void)
{
	__int64 dp[MAX][MAX];
	int n, k;
	int i, j;

	for(i=1; i<MAX; i++)
	{
		dp[i][i]=dp[1][i]=dp[i][0]=dp[0][i]=1;
	}

	for(i=2; i<MAX; i++)
	{
		for(j=i+1; j<MAX; j++)
		{
			dp[i][j]=dp[i-1][j-1]+dp[i][j-i];
		}
	}
	int N, K;
	while(cin>>N>>K)
	{
		if(N==0&&K==0)break;
		cout<<dp[K][N]<<endl;
	}
	return 0;
}