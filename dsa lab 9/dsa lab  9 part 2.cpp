#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class GarageSystem {
private:
    queue<int> road;
    stack<int> garage;

public:
    void onRoad(int truck_id) {
        road.push(truck_id);
        cout << "Truck " << truck_id << " is now on the road." << endl;
    }

    void enterGarage(int truck_id) {
        if (!road.empty() && road.front() == truck_id) {
            road.pop();
            garage.push(truck_id);
            cout << "Truck " << truck_id << " entered the garage." << endl;
        } else {
            cout << "Truck " << truck_id << " is not first on the road. It cannot enter now." << endl;
        }
    }

    void exitGarage(int truck_id) {
        if (garage.empty()) {
            cout << "Garage is empty. No truck to exit." << endl;
            return;
        }

        if (garage.top() == truck_id) {
            garage.pop();
            cout << "Truck " << truck_id << " exited the garage." << endl;
        } else {
            cout << "Truck " << truck_id << " is not near the garage door." << endl;
        }
    }

    void showTrucks(string place) {
        if (place == "road") {
            if (road.empty()) {
                cout << "No trucks on the road." << endl;
                return;
            }
            queue<int> temp = road;
            cout << "Trucks on road: ";
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        } 
        else if (place == "garage") {
            if (garage.empty()) {
                cout << "Garage is empty." << endl;
                return;
            }
            stack<int> temp = garage;
            cout << "Trucks in garage: ";
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        } 
        else {
            cout << "Please type 'garage' or 'road' only." << endl;
        }
    }
};

int main() {
    GarageSystem system;
    int choice, truck_id;
    string place;

    do {
        cout << "\n===== Garage Truck Management Menu =====" << endl;
        cout << "1. Add Truck on Road" << endl;
        cout << "2. Move Truck into Garage" << endl;
        cout << "3. Remove Truck from Garage" << endl;
        cout << "4. Show Trucks (garage/road)" << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter truck ID: ";
            cin >> truck_id;
            system.onRoad(truck_id);
            break;

        case 2:
            cout << "Enter truck ID to enter garage: ";
            cin >> truck_id;
            system.enterGarage(truck_id);
            break;

        case 3:
            cout << "Enter truck ID to exit garage: ";
            cin >> truck_id;
            system.exitGarage(truck_id);
            break;

        case 4:
            cout << "Enter where to show (garage/road): ";
            cin >> place;
            system.showTrucks(place);
            break;

        case 5:
            cout << "Program ended. Thank you!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}


