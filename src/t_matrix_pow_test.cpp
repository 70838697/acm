template<class T> inline
void t_pow(const T &x, unsigned int n, T &z)
{
	T temp(x),temp_x(x);
	z.set_one();

	T::copy(x,temp_x);
	while(n)
	{
		if (n&1)
		{
			T::multiple(temp_x,z,temp);
			T::copy(temp,z);
		}
		if (n >>= 1)
		{
			T::multiple(temp_x,temp_x,temp);
			T::copy(temp,temp_x);
		}
	}
}
int MOD=7608;
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
};
#include <stdio.h>
typedef t_matrix<int,int> Matrix;

// test
//fib(0)=1,fib(1)=1,fib(2)=2
void fib(int m)
{
	Matrix a(2),y(2);
	a[0][0]=1;a[0][1]=1;
	a[1][0]=1;a[1][1]=0;
	MOD=1024*1024;

	t_pow(a,m,y);
	//fib(m+1)
	printf("fib(%d)=%d\n",m,y[0][0]);

	//t_pow_sum(a,m,y);
	//fib(m+1)
	//printf("sum(fib(i))=%d,i=1,..,%d\n",y[0][0],m);

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
fib(10)=89
fib(37)=290857
fib(77)=429672
fib(100)=14533
fib(500)=587202
fib(1000)=352493
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
