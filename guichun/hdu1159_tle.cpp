#include<iostream>
#include<cstring>
using namespace std;

const int MAX_LEN = 100005;
int dp[2][MAX_LEN];
char str1[MAX_LEN], str2[MAX_LEN];

int main(void)
{
	str1[0] = str2[0] = '1';
	while(scanf("%s %s", str1+1, str2+1) == 2)
	{
		memset(dp, 0, sizeof(dp));
		int len1 = strlen(str1);
		int len2 = strlen(str2);

		for(int i = 1; i < len1; i++)
		{
			for(int j = 1; j < len2; j++)
			{
				if(str1[i] == str2[j])
					dp[1][j] = dp[0][j-1] + 1;
				else
				{
					if(dp[1][j-1] > dp[0][j])
						dp[1][j] = dp[1][j-1];
					else
						dp[1][j] = dp[0][j];
				}
			}
			memcpy(dp[0], dp[1], sizeof(dp[1]));
		}
		printf("%d\n", dp[1][len2-1]);
	}
	return 0;
}