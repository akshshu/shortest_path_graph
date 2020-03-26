#include <iostream>
#include <limits.h>
using namespace std;
struct nodes {
		int dis;
		int visited;
};
int** enter_weight_u(int n,char c)
{
		int **a=new int*[n];                           //dynamically created so that it remains even after return
		for(int i=0; i<n; i++)
		{
				a[i]=new int[n];
				for(int j=0; j<=i; j++)
				{
						if(i==j)
								a[i][j]=0;
						else
						{
								cout<<"enter the weight of edge between "<<i<<" and "<<j<<" edge : ";
								cin>>a[i][j];
								a[j][i]=a[i][j];
						}
				}
		}       return a;
}
int** enter_weight_d(int n,char c)
{

		int **a=new int*[n];                           //dynamically created so that it remains even after return
		for(int i=0; i<n; i++)
		{
				a[i]=new int[n];

				for(int j=0; j<n; j++)
				{
						if(i==j)
								a[i][j]=0;
						else
						{
								cout<<"enter the weight of edge between "<<i<<" and "<<j<<" edge : ";
								cin>>a[i][j];
						}
				}
		}       return a;
}

int visit_min(int k,nodes nod[],int **a,int n)
{
		int min=INT_MAX,p;
		for(int i=0; i<n; i++)
		{
				if(k!=i)
				{
						if(nod[i].visited==0)
						{
								if(a[k][i]>0)
								{
										if(a[k][i]+nod[k].dis<nod[i].dis)
										{
												nod[i].dis=a[k][i]+nod[k].dis;
										}
								}
						}
				}
		}
		for(int i=0; i<n; i++)
		{
				if(a[k][i]<INT_MAX&nod[i].visited==0)
				{
						if(nod[i].dis<min)
						{ min=nod[i].dis;
						  p=i;}
				}
		}
		return p;
}
int main()
{
		int n,src,k,kin;
		char c;
		cout<<"enter the no of node"<<endl;
		cin>>n;
		cout<<"Press d for directed graph or Press u for undirected graph";
    cin>>c;
    cout<<endl;
		int dis[n];
		nodes nod[n];
		int **a;
    if(c=='u'||c=='U')
		a=enter_weight_u(n,c);
    else
    a=enter_weight_d(n,c);
		cout<<"choose a source out of the given nodes";
		cin>>src;
		for(int i=0; i<n; i++)
		{
				nod[i].dis=INT_MAX;
				nod[i].visited=0;
		}
		nod[src].dis=0;
		k=n;
		kin=src;
		while(k--)
		{ cout<<endl<<kin<<endl;
		  nod[kin].visited=1;
		  src=visit_min(kin,nod,a,n);
		  kin =src;}
		return 0;
}
