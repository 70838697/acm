int count(unsigned char c)
{
	int num=0;
	do{
		if(c&1)num++;
	}while(c>>=1);
	return num;
}