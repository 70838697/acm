int pa[MAX];//pa[1..n]
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
	while(n)if(pa[n--])c++;
	return c;
}