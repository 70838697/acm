#include<cmath>
using namespace std;
#typedef int T
void swap(T *a,double *b,T n)
{
    T c;
    while(n--)
    {
        c=*a;
        *a++=*b;
        *b++=c;
    }
}
//solve Ax=b, the solution will be stored in b[],det=detA
T xiaoqu(T *A,T *b,int n)
{
    T det=1,det2=1;
    int i;
    for( i=0; i<n-1; i++)
    {
        int max=i;
        //find a non-zero row
        while(!A[max*n+i] && max<n)max++;
        //can not solve
        if(max==n)return 0;
        if(max!=i)//swap row
        {
            T c=b[i];
            b[i]=b[max];
            b[max]=c;
            swap(a+i*n,a+max*n,n);
            det=-det;
        }
        dmax=A[i*n+i];
        for(int k=i+1; k<n; k++)
        {
            T gc=gcd(abs(a[k*n+i]),abs(dmax));
            T m1=dmax/gc,m2=a[k*n+i]/gc;
            for(int p=i+1; p<n; p++)
                A[k*n+p]-=A[k*n+p]*m2-m1*A[i*n+p];
            b[k]=b[k]*m2-m1*b[i];
            det2*=m2;
        }
        det*=dmax;
    }
    for(i=n-1; i>=0; i--)//solve
    {
        T ab=0;
        for(int k=i+1; k<n; k++)
            ab+=a[i][k]*b[k];
        b[i]=(b[i]-ab)/a[i*n+i];
    }
    return det/det2;
}
