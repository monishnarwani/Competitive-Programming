#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

long long n, m, d = 1;

const int N = 51;
int visited[N], comp;
vector<int> adj[N], rev[N], scc[N];
stack<int> s;

void dfs(int x){
	if(visited[x] == 1) return;
	visited[x] = 1;
	
	for(int i = 0; i < adj[x].size(); i++) dfs(adj[x][i]);
	
	s.push(x);
	
	return;
}

void dfs2(int x, int comp){
	if(visited[x] == 1) return;
	
	visited[x] = 1; scc[comp].pb(x);
	
	for(int i = 0; i < rev[x].size(); i++) dfs2(rev[x][i], comp);
	
	return;
	
}

void sccomp(){
	for(int i = 0; i < n; i++)
		if(!visited[i]){
			dfs(i);
//			tr2("this",i);
		}

	int cur;
	
	for(int i = 0; i < n; i++) visited[i] = 0;
	
	while(!s.empty()){
		cur = s.top(); s.pop();
		
		if(visited[cur] == 1) continue;
		
//		tr2("
		
		dfs2(cur, comp);
		comp++;
		
	}
	return;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb(y);
		adj[y].pb(x);
		rev[x].pb(y);
		rev[y].pb(x);
	}
	
	sccomp();
	
//	tr(comp);
	
	for(int i = 0; i < comp; i++){
		d <<= (scc[i].size()-1);
	}
	
	cout << d << endl;
	
	return 0;
}
