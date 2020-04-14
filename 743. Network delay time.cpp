class Solution {
public:
    typedef pair<int, int> pp;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<vector<int>> adj(N+1,vector<int>(N+1,-1));
        
        for( auto a:times ){
            adj[a[0]][a[1]] = a[2];
        }
        vector<int> dist(N+1,INT_MAX);
        dist[K]=0;
       priority_queue<pp,vector<pp> , greater<pp>> pq;
        pq.push(make_pair(0,K));
        
        while(!pq.empty()){
            int nv=pq.top().second;
            pq.pop();
            
            for(int i=1;i<=N;i++){
                if(adj[nv][i]!=-1){
                   int weight= adj[nv][i];
                 //   dist[i] = min(dist[i] ,  )
                if (dist[i] > dist[nv] + weight) 
            { 
                dist[i] = dist[nv] + weight; 
                pq.push(make_pair(dist[i], i)); 
            } 
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<N+1;i++){
          //  cout<<dist[i]<<" ";
            if(i==K)
                continue;
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
        
    }
};