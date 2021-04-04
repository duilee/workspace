# Complete the minimumSwaps function below.
# https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
def minimumSwaps(arr):
    swap = 0
    for i in range(len(arr)):
        if (arr[i] != (i + 1)):
            t = i;
            while (arr[t] != (i + 1)):
                t += 1
            arr[i], arr[t] = arr[t], arr[i]
            swap += 1
    return swap

# since python is slow...

"""
// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int count = 0;
    
    for (int i=0; i < arr.size()- 1; i++) {
        if (arr[i] != i+1) {
            int t = i+1;
            while (arr[t] != i+1) {
                t++;
            }
            int temp = arr[t];
            arr[t] = arr[i];
            arr[i] = temp;
            count++;
        }
        
    }
    
    return count;

}
"""
