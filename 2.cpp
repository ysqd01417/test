#include <bits/stdc++.h>
using namespace std;
int n,ans=-1,a[1005],s[10000][10000];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=2;i<n*2;i++)
		for(int j=i-1;i-j<n&&j>=1;j--)
			for(int k=j;k<i;k++){
				s[j][i]=max(s[j][i],s[j][k]+s[k+1][i]+a[j]*a[k+1]*a[i+1]);
				ans=max(ans,s[j][i]);
			}
	cout<<ans;
	return 0;
}
