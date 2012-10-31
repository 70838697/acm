#include<cmath>
using namespace std;
void swap(double *a,double *b,int n)
{
    double c;
    while(n--)
    {
        c=*a;
        *a++=*b;
        *b++=c;
    }
}
//solve Ax=b, the solution will be stored in b[],det=detA
double xiaoqu(double *A,double *b,int n)
{
    double det=1.0;
    int i;
    for( i=0; i<n-1; i++)
    {
        int max=i;
        double dmax=fabs(A[i*n+i]);
        for(int j=i+1; j<n; j++)
        {
            if(dmax<fabs(A[j*n+i])) {
                dmax=fabs(A[j*n+i])
                     max=j;
            }
        }
        //dmax=0,can not solve
        if(!dmax)return 0;
        if(max!=i)//swap row
        {
            double c=b[i];
            b[i]=b[max];
            b[max]=c;
            swap(a+i*n,a+max*n,n);
            det=-det;
        }
        dmax=A[i*n+i];
        for(int k=i+1; k<n; k++)
        {
            double m=a[k*n+i]/dmax;
            for(int p=i+1; p<n; p++)
                A[k*n+p]-=m*A[i*n+p];
            b[k]-=m*b[i];
        }
        det*=dmax;
    }
    for(i=n-1; i>=0; i--)//solve
    {
        double ab=0;
        for(int k=i+1; k<n; k++)
            ab+=a[i][k]*b[k];
        b[i]=(b[i]-ab)/a[i*n+i];
    }
    return det;
}
