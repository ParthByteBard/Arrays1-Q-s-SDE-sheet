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

