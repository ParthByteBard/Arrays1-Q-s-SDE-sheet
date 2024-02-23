// Extreme brute force sort the array O,1 and 2's will get sorted automatically 
// TC=O(nlogn)
// SC=O(1)
#include <bits/stdc++.h> 
# include<algorithm>
void sort012(int *arr, int n)
{
   sort(arr,arr+n);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 2nd brute force
// count the O's,1's and 2's and later override the same array according to the number of 0's,1's and 2's counted
// TC=O(2N)
// SC=O(1)

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int cnt0=0,cnt1=0,cnt2=0;

   for(int i=0;i<n;i++)
   {
     if(arr[i]==0)
     cnt0++;
     else if(arr[i]==1)
     cnt1++;
     else
     cnt2++;
   }

  int idx=0;
   while(cnt0--)
   {
     arr[idx++]=0;
   }
    while(cnt1--)
   {
     arr[idx++]=1;
   }
    while(cnt2--)
   {
     arr[idx++]=2;
   }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Optimal solution using Dutch National Flag Algorithm
// TC=O(n)
// SC=O(1)
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   // solved using DNF algorithm , i.e the Dutch National Flag algorithm
  // low--> index before which all zeros are located
  // mid--> index before which all ones are located
  // high--> index after which all 2's are located
  
   int low=0,mid=0,high=n-1;

    // if mid crosses high means that now the array is sorted
    while(mid<=high)
    {
    // mid index should contain 1 if contain zero swap with the low which needs 0, increment both
      if(arr[mid]==0)
      swap(arr[mid++],arr[low++]);
     
  // mid has 1, then 1 is in its right postion
      else if(arr[mid]==1)
      mid++;
      
// means mid has 2, swap mid with high so that 2 goes to its appropiate place and decrement high so that all 2's are located after high
      else
      swap(arr[mid],arr[high--]);
    }

  
  
}
