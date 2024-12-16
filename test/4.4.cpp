#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
const int inf=0x3f3f3f3f,maxn=5e5+7;
using namespace std;
int n,m;
double t[maxn<<2],sa[maxn<<2],sb[maxn<<2];  
void push_up(int p){
    sa[p]=sa[ls(p)]+sa[rs(p)];
    sb[p]=sb[ls(p)]+sb[rs(p)];
}
void build(int p,int l,int r){
    if(l==r){
        scanf("%lf",&sa[p]); sb[p]=1.0*sa[p]*sa[p]; return;
    }
    build(ls(p),l,mid); build(rs(p),mid+1,r);
    push_up(p);
}
void maketag(int p,int l,int r,double k){
    sb[p]+=2.0*k*sa[p]+1.0*(r-l+1)*k*k;
    sa[p]+=1.0*(r-l+1)*k; t[p]+=k;
}
void push_down(int p,int l,int r){
    if(!t[p]) return;
    maketag(ls(p),l,mid,t[p]); maketag(rs(p),mid+1,r,t[p]);
    t[p]=0;
}

double ask_a(int p,int l,int r,int L,int R){
    if(l>R||r<L) return 0;
    if(l>=L&&r<=R) return sa[p];
    push_down(p,l,r);
    return ask_a(ls(p),l,mid,L,R)+ask_a(rs(p),mid+1,r,L,R);
}

double ask_b(int p,int l,int r,int L,int R){
    if(l>R||r<L) return 0;
    if(l>=L&&r<=R) return sb[p];
    push_down(p,l,r);
    return ask_b(ls(p),l,mid,L,R)+ask_b(rs(p),mid+1,r,L,R);
}

void update(int p,int l,int r,int L,int R,double x){
    if(r<L||R<l) return;
    if(L<=l&&r<=R){
        maketag(p,l,r,x); return;
    }
    push_down(p,l,r);
    update(ls(p),l,mid,L,R,x); update(rs(p),mid+1,r,L,R,x);
    push_up(p);
}

int main(){
    scanf("%d%d",&n,&m);
    build(1,1,n);
    while(m--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==2){ 
            printf("%.4lf\n",1.0*ask_a(1,1,n,x,y)/(y-x+1));
        }
        else if(op==1){  
            double z; scanf("%lf",&z);
            update(1,1,n,x,y,z);
        }
        else if(op==3){  
            double sum1=ask_b(1,1,n,x,y)*1.0/(y-x+1),sum2=ask_a(1,1,n,x,y)*1.0/(y-x+1);  
            double ans=sum1-sum2*sum2;
            printf("%.4lf\n",ans);
        }
    }
    return 0;
}

