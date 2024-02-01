// Solution to pascal's triangle

// Intution: in every row  when the first element when j=0 and the last element when i==j
// are always zero 
// The remaining are just a sum of the two elements present in prev row( explained in notes)
// Pascal's Triangle
# include<vector>
vector<vector<int>> pascalTriangle(int N) {

// making the 2d vector to store the pascal's triangle it will be of size NxN
  vector<vector<int>> pTriangle(N*N);


  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {

      // if first element(j=0) or i==j then push 1 into the pTriangle
      if (j == 0 || i == j) 
            pTriangle[i].push_back(1);

      else {
      // the element is the sum of elements in prev row(i-1) i.e [i-1][j] and [i=1][j-1] indices
            int ele= pTriangle[i-1][j]+pTriangle[i-1][j-1];
            pTriangle[i].push_back(ele);
            
      }
    }
  }

  return pTriangle;
}

// TC= O(n*n)
// SC= O(n*n) for storing output matrix
