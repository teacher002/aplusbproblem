#include <iostream>
using namespace std;
const int N =1e2+10;
int n,m;
int dx[]={1,2,2,1};
int dy[]={-2,-1,1,2};
int a[N];
bool b[N][N];
bool check(int x,int y)
{
	if(x>=1&&y>=1&&x<=n&&y<=m&&b[x][y]==0&&b[n][m]==0)
	{
		return 1;
	}
	return 0;
}
void dfs(int x,int y,int z)
{
	if(x==n&&y==m)
	{
		b[n][m]=1;
		for(int i=1;i<=z-1;i++)
		{
			printf("%d ",a[i]);
		}
		exit(0);
	}
	for(int i=0;i<=3;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(check(xx,yy))
		{
			a[z]=i+1;
			b[x][y]=1;
			dfs(xx,yy,z+1);
		}
	}
}
int main()
{
	cin>>n>>m;
	dfs(1,1,1);
	cout<<-1;
	return 0;
}
