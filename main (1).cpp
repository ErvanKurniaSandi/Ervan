#include <iostream>
using namespace std;
int main() {
    int kesamping = 3; 
    int kebawah = 3; 
    cout << "---------\n";
    for (int s = 1 ; s <= kesamping; s++) {
        for (int b = 1 ; b <= kebawah; b++) {
          cout <<"|_|";
        }
          cout <<"\n";
    }

    return 0;
}
