#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define lc p<<1
#define rc p<<1|1
#define int long long
struct node{
	int l,r,sum,add;
}tr[N*4];
char a[N];
int w[N];

void pushup(int p){
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}
 
void pushdown(int p){
	if(tr[p].add){
		tr[lc].sum=tr[lc].r-tr[lc].l+1-tr[lc].sum;
		tr[rc].sum=tr[rc].r-tr[rc].l+1-tr[rc].sum;
		tr[lc].add^=1;
		tr[rc].add^=1;
		tr[p].add=0;	
	}
}

void build(int p,int l,int r){
	if(l==r){
		tr[p].l=tr[p].r=l;
		tr[p].sum=w[l];
		return;
	}
	tr[p].l=l,tr[p].r=r;
	int m=(l+r)/2;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}

void update(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y){
		tr[p].sum=tr[p].r-tr[p].l+1-tr[p].sum;
		tr[p].add^=1;
		return;
	}
	int m=(tr[p].l+tr[p].r)/2;
	pushdown(p);
	if(x<=m) update(lc,x,y);
	if(y>m) update(rc,x,y);
	pushup(p);
}

int query(int p,int x,int y){
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].sum;
	int m=(tr[p].l+tr[p].r)/2;
	pushdown(p);
	int sum=0;
	if(x<=m) sum+=query(lc,x,y);
	if(y>m) sum+=query(rc,x,y);
	return sum;
}

signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		w[i]=a[i]-'0';
	build(1,1,n);
	while(m--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==0){
			update(1,x,y);
		}
		if(op==1){
			cout<<query(1,x,y)<<endl;
		}
	}
	return 0;
}





 
