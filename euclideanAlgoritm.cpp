#include <iostream>
#include <algorithm>
using namespace std;

int iEuclidean(int a, int b);
int rEuclidean(int a, int b);

int main(){
    int a, b;
    cin >> a >> b;
    cout << iEuclidean(a, b) << '\n' << rEuclidean(a, b);
    return 0;
}

int iEuclidean(int a, int b){
    int big = max<int>(a, b);
    int small = min<int>(a, b);
    int tmp;
    while(small != 0){
        cout << "gcd(" << big << ", " << small << ") = ";
        tmp = big;
        big = small;
        small = tmp % small;
    }
    cout << "gcd(" << big << ", " << small << ") = ";
    return big;
}

int rEuclidean(int a, int b){
    int big = max<int>(a, b);
    int small = min<int>(a, b);
    cout << "gcd(" << big << ", " << small << ") = ";
    if(small == 0) return big;
    return rEuclidean(small, big % small);
}