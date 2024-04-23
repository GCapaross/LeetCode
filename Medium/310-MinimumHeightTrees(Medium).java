import java.util.List;
import java.util.Map;
import java.util.HashMap;


public class 310-MinimumHeightTrees(Medium) {

    class Solution {


        public int treeHeight(int n, int root, int[][] edges) {
            int hMax = 0;
            if (root > n) {
                return 0;
            }
            for (int i = 0; i < edges.length; i++) {
                if (edges[i][0] == root) {
                    hMax = Math.max(hMax, 1 + treeHeight(n, edges[i][1], edges));
                }
                else if (edges[i][1] == root) {
                    hMax = Math.max(hMax, 1 + treeHeight(n, edges[i][0], edges)); 
                }
            }    
            return hMax;          
        }
        public List<Integer> findMinHeightTrees(int n, int[][] edges) {

            Map<Integer, Integer> map = new HashMap<>();
    
            for (int i = 0; i < n; i++) {
                int root = i;
                map.put(i, treeHeight(n, root, edges));
            }
            int menor = 0;
            for (Integer value : map.values()) {
                if (value < menor) {
                    menor = value;
                }

            }
            List<Integer> list = new ArrayList<>();
            for (Integer key : map.keySet()) {
                if (map.get(key) == menor) {
                    list.add(key);
                }
            }
            return list;
        }
    }
    
}
