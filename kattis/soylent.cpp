#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n; cin >> n;
    float cal; 
    while (n--){
        cin >> cal;
        cout << ceil(cal / 400) << '\n';
    }
}
