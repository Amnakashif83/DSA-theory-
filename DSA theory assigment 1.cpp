#include <iostream>
using namespace std;

int main() {
    int arr[6]; 
    cout << "Enter 6 numbers:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "\nYou entered: ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " "<<",";
    }
    return 0;
}
