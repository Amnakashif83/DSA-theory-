#include <iostream>
using namespace std;
void swap(int a, int b) 


int main() 
{
	 int temp = a;
    a = b;
    b = temp;
    
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;    swap(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;
    return 0;
}
//without pointers and the function is in the main funtion then the program didn't run 
