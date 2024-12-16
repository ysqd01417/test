#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	int left,right;
	int value=0,lazy=0;
}tree[400005];
int a[100005];
inline void build(int l,int r,int root){
	tree[root].left=l,tree[root].right=r;
	if(tree[root].left==tree[root].right){
		tree[root].value=a[l];
		return;
	} 
	int mid=(tree[root].left+tree[root].right)/2;
	build(l,mid,2*root);
	build(mid+1,r,2*root+1);
	tree[root].value=tree[root*2].value+tree[root*2+1].value;
} 
inline void spread(int root){
	if(tree[root].left==tree[root].right){
		return;
	}
	int lazy=tree[root].lazy;
	if(lazy!=0){
		tree[root*2].lazy+=lazy;
		tree[root*2+1].lazy+=lazy;
		tree[root*2].value+=lazy*(tree[root*2].right-tree[root*2].left+1);
		tree[root*2+1].value+=lazy*(tree[root*2+1].right-tree[root*2+1].left+1);
		tree[root].lazy=0;
	}
}
inline int query(int root,int l,int r){
	if(tree[root].left>=l&&tree[root].right<=r){
		return tree[root].value;
	}
	int ans=0;
	spread(root);
	int mid=(tree[root].left+tree[root].right)/2;
	if(l<=mid) ans+=query(root*2,l,r);
	if(r>mid) ans+=query(root*2+1,l,r);
	return ans;
} 
inline void update(int root,int l,int r,int v){
	if(tree[root].left>=l&&tree[root].right<=r){
		tree[root].value+=v*(tree[root].right-tree[root].left+1);
		tree[root].lazy+=v;
		return;
	}
	spread(root);
	int mid=(tree[root].left+tree[root].right)/2;
	if(l<=mid) update(root*2,l,r,v);
	if(r>mid) update(root*2+1,l,r,v);
	tree[root].value=tree[root*2].value+tree[root*2+1].value;
}
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,n,1);
	while(m--){
		int op,x,y;
	    scanf("%lld",&op);
		if(op==1){
			int l,r,v;
			scanf("%lld%lld%lld",&l,&r,&v);
			update(1,l,r,v);
		}else{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(1,x,y));
		}
	}
	return 0;
}
