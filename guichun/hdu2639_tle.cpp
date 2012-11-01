#include<iostream>
#include<set>
#include<functional>
#include <algorithm>
using namespace std;

const int MAX = 105;
const int MAX_SIZE = 1005;
typedef struct goods
{
	int vol, weight;
} G;

set<int, greater<int> > mySet;
G bone[MAX];
int n, vol, k;
int dp[MAX_SIZE][35];

void zeroOnePack(G bone)
{
	for(int i = vol; i >= bone.vol; i--)
	{
		mySet.clear();
		for(int j = 0; j < k; j++)
		{
			int a, b;
			a = dp[i][j];
			b = dp[i-bone.vol][j] + bone.weight;
			mySet.insert(a);
			mySet.insert(b);
		}
		set<int, greater<int> >::iterator iter1;
		iter1 = mySet.begin();

		for(int j = 0; j < k && iter1 != mySet.end(); j++)
		{
			dp[i][j] = *iter1;
			iter1++;
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