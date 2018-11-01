/**************************************************************************************************

    Name : Ankit Dimri
    code : Maximum Value Contiguous Subsequence using dynamic porgramming.

**************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

 // To compute the maximum value of a subsequence
 int MVCS (const std::vector <int>);
 int max (int, int);

 int main(int argc, char const *argv[]) {
     std::vector <int> sequence;
     int n, val;
     std::cout << "\n\n\t Enter the size of the sequence : ";
     std::cin >> n;
     std::cout << "\n\t Enter the values of the sequence : ";
     for (int i = 0; i < n; i++) {
         std::cin >> val;
         sequence.push_back (val);
     }
     std::cout << "\n\n\t The maximum value is : " << MVCS (sequence) << std::endl;
     return 0;
 }

 int MVCS (const std::vector <int> v) {
     std::vector <int> val (v.size(), 0);
     std::vector <int>::iterator i = val.begin();
     for (std::vector <int>::const_iterator it = v.begin (); it != v.end(); it++, i++)
         *i = max (*it, *it + *(i-1));
     return *max_element (val.begin (), val.end ());
 }

 int max (int a, int b) {
     return a>b ? a:b;
 }
