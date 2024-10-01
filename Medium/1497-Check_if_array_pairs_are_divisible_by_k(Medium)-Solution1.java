// Memory limit reached
class Solution {
    public boolean canArrange(int[] arr, int k) {
        if (arr.length % 2 != 0) {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        if ((sum % k) != 0) {
            return false;
        }

        return recursivePairing(arr, k);
    }

    public boolean recursivePairing(int[] arr, int k) {
        if (arr.length == 2) {
            return (arr[0] + arr[1]) % k == 0;
        }

        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if ((arr[i] + arr[j]) % k == 0) {
                    int[] new_arr = new int[arr.length - 2];
                    int count = 0;
                    for (int l = 0; l < arr.length; l++) {
                        if (l != i && l != j) {
                            new_arr[count] = arr[l];
                            count++;
                        }
                    }
                    if (recursivePairing(new_arr, k)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
