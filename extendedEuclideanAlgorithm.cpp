#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, pair<int, int>> iExtendedEuclidean(int big, int small);
pair<int, pair<int, int>> rExtendedEuclidean(int big, int small);

int main(){
    int a, b;
    cin >> a >> b;
    int big = max<int>(a, b);
    int small = min<int>(a, b);
    pair<int, pair<int, int>> result = iExtendedEuclidean(big, small);
    cout << big << "X + " << small << "Y = " << result.first << '\n';
    cout << "X = " << result.second.first << " Y = " << result.second.second << '\n';
    result = rExtendedEuclidean(big, small);
    cout << big << "X + " << small << "Y = " << result.first << '\n';
    cout << "X = " << result.second.first << " Y = " << result.second.second << '\n';
    return 0;
}

pair<int, pair<int, int>> iExtendedEuclidean(int big, int small){
    int x0 = 1, x1 = 0, y0 = 0, y1 = 1, x2, y2, quotient, remainder;
    while(small != 0){
        quotient = big / small;
        remainder = big % small;
        big = small;
        small = remainder;
        x2 = x0 - (quotient * x1);
        y2 = y0 - (quotient * y1);
        x0 = x1; x1 = x2;
        y0 = y1; y1 = y2;
    }
    return pair<int, pair<int, int>>(big, pair<int, int>(x0, y0));
}

pair<int, pair<int, int>> rExtendedEuclidean(int big, int small){
    if(small == 0) return pair<int, pair<int, int>>(big, pair<int, int>(1, 0));
    pair<int, pair<int, int>> result = rExtendedEuclidean(small, big % small);
    pair<int, pair<int, int>> ret;
    ret.first = result.first;
    ret.second.first = result.second.second;
    ret.second.second = result.second.first - result.second.second *(big / small);
    return ret;
}