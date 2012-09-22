/*调用这些版本时候注意a,b最好都是非负整数*/
template< class T >T gcd( T a, T b )
{
    return( b ? a : gcd( b, a % b ));
}
