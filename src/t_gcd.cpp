//a>=0,b>0
template< class T > T gcd(T a,T b)
{
    while(b ^= a ^= b ^= a %= b) ;
    return a;
}
