int pa[MAX];
int rank[MAX];
void make_set(int x)
{
	pa[x] = x;//set parent as self
	rank[x] = 0; //set rank as needed
}

int find_set(int x)
{
	if (x != pa[x])
	{
		pa[x] = find_set(pa[x]);
	}
	return pa[x];
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