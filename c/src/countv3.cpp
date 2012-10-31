int count(unsigned char c)
{
	int num=0;
	while(c){
		num++;
		c=c&(c-1);
	}
	return num;
}