
#include<bits/stdc++.h>
using namespace std;
int siz[30005],fd[30005],fro[30005],t;
void init(){
	for(int i=1;i<30001;i++){
		fd[i]=i;
		siz[i]=1;
	}
}
int fid(int x){
	if(fd[x]==x)return x;
	int fx=fid(fd[x]);
	fro[x]+=fro[fd[x]];
	return fd[x]=fx;
}

int main(){
	scanf("%d",&t);
	init();
	while(t--){
		char opt;
		int i,j;
		opt=getchar();
		while(opt!='M' && opt!='C')opt=getchar();
		scanf("%d%d",&i,&j);
		int fi=fid(i),fj=fid(j);
		if(opt=='M'){
			fro[fi]+=siz[fj];
			fd[fi]=fd[fj];
			siz[fj]+=siz[fi];
			siz[fi]=0;
		}else{
			if(fi!=fj){
				printf("-1\n");
				continue;
			}else{
				printf("%d\n",abs(fro[i]-fro[j])-1);
			}
		}
	}
	return 0;
}
