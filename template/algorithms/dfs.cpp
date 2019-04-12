/*@method_info
name: Búsqueda en profundidad
category: graphs, dfs
*/

int V;
vi dfs_num(V,0); // vector de visitados. Inicialmente a 0
vector<vii> AdjList; // lista de adyacencia

//Búsqueda en profundidad. O(V+E);
void dfs(int u){
  dfs_num[u]=1;
  for (int j=0; j<(int)AdjList[u].size();j++ ){
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == 0)
      dfs(v.first);
  }
}
