#include"iostream"
#include"string.h"
#include"cstdio"
//hdu VC++ needs this pragma, g++ no need
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int pa[100009];//pa[1..n]
int flag=0;
void init_set(int n)
{
	memset(pa,0,sizeof(int)*(n+1));//default parent set to 0, you can set -1
}
inline int find_set(int x)
{
	//if no parent
	return pa[x]?(pa[x]=find_set(pa[x])):x;
}
void union_set(int x, int y)
{
	x = find_set(x);
	y = find_set(y);
	if (x != y)	pa[x] = y;
	else flag=1;//two tree
}

int main()
{
	int a,b,n=100005,m=0;
	init_set(n);
	while( (scanf("%d%d",&a,&b)==2) && (a!=-1 || b!=-1))
	{
		if(a==0 && b==0)
		{
			int k=n,mp=0;
			if(m==0)
				cout<<"Yes"<<endl;
			else if(flag==1) cout<<"No"<<endl;
			else
			{
				//check whether there is only one tree
				while(k&&!pa[k--]);//get root of first tree
				if(pa[k+1])mp=find_set(pa[k+1]);
				while(k)if(pa[k--])
					{
						if(mp!=find_set(pa[k+1]))
						{
							flag=1;
							break;
						}
					};
				if(flag==0)
					cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
			init_set(n);
			flag=0;
			m=0;
			continue;
		}
		//if(a==b)continue;//the same node
		m++;

		union_set(a,b);
	}
	return 0;
}