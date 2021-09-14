int lca(int u, int v){
  if(depth[v] < depth[u])
    swap(u,v);
  v = ancestro(v, depth[v]-depth[u]);
  if(u==v) return u;
  for(int k = log_maxn;k >= 0; k--){
    if(P[u][k] != P[v][k]){
      u=P[u][k];
      v=P[v][k];
    }
  }
  return P[u][0];
}