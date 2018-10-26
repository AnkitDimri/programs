/*******************************************************************************

    Name : Ankit Dimri
    code : Rod Cutting problem implemented using Dynamic Progamming.
           Top-Down approach.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <climits>

 std::vector <int> p, r;

 int cut_rod (int);
 int max (int, int);

 int main(int argc, char const *argv[]) {
     int n, price, length;
     std::cout << "\n\n\t Enter the maximum length of cut : ";
     std::cin >> n;
     std::cout << "\n\t enter the price of each length cut : " << '\n';
     for (int i = 0; i < n; i++) {
         std::cin >> price;
         p.push_back (price);
     }
     std::cout << "\n\n\t Enter the length of rod : ";
     std::cin >> length;
     price = cut_rod (length);
     std::cout << "\n\t Max revenue is : " << price << '\n';
     std::cout << r.size () << '\n';
     for (std::vector <int>::iterator it = r.begin (); it != r.end (); it++)
        std::cout << *it << ' ';
     std::cout << '\n';
     return 0;
 }

 int cut_rod (int n) {
     if (n == 0)
        return 0;
     if (r.size () >= n)
        return r.at (n-1);
     int revenue;
     revenue = INT_MIN;
     for (int i = 1; i <= n; i++)
         revenue = max (revenue, p[i-1] + cut_rod (n-i));
     r.push_back (revenue);
     return revenue;
 }

 int max (int a, int b) {
     return a>b? a:b;
 }
