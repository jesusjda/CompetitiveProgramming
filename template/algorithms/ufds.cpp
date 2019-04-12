/*@method_info
name: Union Find Disjoint Sets
category: graphs, ufds
*/


struct UFDS{
  vi p, r;

  UFDS (int N){
    p.assign(N,0); r.assign(N,0);
    for(int j=0; j<N; j++) p[j]=j;
  }

  int find(int i){
    if (p[i]==i) return i; else return find(p[i]);
  }

  void unionn(int i, int j){
    int x=find(i), y=find(j);
    if (x!=y){
      if (r[x]>r[y])
	p[y]=x;
      else{
	p[x]=y;
	if (r[x]==r[y])
	  r[y]++;
      }
    }
  }
};
