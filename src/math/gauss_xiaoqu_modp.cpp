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
//solve Ax=b mod P, the solution will be stored in b[],det=detA
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
        dmax=inv(A[i*n+i],P);
        for(int k=i; k<n; k++)a[i*n+k]=(dmax*a[i*n+k])%P;
        for(int k=i+1; k<n; k++)
        {
            T m=a[k*n+i];
            for(int p=i+1; p<n; p++)
                A[k*n+p]=(A[k*n+p]-m*A[i*n+p])%P;
            b[k]=(b[k]-m*b[i])%P;
        }
    }
    for(i=n-1; i>=0; i--)//solve
    {
        T ab=0;
        for(int k=i+1; k<n; k++)
            ab=(ab+a[i][k]*b[k])%P;
        b[i]=((b[i]-ab)*inv(a[i*n+i],P))%P;
        if(b[i]<0)b[i]+=P;
    }
    return 1;
}
