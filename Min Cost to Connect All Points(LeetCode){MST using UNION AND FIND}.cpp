/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.*/




class Solution {
public:
    vector<int> parent;
    int find(int x)
    {
        if(parent[x]==x||parent[x]==-1)
            return x;
        return find(parent[x]);
    }
    int minCostConnectPoints(vector<vector<int>>& v) {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            parent.push_back(-1);
        }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minhp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
            minhp.push({abs(v[i][0]-v[j][0])+abs(v[i][1]-v[j][1]),i*1001+j});
            }
        }
        long long minCost=0;
        pair<int,int> p;
        int i,j;
        while(!minhp.empty())
        {
            p=minhp.top();
            minhp.pop();
            i=p.second/1001;
            j=p.second%1001;
           
            int p1=find(i);
            int p2=find(j);
            if(p1!=p2)
            {
                minCost+=p.first;
                parent[p1]=p2;
            }
            
            //cout<<p.first<<" i="<<i<<" j=:"<<j<<"parent i="<<parent[i]<<"paren[j]="<<parent[j]<<"\n";
        }
                       return minCost;
    }
};

//p1 p2
