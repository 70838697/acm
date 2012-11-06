#include"iostream"
using namespace std;
int pa[1002];//pa[1..n]
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
}

inline int count_set(int n)
{
	int c=0;
	while(n)if(!pa[n--])c++;
	return c;
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