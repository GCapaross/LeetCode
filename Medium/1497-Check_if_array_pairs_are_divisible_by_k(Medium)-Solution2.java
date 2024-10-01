class Solution {
    // Basically in this solution we take advantage of remainders
    // Example: [9, 7, 5, 3] and k = 6
    // 9%6=3 | 7%6=1 | 5%6=5 | 3%6=3
    // After this we have an array with this remainders [3,1,5,3]
    // Now we build an array called remainder count of size k
    // This array will be for this example remainderCounts[0, 1, 0, 2, 0, 1];
    // In which the numbers represent the ammount of numbers in the var "arr" that have the remainder equal the index
    // of "remainderCounts" -> Because the remainder will never be higher or the same as k
    // Now we know that numbers with remainder 1 need to pair with numbers with remainder 5
    // If there aren't enough remainders we know it will return false.
  
    public boolean canArrange(int[] arr, int k) {

        int[] remainderCounts = new int[k];

        for (int num : arr) {
            int remainder = ((num % k) + k) % k; 
            remainderCounts[remainder]++;
        }

        for (int i = 1; i < k; i++) {
            if (remainderCounts[i] != remainderCounts[k - i]) {
                return false;
            }
        }

        return remainderCounts[0] % 2 == 0;
    }
}
