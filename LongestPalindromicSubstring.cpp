/* Problem statement
 You are given a string 'str' of length 'N'.
Your task is to return the longest palindromic substring. If there are multiple strings, return any.
A substring is a contiguous segment of a string.
For example :
Explain
str = "ababc"
The longest palindromic substring of "ababc" is "aba", since "aba" is a palindrome and it is the longest substring of length 3 which is a palindrome. 
There is another palindromic substring of length 3 is "bab". Since starting index of "aba" is less than "bab", so "aba" is the answer.
*/


// Brute force to find the longest palindromic sequence
// solution written by myself

    // this fn checks if a given string is palindrome or not
bool isPalindrome(string &subStr) {
    // if the lenght of the string is 1 or 0 , it is always a palindromic string
  if (subStr.size() == 1 || subStr.size() == 0) return true;

  int s = 0, e = subStr.size() - 1;
    // at any instance if the elements at start and end are not equal strings are not palindromic
  while (s < e) {
    if (subStr[s++] != subStr[e--]) return false;
  }
    // if no instance of substr[s]!=substr[e] is found means the strings are palindromic
  return true;
}

string longestPalinSubstring(string str) {

// temp stores strings temprerorly for different iterations
  string temp = "", ans = "";
// choosing the first character of the string
  for (int i = 0; i < str.size(); i++) {
    temp = str[i];
// add characters to ith character chosen and check if is palindrome
    for (int j = i + 1; j < str.size(); j++) {
      temp += str[j];
// only and only if the string is a palindromic string and the curr palindromic str(temp) is greater
// in size than the ans string then temp is my ans
      if (isPalindrome(temp) && ans.size() < temp.size()) {
        ans = temp;
      }
    }
    // if the ans size is greater or equal to lenght of the remaining string to be traversed
    // since we begin with next i to find next greater string, if the current string is already 
    // equal to that then no use, in traversing further(dry run you'll understand)
    if (ans.size() >= (str.size() - (i + 1))) break;
  }
// if no palindromic string is found , return the first character as the ans
  if (ans.size() == 0) {
    ans = str[0];
  }
  return ans;
}

// TC=O(n3)
// SC=O(n)


// slightly optimized version
// INSTEAD OF USING A TEMP AND ANS STRING WE ARE PLAYING WITH INDICES, AVOIDING THE EXTRA SPACE THAT
// WE ARE GONNA USE BY temp and ans variables
// This function checks if a substring of a given string is a palindrome.
// It takes the string, starting index (s), and ending index (e) as input.
// It returns true if the substring is a palindrome, false otherwise.
bool isPalindrome(string& str, int s, int e) {
  // Iterate while the starting index is less than or equal to the ending index.
  while (s <= e) {
    // If the characters at the starting and ending indices are not equal,
    // the substring is not a palindrome, so return false.
    if (str[s++] != str[e--]) {
      return false;
    }
  }
  // If the loop completes without returning false, then all characters
  // were matched, so the substring is a palindrome, so return true.
  return true;
}

// This function finds the longest palindromic substring starting from a given index.
// It takes the string, starting index (i), reference to the starting index of the
// longest substring found so far (start), and reference to the length of the longest
// substring found so far (mx) as input. It updates start and mx if a longer
// palindromic substring is found starting from index i.
void solve(string& str, int i, int& start, int& mx) {
  // Get the length of the string.
  int n = str.length();

  // Iterate from the current index (i) to the end of the string.
  for (int j = i; j < n; j++) {
    // Check if the substring from index i to index j is a palindrome.
    if (isPalindrome(str, i, j)) {
      // Calculate the length of the current substring.
      int currentLength = j - i + 1;

      // If the current substring is longer than the longest one found so far,
      // update start and mx.
      if (currentLength > mx) {
        start = i;
        mx = currentLength;
      }
    }
  }
}

// This function finds the longest palindromic substring in a given string.
// It takes the string as input and returns the longest palindromic substring.
string longestPalinSubstring(string str) {
  // Initialize variables to keep track of the starting index and length
  // of the longest palindromic substring found so far.
  int start = 0;
  int mx = 0;
  int n = str.length();

  // Iterate from the beginning of the string to the end.
  for (int i = 0; i < n; i++) {
    // Call the solve function to find the longest palindromic substring
    // starting from the current index.
    solve(str, i, start, mx);
  }

  // Return the longest palindromic substring found.
  return str.substr(start, mx);
}

// TC=O(N3)
// SC=O(1)
