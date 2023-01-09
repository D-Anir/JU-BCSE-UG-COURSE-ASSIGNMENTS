public class part2 {
    private boolean dls_util(int v,boolean[] visited,ArrayList<Integer> order,int limit,ArrayList<Integer> path)
    {
        visited[v]=true;
        order.add(v); path.add(v);
        if(isGoal(v)) return true;
        if(limit<=0) { path.remove(path.lastIndexOf(v)); return false; }
        for(int i=0;i<n;i++)
        {
            if(a[v][i]<Integer.MAX_VALUE&&!visited[i])
            if(dls_util(i,visited,order,limit-1,path)) return true;
        
        }
        path.remove(path.lastIndexOf(v));
        return false;
    }
    void dls(int limit)
    {
        ArrayList<Integer> order=new ArrayList<>();
        ArrayList<Integer> path=new ArrayList<>();
        boolean[] visited=new boolean[n];
        dls_util(start,visited,order,limit,path);
        System.out.println("Using DLS:");
        if(isGoal(order.get(order.size()-1)))
        {
            System.out.println("Goal Node "+order.get(order.size()-1)+" found");
            System.out.println("Order:");
            for(int vv:order)
            System.out.print(vv+" ");
            System.out.println();
            System.out.println("Path:");
            for(int vv:path)
            System.out.print(vv+" ");
            System.out.println();
        }
        else
        System.out.println("No goal node found");
    }
    void ids()
    {
        ArrayList<Integer> order=new ArrayList<>();
        ArrayList<Integer> path=new ArrayList<>();
        boolean[] visited=new boolean[n];
        boolean flag=false;
        int limit;
        for(limit=0;limit<100;limit++)
        {
            path.clear();
            for(int i=0;i<n;i++)
            visited[i]=false;
            dls_util(start,visited,order,limit,path);
            if(isGoal(order.get(order.size()-1)))
            {
                flag=true; break;
            }
        }
        System.out.println("Using IDS:");
        if(flag)
        {
            System.out.println("Goal Node "+order.get(order.size()-1)+" found");
            System.out.println("Order:");
            for(int vv:order)
            System.out.print(vv+" ");
            System.out.println();
            System.out.println("Path:");
            for(int vv:path)
            System.out.print(vv+" ");
            System.out.println();
        }
        else
        System.out.println("No goal node found");
    }
    private boolean ibs_util(int v,boolean[] visited,ArrayList<Integer> order,int limit,ArrayList<Integer> path)
    {
        visited[v]=true; int b=0;
        order.add(v); path.add(v);
        if(isGoal(v)) return true;
        for(int i=0;i<n;i++)
        {
            if(a[v][i]<Integer.MAX_VALUE&&!visited[i])
            {
            if(ibs_util(i,visited,order,limit,path)) return true;
            b++;
            }
            if(b==limit) break;
        }
        path.remove(path.lastIndexOf(v));
        return false;

    }
    void ibs()
    {
        ArrayList<Integer> order=new ArrayList<>();
        ArrayList<Integer> path=new ArrayList<>();
        boolean[] visited=new boolean[n];
        boolean flag=false;
        int limit;
        for(limit=1;limit<100;limit++)
        {
            path.clear();
            for(int i=0;i<n;i++)
            visited[i]=false;
            ibs_util(start,visited,order,limit,path);
            if(isGoal(order.get(order.size()-1)))
            {
                flag=true; break;
            }
        }
        System.out.println("Using IBS:");
        if(flag)
        {
            System.out.println("Goal Node "+order.get(order.size()-1)+" found");
            System.out.println("Order:");
            for(int vv:order)
            System.out.print(vv+" ");
            System.out.println();
            System.out.println("Path:");
            for(int vv:path)
            System.out.print(vv+" ");
            System.out.println();
        }
        else
        System.out.println("No goal node found");
    }

    public static void main(String[] args){
            
    }
}
