#include <iostream>
using namespace std;

// Recursive function to calculate GCD
int findGCD(int a, int b) {
    if (b == 0) 
        return a;
    return findGCD(b, a % b);
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    cout << "GCD is: " << findGCD(num1, num2) << endl;
    // cout<<num1%num2;
    return 0;
}
