class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        if (destination >= n) {
            return false;
        }
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }

        boolean[] visited = new boolean[n];
        visited[source] = true;
        return dfs(adjList, source, destination, visited);
    }

    private boolean dfs(List<List<Integer>> adjList, int source, int destination, boolean[] visited) {
        if (source == destination) {
            return true;
        }
        for (int neighbor : adjList.get(source)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                if (dfs(adjList, neighbor, destination, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
}
