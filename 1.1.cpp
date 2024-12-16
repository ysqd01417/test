#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, a[N];
map<int, int> pos;
signed main(){
	cin >> n >> m;
	for (int i = 1; i <= n;i++){
		cin >> a[i];
		if(pos[a[i]]==0)
			pos[a[i]] = i;
	}
	while (m--){
		int q;
		cin >> q;
		if(pos[q])
			cout << pos[q] << " ";
		else
			cout << -1 << " ";
	}
	return 0;
}
