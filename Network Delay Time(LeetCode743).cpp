/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 */

class Solution {
public:
    int pardist[101],par[101];
    int rank[101];
    int find(int x)
    {
        if(par[x]==x)
            return x;
        par[x]=find(par[x]);
        return par[x];
    }
    void unionFunction(int x,int y)
    {
        int parX=find(x),parY=find(y);
        if(parX!=parY)
        {
            if(rank[x]<rank[y])
            {
                par[parX]=parY;
                rank[y]+=rank[x];
            }
            else
            {
                par[parY]=parX;
                rank[x]+=rank[y];
            }
        }
        return ;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int vis[101];
        for(int i=0;i<=n;i++)
        {
            pardist[i]=1e6;
            par[i]=i;
            rank[i]=1;
            vis[i]=0;
        }
        pardist[k]=0;
        vis[k]=1;
        vector<vector<vector<int>>> adj(n+1);
        for(auto v:times)
            adj[v[0]].push_back({v[1],v[2]});
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,k});
        while(!q.empty())
        {
            vector<int> v=q.top();
            q.pop();
            
            for(auto neighbour:adj[v[1]])
            {
                if(pardist[neighbour[0]]>neighbour[1]+pardist[v[1]])
                {
                    pardist[neighbour[0]]=neighbour[1]+pardist[v[1]];
                    
                    q.push({pardist[neighbour[0]],neighbour[0]});
                    vis[neighbour[0]]=1;
                }
            }
            
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<pardist[i]<<" ";
            ans=max(ans,pardist[i]);
        }
        if(ans==1e6)
            return -1;
        return ans;
        
        
        
        
    }
};
