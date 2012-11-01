#include<iostream>
using namespace std;

const int MAX = 105;
const int MAX_SIZE = 1005;
typedef struct goods
{
	int vol, weight;
} G;

G bone[MAX];
int n, vol, k;
int dp[MAX_SIZE][35];
int A[35], B[35];
void zeroOnePack(G bone)
{
	int a, b, c, j;
	for(int i = vol; i >= bone.vol; i--)
	{
		for(j = 0; j < k; j++)
		{
			A[j] = dp[i][j];
			B[j] = dp[i-bone.vol][j] + bone.weight;
		}
		A[k] = B[k] = -1;//guard end of array
		a = b = c = 0;
		while(c < k && (a < k || b < k))
		{
			if(A[a] > B[b])
				dp[i][c] = A[a], a++;
			else
				dp[i][c] = B[b], b++;
			if(dp[i][c] != dp[i][c-1])
				c++;
		}
	}
}

void init()
{
	memset(dp, 0, sizeof(dp));
}

int main(void)
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		init();

		scanf("%d %d %d", &n, &vol, &k);
		for(int i = 0; i < n; i++)
			scanf("%d", &bone[i].weight);
		for(int i = 0; i < n; i++)
			scanf("%d", &bone[i].vol);
		for(int i = 0; i < n; i++)
			zeroOnePack(bone[i]);

		cout << dp[vol][k-1] << endl;
	}
	return 0;
}