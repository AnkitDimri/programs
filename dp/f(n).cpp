/************************************************************************************

    Name : Ankit Dimri
    code : Design and implement a non-recursive dynamic programming based algorithm
           to evaluate f(n) = 2*summation(i=2 to n) [f(i-1)*f(i-2)] + 1

************************************************************************************/

#include <iostream>
#include <vector>

 std::vector<long int> v;    // Dynamic table to store values calculated for n

 long int f (long int);      // Function to calculate f(n)

  int main( int argc, char const *argv[]) {
   long int n;
   char ans = 'y';
   // Initial condition values
   v.push_back (1);
   v.push_back (2);
   v.push_back (5);
   while (ans == 'y' || ans == 'Y') {
     std::cout << "\n\t Enter the value of n : ";
     std::cin >> n;
     std::cout << "\t f(n) = " << f (n) << '\n';
     std::cout << "\n\n\t Do you want to continue?(Y/N) : ";
     std::cin >> ans;
   }
   return 0;
 }

 // Check if the value is already computed or computes using the nearest calculated
 long int f (long int n) {
   if (n < v.size())
      return v[n];
   for (long int i = v.size(); i <= n; i++)
     v.push_back (2*v[i-1]*v[i-2] + v[i-1]);    // Function Definition
   return v[n];
 }
