int count(unsigned char c)
{
	int num=0;
	do
	{
		if(c%2==1)num++;
		c=c/2;
	}while(c);
	return num;
}