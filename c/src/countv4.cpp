int count(unsigned char c)
{
	switch(c){
	case 0:return 0;
	case 1,2,4,8,16,32,64,128: return 1;
	....
	case 255:return 8;
	}
}