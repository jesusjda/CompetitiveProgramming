/*@method_info
name: Búsqueda en anchura
category: graphs, bfs
*/

int V;
vi distance(V, INF); // vector de distancias
vector<vii> AdjList; // lista de adyacencia

//Búsqueda en anchura
void bfs(int s){
  d[s] = 0; //Distancia desde s
  queue<int> q; q.push(s);
  while(!q.empty()){
    int u=q.front(); q.pop();
    for (int j=0; j<AdjList[u].size(); j++){
      ii v= AdjList[u][j];
      if (distance[v.first] == INF){
	distance[v.first]= distance[u] + 1;
	q.push(v.first);
      }
    }
  }
}
