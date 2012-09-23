//we must define MOD,T_max must be a type larger than T to avoid overflowing
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