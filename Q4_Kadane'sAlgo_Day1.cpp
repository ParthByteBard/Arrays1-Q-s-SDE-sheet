// TC=O(n)
// SC=O(1)

// Brute force solution for the same question would be to check all the subarrays
// which would result in a TC of O(N^2), this algo Kadane's alogrithm finds answer
// in O(n) time

long long maxSubarraySum(vector<int> arr, int n)
{
// maxSum stores the maxSum encountered till a point, and currSum stores the current sum
    long long maxSum=0,currSum=0;
// iterate the entire array
    for(int i=0;i<n;i++)
    {
    // add comming elements to currSum
        currSum+=arr[i];
    // if the currSum is greater than the maxSum update the maxSum
        if(currSum>maxSum)
        {
            maxSum=currSum;
        }
    // if the currSum has become less than zero means, it is a negative addition as we move
    // ahead, we always have a subarray of size zero so carrying the -ve sum ahead
    // wont give us maximum subarray sum , so we drop the -ve qunatity and set currSum
    // as zero again
        if(currSum<0)
        currSum=0;
    }
    // return the maxSum after everything
    return maxSum;
}
