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
int main()
{
	int L,M;
	//×¢Òâ4Î¬¾ØÕó¼´¿É
	//{{0,0,1,1},{1,1,0,0},{0,1,0,0},{0,0,1,0}};
	Matrix m(4);
	m.set_zero();
	m[0][3]=1;m[0][2]=1;
	m[1][0]=1;m[1][1]=1;
	m[2][1]=1;
	m[3][2]=1;
	while(scanf("%d%d",&L,&M)==2)
	{
		Matrix msum(4);
		MOD=M;

		if(L<=1)
			printf("0\n");
		else
		{
			t_pow(m,L-2,msum);
			int i,j,sum=0;
			for(i=0;i<4;++i)
				for(j=0;j<4;++j)
				{
					sum+=msum[i][j];
					sum%=M;
				}
			printf("%d\n",sum);
		}
	}
}