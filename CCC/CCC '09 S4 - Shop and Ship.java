import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.*;

public class ShopandShip {
    static class FastScanner {
        private BufferedReader br;
        private StringTokenizer st;

        public FastScanner (InputStream in){
            br = new BufferedReader(new InputStreamReader(in));
            st = new StringTokenizer("");
        }
        private String next() throws IOException {
            if (st.hasMoreTokens()) return st.nextToken();
            else st = new StringTokenizer(br.readLine());
            return next();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        public String nextLine() throws IOException {
            if (!st.hasMoreTokens()) return br.readLine();
            String cont = st.nextToken();
            while (st.hasMoreTokens()) {
                cont += " " + st.nextToken();
            }
            return cont;
        }
    }
    static int minDistance(int dist[], boolean sptSet[], int V) {
        int min = Integer.MAX_VALUE;
        int ind =-1;

        for (int v = 1; v <= V; v++)
            if (!sptSet[v] && dist[v] < min) {
                min = dist[v];
                ind = v;
            }

        return ind;
    }
    static int[] dijkstra(int graph[][], int V, int d) {
        int dis[] = new int[V+1];
        boolean visited[] = new boolean[V+1];

        Arrays.fill(dis, Integer.MAX_VALUE);
        dis[d] = 0;
        for (int i = 1; i <= V; i++) {
            int u = minDistance(dis, visited, V);

            if (u==-1) continue;

            visited[u] = true;
            for (int j = 1; j <= V; j++)
                if (!visited[j] && graph[u][j]!=0 && dis[u] + graph[u][j] < dis[j])
                    dis[j] = dis[u] + graph[u][j];
        }
        return dis;
    }

    public static void main (String[] args) throws IOException{
        FastScanner sc = new FastScanner(System.in);
        int n = sc.nextInt(); //vertices
        int m = sc.nextInt(); //edges
        int[][] graph = new int[n + 1][n + 1];

        for (int i = 1; i <=m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int w = sc.nextInt();
            if (a != b && (w<graph[a][b]||graph[a][b]==0)) {
                graph[a][b] = w;
                graph[b][a] = w;
            }
        }
        int k = sc.nextInt();
        int[] cost = new int[n + 1];
        Arrays.fill(cost, Integer.MAX_VALUE);
        for (int i = 1; i <= k; i++ ) {
            cost[sc.nextInt()] = sc.nextInt();
        }
        int d = sc.nextInt();
        int[] ans = dijkstra(graph, n, d);
        int min = Integer.MAX_VALUE;
        for (int i = 1; i < ans.length; i++) {
            if (cost[i]==Integer.MAX_VALUE)
                ans[i] = Integer.MAX_VALUE;
            else
                ans[i] += cost[i];
            if (ans[i] < min)
                min = ans[i];
        }
        System.out.println(min);

    }
}