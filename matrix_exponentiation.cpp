#include<bits/stdc++.h>
#define mod 1000000007
#define ull unsigned long long int
#define re(i,n) for(i=0;i<n;i++)
using namespace std;
unsigned long long int** mmul(unsigned long long int** m,unsigned long long int** n,unsigned long long int N)
{
    unsigned long long int i,j,k,**result;
    result = new unsigned long long int* [N];
    re(i,N)
    result[i]=new unsigned long long int[N];
    re(i,N)
    re(j,N)
    {
        result[i][j]=0;
        re(k,N)
        result[i][j]+=m[i][k]*n[k][j];
    }
	return result;
}
unsigned long long int** mpow(unsigned long long int** matrix,unsigned long long int p,unsigned long long int n)
{
    unsigned long long int **m,i,j;
    m = new unsigned long long int* [n];
    re(i,n)
    	m[i]=new unsigned long long int[n];
    re(i,n)
        re(j,n)
        {
            if(i==j)
                m[i][j]=1;
            else
                m[i][j]=0;
        }
    if(p==0)
        return m;
    else if(p==1)
        return matrix;
    while(p)
    {
        if(p&1)
            m = mmul(m,matrix,n);
        p>>=1;
            matrix = mmul(matrix,matrix,n);
    }
    return m;
}
int main()
{
    unsigned long long int n,i,j,p;
    unsigned long long int** matrix;
    cout<<"Enter N  : ";
    cin>>n;
            matrix = new unsigned long long int* [n];
    re(i,n)
    matrix[i]=new unsigned long long int[n];
    cout<<"Enter Elements :\n";
    re(i,n)
    	re(j,n)
    		cin>>matrix[i][j];
    cout<<"Enter Power : ";
    cin>>p;
    matrix=mpow(matrix,p,n);
    cout<<'\n';
    re(i,n)
    {
        re(j,n)
        cout<<matrix[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
