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

////////////////////////////////////////////////
//注意 矩阵大小设定成30X30修改文件头
//注意__int64是比较费时的，所以要修改中间结果类型，避免int64运算，不然程序会超时
typedef t_matrix<int,int> Matrix;
#include<map>
#include<stdio.h>
void solve_hdu_2254()
{
	//题目的主要点在于考察城市标号可能不存在，城市标号并不是0～30.
	int n;
	std::map<int,int> amap;
	MOD=2008;
	Matrix a(31),sum1(31),sum2(31);

	while(scanf("%d",&n)==1)
	{
		a.set_zero(); //注意点,在这里清除数据，可以在这里直接申明即可
		amap.clear();//保存点
		int inum=0;
		while(n--)
		{
			int p1,p2;
			scanf("%d%d",&p1,&p2);
			//如果不存在就插入
			if(amap.count(p1)==0)amap[p1]=inum++;
			if(amap.count(p2)==0)amap[p2]=inum++;
			a[amap[p1]][amap[p2]]++;
		}
		a.n=sum1.n=sum2.n=(inum);
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int v1,v2,t1,t2;
			int path1=0,path2=0;
			scanf("%d%d%d%d",&v1,&v2,&t1,&t2);
			//要判断点不存在的情况
			if(t2<t1|| amap.count(v1)==0 || amap.count(v2)==0)
			{
				printf("0\n");
				continue;
			}
			if(t1>1)
			{
				t_pow_sum(a,t1-1,sum1);
				path1=sum1[amap[v1]][amap[v2]];
			}
			if(t2>=1)
			{
				t_pow_sum(a,t2,sum2);
				path2=sum2[amap[v1]][amap[v2]];
			}
			printf("%d\n", (path2-path1+2008)%2008);
		}
	}
}
int main()
{

	solve_hdu_2254();
	return 0;
}