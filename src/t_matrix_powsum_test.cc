﻿int MOD=7608;
#include <string.h>
template<class T=int,class T_max=int> struct t_matrix
{
	T *data;
	int n;

	t_matrix(const t_matrix&src):n(src.n){
		data= (T *) new T[src.n*src.n];
		copy(src,*this);
	}
	t_matrix(int n_):n(n_){
		data= (T *) new T[n_*n_];
	}
	~t_matrix(){
		delete []data;
	}
	
	void set_one(){
		set_zero();
		for(int i=0;i<n;++i)data[i*n+i]=1;
	}
	void set_zero(){
		memset(data, 0, sizeof(T)*n*n);
	}
	static void copy(const t_matrix &src,t_matrix &dest)
	{
		memcpy(dest.data,src.data, sizeof(T)*src.n*src.n);
	}
	static void multiple(const t_matrix &x,const t_matrix &y, t_matrix &z)
	{
		int i,j,k,n=x.n;
		T t;

		for(i=0;i<n;i++){
			T* xdi=x.data+i*n;
			for(j=0;j<n;j++)
			{
				t=0;
				
				for(k=0;k<n;k++){
					t+=(xdi[k]*(T_max)y.data[k*n+j])%MOD;
					t%=MOD;
				}//module
				z[i][j]=t;
			}
		}
	}
	T* operator[](unsigned int index)
	{
		return data+index*n;
	}
	//another function needed;
	static void add(const t_matrix&  x,const t_matrix&  y,t_matrix&  z)
	{
		int i,j;
		for(i=0;i<x.n;i++)
			for(j=0;j<x.n;j++)
				z.data[i*x.n+j]=(x.data[i*x.n+j]+(T_max)y.data[i*x.n+j])%MOD;//module
	}
};
#include<vector>
template <class T>void m_pow_with_saved(const std::vector < T > & x_p,unsigned int n, T &y)
{
	T temp(y);
	y.set_one();
	for(int k=1;n;++k,n>>=1)
	{
		if ((n & 1) != 0)
		{
			y.multiple(x_p[k],y,temp);
			y.copy(temp,y);
		}
	}
}

template <class T> void m_pow_sum1(const std::vector<T> & x_p,unsigned int n, T & y)
{
	y.set_zero();
	if(n==0)return;
	if(n==1) y.copy(x_p[1],y);
	else
	{
		T temp(y);
		m_pow_sum1(x_p,n>>1,temp);
		T::add(temp,y,y);
		T temp2(y);
		m_pow_with_saved(x_p,n>>1,temp2);
		T temp3(y);
		T::multiple(temp,temp2,temp3);
		T::add(temp3,y,y);
		if(n&1)
		{
			T::multiple(temp2,temp2,temp3);
			T::multiple(temp3,x_p[1],temp2);
			T::add(temp2,y,y);
		}
	}

}
template <class T>void t_pow_sum(T x, unsigned int n, T& y)
{
	//calculate x^1 x^2 x^4 ... x^logn
	unsigned int i=0,logn,n2=n;
	for(logn=0,n2=n;n2;logn++,n2 >>= 1);
	std::vector<T> pow_arry(logn==0?2:(logn+1),x);
	pow_arry[0].set_one();
	T::copy(x,pow_arry[1]);
	for(i=1;i<logn;i++)
	{
		T::multiple(pow_arry[i],pow_arry[i],pow_arry[i+1]);
	}

	m_pow_sum1(pow_arry,n,y);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//上面是计算级数的类部分
/////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

//要用__int64存储，不然模1024*1024会溢出
typedef t_matrix_type<int,__int64> Matrix;
// test
//fib(0)=1,fib(1)=1,fib(2)=2
void fib(int m)
{
	Matrix a(2),y(2);
	a[0][0]=1;a[0][1]=1;
	a[1][0]=1;a[1][1]=0;
	MOD=1024*1024;

	//t_pow(a,m,y);
	//fib(m+1)
	//printf("fib(%d)=%d\n",m,y[0][0]);

	t_pow_sum(a,m,y);
	//fib(m+1)
	printf("sum(fib(i))=%d,i=1,..,%d\n",y[0][0],m);

}
int test()
{
	fib(10);
	fib(37);
	fib(77);
	fib(100);
	fib(500);
	fib(1000);
	return 0;
}
#if 0
//测试结果
sum(fib(i))=231,i=1,..,10
sum(fib(i))=622281,i=1,..,37
sum(fib(i))=205283,i=1,..,77
sum(fib(i))=340299,i=1,..,100
sum(fib(i))=731311,i=1,..,500
sum(fib(i))=729635,i=1,..,1000
#endif

//*/


void solve_xxxx()
{
	test();
}
int main()
{

	solve_xxxx();
	return 0;
}
