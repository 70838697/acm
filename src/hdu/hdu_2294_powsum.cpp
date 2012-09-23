__int64 MOD=7608;
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

typedef t_matrix<__int64,__int64> Matrix;

#include<stdio.h>

void solve_2294()
{
    unsigned int T,num,K;
    //注意30维矩阵即可
    int i;

	MOD=1234567891; //注意设置取模的值
	Matrix a(30),msum(30);

    scanf("%u",&T);
    while(T--)
    {
        scanf("%d%d",&num,&K);
        if(K>num)
        {
            printf("0\n");
            continue;
        }
        //if(K==1)
        //{
            //printf("%d\n",((__int64)K*(num-K+1))%mod);continue;
        //}
		a.n=msum.n=K;
		a.set_zero();
        for(i=0;i<K;i++)
        {
            //已经有(i+1)种颜色的，再从(i+1)种中任选一种/个放上去还是(i+1)
            a[i][i]=(i+1);
            //已经有i种颜色，再选k-i种中任选一种/个放上去就是i
            if(i!=0)a[i][i-1]=K-i;
        }
        t_pow_sum(a,num-1,msum); //A^1+...+A^num-1
        //for 1 kind A^0
        Matrix one(K);
		one.set_one();
		Matrix::add(one,msum,msum);
        
		//初始时长度为1时，单一颜色的有K种，其余的为0。
		int ir=((__int64)K*msum[K-1][0])%MOD;
        printf("%d\n",ir);
    }
}


int main()
{

	solve_2294();
	//fib(3);

	return 0;
}