#include <bits/stdc++.h>
using namespace std;

// ** PASCAL'S TRIANGLE

int NcR(int n, int r) {
    /*
    ? n-th row r-th col value of the pascal triangle is given by NcR(n-1, r-1)
            n!
        __________
        r! (n-r)!

    ? shortcut way : 10c3 = (10*9*8) / (1*2*3) 
    ! this is the only way, because other way would be way too much time-consuming
    */

    int res = 1;
    for (int i=0; i<r; i++) {
        res *= n-i;
        res /= i+1;
    }
    return res;
}


int main (void)
{
    system("cls");
    cout << "Pascal triangle er 3rd row 2nd col " << NcR(4,2) << endl;


}