/*
54321
 4321
  321
   21
    1
*/
#include <iostream>
using namespace std;
int main()
{
    for (int i = 5; i >= 1; i--)
    {
        for (int k = i; k < 5 ; k++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}
