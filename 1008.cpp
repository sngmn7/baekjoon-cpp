#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    cin >> a >> b;

    cout.precision(10);
    cout << fixed;

    cout << a/b << "\n";

    return 0;
}