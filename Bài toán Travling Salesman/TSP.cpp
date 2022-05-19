#include<bits/stdc++.h>

using namespace std;

#define maxn 30

int f[maxn],a[maxn][maxn],d[maxn],n,m;
long long min1,k[600000][20][20];
void xuli()
{
    long long ans=0;
    for(int i=1;i<n;i++) ans=ans+a[f[i]][f[i+1]];
    min1=min(min1,ans+a[f[n]][f[1]]);
}

void Hoanvi(int x)
{
    if(x==n+1)
    {
        xuli();
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==true) continue;

        f[x]=i;d[i]=true;
        Hoanvi(x+1);d[i]=false;
    }
}

void PB1()
{
    min1=1000000000000000;
    Hoanvi(1);
    cout<<min1<<endl;
}

long long qhd(int x,int st,int fn)
{
    if(k[x][st][fn]!=-1) return k[x][st][fn];

    k[x][st][fn]=1000000000000000;

    if(x==(int)(1<<n)-1)
        return k[x][st][fn]=a[fn][st];

    for(int i=0;i<n;i++)
    {
        int u=(x>>i)&1;
        if(u==0) k[x][st][fn]=min(k[x][st][fn],qhd(x+(int)(1<<i),st,i+1)+a[fn][i+1]);
    }

    return k[x][st][fn];
}

void PB2()
{
    memset(k,-1,sizeof(k));
    cout<<qhd(1,1,1)<<endl;
}

int main()
{
    freopen("TSP.INP","r",stdin);
    freopen("TSP.OUT","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) a[i][j]=1000000000;

    for(int i=1;i<=m;i++)
    {
        int x,y,value;cin>>x>>y>>value;
        a[x][y]=value;a[y][x]=value;
    }

    PB1();
    PB2();

}
