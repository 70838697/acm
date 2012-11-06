#include"iostream"
using namespace std;
#define MAX 1024
int pa[MAX];
int rank[MAX];
void init_set(int n)
{
	memset(pa,0,sizeof(int)*(n+1));//default parent set to 0, you can set -1
	memset(rank,0,sizeof(int)*(n+1));//default parent set to 0, you can set -1
}

int find_set(int x)
{
	if (pa[x])
	{
		return pa[x] = find_set(pa[x]);
	}
	return x;
}

void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);
	if (x == y) return;
	if (rank[x] > rank[y])
	{
		pa[y] = x;
	}
	else
	{
		if (rank[x] == rank[y])
		{
			rank[y]++;
		}
		pa[x] = y;
	}
}

int main()
{
    int a,b,n,m;
    while(cin >> n,n){
        cin >> m;
        init_set(n);
        while(m--){
            cin >> a >> b;
            union_set(a,b);
        }
		/* //there is a cost calling a function 46ms->72ms
        cout << count_set(n)-1 << endl;
		*/
		while(n)if(!pa[n--])m++;
        cout << m << endl;
    }
    return 0;
}