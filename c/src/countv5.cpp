int count(unsigned char c)
{
	int num=0;
	if(c>=128){
		num++;
		c-=128;
	}
	if(c>=64){
		num++;
		c-=64;
	}
	...
	return num;
}