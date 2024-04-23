func findMinHeightTrees(n int, edges [][]int) []int {
    if n == 1 {
        return []int{0}
    }

    graph := make([][]int, n)
    for _, edge := range edges {
        a, b := edge[0], edge[1]
        graph[a] = append(graph[a], b)
        graph[b] = append(graph[b], a)
    }

    queue := make([]int, 0)
    for i := 0; i < n; i++ {
        if len(graph[i]) == 1 {
            queue = append(queue, i)
        }
    }

    for n > 2 {
        size := len(queue)
        n -= size
        for i := 0; i < size; i++ {
            node := queue[0]
            queue = queue[1:]

            for _, neighbor := range graph[node] {
                index := 0
                for j, val := range graph[neighbor] {
                    if val == node {
                        index = j
                        break
                    }
                }
                graph[neighbor] = append(graph[neighbor][:index], graph[neighbor][index+1:]...)
                if len(graph[neighbor]) == 1 {
                    queue = append(queue, neighbor)
                }
            }
        }
    }

    result := make([]int, len(queue))
    for i, root := range queue {
        result[i] = root
    }
    return result
}
// Optimized by ChatGPT
