/**********************************************************************************************

    Name : Ankit Dimri
    code : Rod Cutting problem implemented using Dynamic Progamming.
           Top-Down and Bottom-Up approach.

**********************************************************************************************/

#include <iostream>
#include <vector>
#include <climits>

 // rTD - Top Down approach dynamic table
 // rBU - Bottom Up approach dynamic table
 std::vector <int> p, rTD, rBU;

 int cut_rod (int); // Top-down
 int rod_cut (int); // Bottom-up
 int max (int, int);

 int main(int argc, char const *argv[]) {
     int n, priceTD, priceBU, length;
     std::cout << "\n\n\t Enter the maximum length of cut : ";
     std::cin >> n;
     std::cout << "\n\t enter the price of each length cut : " << '\n';
     for (int i = 0; i < n; i++) {
         std::cin >> priceTD;
         p.push_back (priceTD);
     }
     std::cout << "\n\n\t Enter the length of rod : ";
     std::cin >> length;
     priceTD = cut_rod (length);
     priceBU = rod_cut (length);
     std::cout << "\n\t\t Max revenue is : " << "\n\t Top-down approach : " << priceTD << '\n';
     std::cout << "\t Bottom-up approach : " << priceBU << '\n';
     // To display top down dynamic table
     std::cout << rTD.size () << '\n';
     for (std::vector <int>::iterator it = rTD.begin (); it != rTD.end (); it++)
        std::cout << *it << ' ';
     std::cout << '\n';
     // To display bottom up dynamic table
     std::cout << rBU.size () << '\n';
     for (std::vector <int>::iterator it = rBU.begin (); it != rBU.end (); it++)
        std::cout << *it << ' ';
     std::cout << '\n';
     return 0;
 }

 // top-Down
 int cut_rod (int n) {
     if (n == 0)
        return 0;
     if (rTD.size () >= n)
        return rTD.at (n-1);
     int revenue;
     revenue = INT_MIN;
     for (int i = 1; i <= n; i++)
         revenue = max (revenue, p[i-1] + cut_rod (n-i));
     rTD.push_back (revenue);
     return revenue;
 }

 // Bottom-Up
 int rod_cut (int n) {
     if (n == 0)
        return 0;
     int revenue = INT_MIN;
     rBU.push_back (0);
     for (int i = 1; i <= n; i++) {
         revenue = INT_MIN;
         for (int j = 1; j <= i; j++)
             revenue = max (revenue, p [j - 1] + rBU [i-j]);
         rBU.push_back (revenue);
     }
     return rBU [n];
 }

 int max (int a, int b) {
     return a>b? a:b;
 }
