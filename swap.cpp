#include<iostream>
using namespace std;

int main() {
    int a = 1;
    int b = 2;

    int temp = a;
    a = b;
    temp = b;

    cout << a;

    return 0;
}