#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
    cout << "Hello, world." << endl;

    cout << "Press ENTER to quit... ";
    while (cin.get() != '\n');

    return 0;
}