/***************************************************************************************************

    Name : Ankit Dimri
    code : Longest Common Subsequence. Find LCS using dynamic programming.

***************************************************************************************************/

#include <vector>
#include <iostream>
#include <string>

 // Longest Common Subsequence
 int LCS (std::string, std::string);
 int max (int, int);

 int main(int argc, char const *argv[]) {
     std::string s1, s2;
     std::cout << "\n\n\t Enter the 1st string : ";
     std::cin >> s1;
     std::cout << "\n\t Enter the 2nd string : ";
     std::cin >> s2;
     std::cout << "\n\n\t The length of longest common subsequence is : " << LCS (s1, s2) << '\n';
     return 0;
 }

 int LCS (std::string s1, std::string s2) {
     int m = s1.length () + 1, n = s2.length () + 1;
     std::vector <std::vector <int>> table(m, std::vector <int> (n,0)); // DP table
     for (int i = 1; i < m; i++)
        for (int j = 1 ; j < n; j++) {
            if (s1 [i-1] == s2 [j-1])
                table [i][j] = table [i-1][j-1] + 1;
            else
                table [i][j] = max (table [i-1][j], table [i][j-1]);
        }
     return table [m-1][n-1];
 }

 int max (int a, int b) {
     return (a > b)? a:b;
 }
