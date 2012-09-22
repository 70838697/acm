//a>=0,b>=0
template< class T >T gcd( T a, T b )
{
    return( b ? a : gcd( b, a % b ));
}
