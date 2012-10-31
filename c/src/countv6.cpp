int count(unsigned char c)
{
	c=(c&0x55)+((c>>1)&0x55);
	c=(c&0x33)+((c>>2)&0x33);
	c=(c&0xF)+((c>>4)&0xF);
	return c;
}