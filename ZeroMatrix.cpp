// if (x,y) in a matrix is zero mark the corresponding rows and coloumns as zero and do this for all the elements which are zero.

// Brute force solution
#include <bits/stdc++.h>
void makeRowColumnZero(vector<vector<int>> &matrix, int n, int m, int r, int c)
{
    // make the entire rth row zero
    for (int i = 0; i < m; i++)
    {
        matrix[r][i] = 0;
    }

    // make the entire cth col zero
    for (int j = 0; j < n; j++)
    {
        matrix[j][c] = 0;
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    // to store all the pairs having element as 0
    vector<pair<int, int>> allPairs;
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // ele at i,j is zero so add i,j to allPairs
            if (matrix[i][j] == 0)
            {
                p = make_pair(i, j);
                // push curr pair into allPairs matrix
                allPairs.push_back({i, j});
            }
        }
    }

    // traverse through the pairs to make their rows and cols zero
    for (int i = 0; i < allPairs.size(); i++)
    {
        makeRowColumnZero(matrix, n, m, allPairs[i].first, allPairs[i].second);
    }
    return matrix;
}

// TC=O(n*m(m+n) nearly cubic
// SC=O(m*n) for storing the pairs

//-----------------------------------------------------------------------

// Better solution
#include <bits/stdc++.h>

void markMatrix(vector<vector<int>> &matrix, int n, int m, int r, int c)
{

    // always before marking -1 check if the current element underpocessing is not zero, if it is zero
    // it means it can potentially make rows and coloumns corresponding to it zero, so we leave it
    for (int i = 0; i < m; i++)
    {
        if (matrix[r][i] != 0)
            matrix[r][i] = -1;
    }

    for (int j = 0; j < n; j++)
    {
        if (matrix[j][c] != 0)
            matrix[j][c] = -1;
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if a element (r,c) is zero mark rth row and cth col as -1
            if (matrix[i][j] == 0)
            {
                markMatrix(matrix, n, m, i, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

// time complexity = O(m*n(m+n))
// space complexity = O(1)

//-------------------------------------------------------------------------------------

// Best solution
#include <bits/stdc++.h>

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    vector<pair<int, int>> allPairs;
    // to mark if a particular row or coloum is zero
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);

    // iterate in the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if a element is zero mark the corresponding row and coloumns as 1
            if (matrix[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    // re-iterate the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if you find that the row or col or both are marked as 1 it means there is a zero present
            // in the row and coloumn of that element so mark the element as zero
            if (rows[i] == 1 || cols[j] == 1)
                matrix[i][j] = 0;
        }
    }

    return matrix;
}
// TC=O(m*n)
// SC=O(m+n)
