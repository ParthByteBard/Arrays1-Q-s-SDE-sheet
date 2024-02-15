// STL solution

# include<algorithm>
vector<int> nextGreaterPermutation(vector<int> &A) {
     next_permutation(A.begin(),A.end());
    return A;
}

// brute force
// generate all the possible permutation and store them in a set in sorted order, later do a linear search till that position and return the next greater permutation
// TC=O(n*n!)
// SC=O(n*n!)


//   OPTIMAL SOLUTION
void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
vector<int> nextGreaterPermutation(vector<int> &A) {

// initialize dip with -1
  int dip = -1;
  int n = A.size();

  for (int i = n - 1; i >= 1; i--) {
    // to find the dip first, if the curr element @ i is greater than element @ i-1 dip is found
    if (A[i - 1] < A[i]) {
    // store the index of the dip and break
      dip = i - 1;
      break;
    }
  }

    // dip is not found( dip = -1), means we have the vector in monotonically decreasing order i.e having the 
    // last and greatest permutation possible
    // for eg: if A={5,4,3,2,1} then no dip is found so just reverse the vector, the starting 
    // vector A={1,2,3,4,5} will be the next permutation 
    if(dip==-1)
    {
        reverse(A.begin(),A.end());
        return A;
    }

    // find for the just greater number than dip, since the range (dip+1,n-1) is
    // monotonically decreasing, we will start from back(n-1) till >dip
  for (int i = n - 1; i > dip; i--) {
        if (A[i] > A[dip]) {
        // once we find the ele just gr8ter than dip swap it with the dip index and break;
      swap(A[i], A[dip]);
      break;
        }
  }

    // we have the just greater element at dip position, means to generate the next greater 
    // permutation, we minimize the permutation from dip+1 to n-1. 
    // For this its simple just reverse (dip+1,n-1), since the range is monotonically decreasing
    // reversing it will make it the smallest permutation possible in range dip+1 to n-1
    reverse(A.begin()+dip+1,A.end());
    return A;
  
}
