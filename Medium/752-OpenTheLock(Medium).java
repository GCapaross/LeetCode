class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> deadendSet = new HashSet<>();
        for (String deadend : deadends) {
            deadendSet.add(deadend);
        }

        String start = "0000";
        if (deadendSet.contains(start) || deadendSet.contains(target)) {
            return -1;
        }

        Set<String> visited = new HashSet<>();
        visited.add(start);

        Queue<String> queue = new LinkedList<>();
        queue.offer(start);

        int moves = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                String current = queue.poll();

                if (current.equals(target)) {
                    return moves;
                }

                for (int j = 0; j < 4; j++) {
                    for (int d = -1; d <= 1; d += 2) {
                        char[] digits = current.toCharArray();
                        digits[j] = (char) ((digits[j] - '0' + d + 10) % 10 + '0');
                        String nextState = new String(digits);

                        if (!deadendSet.contains(nextState) && !visited.contains(nextState)) {
                            visited.add(nextState);
                            queue.offer(nextState);
                        }
                    }
                }
            }

            moves++;
        }

        return -1;
    }
}
