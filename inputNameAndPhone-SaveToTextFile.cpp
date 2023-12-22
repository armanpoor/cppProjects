#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Person {
    string name;
    string number;
};

const int MAX_PERSONS = 100;
Person persons[MAX_PERSONS];
int numPersons = 0;

void searchByNameOrNumber(const string& searchTerm) {
    for (int i = 0; i < numPersons; i++) {
        if (persons[i].name == searchTerm && persons[i].number == searchTerm) {
            cout << "Name: " << persons[i].name << ", Number: " << persons[i].number << endl;
        }
    }
}

void getInput() {
    if (numPersons < MAX_PERSONS) {
        cout << "Enter name: ";
        cin >> persons[numPersons].name;
        cout << "Enter number: ";
        cin >> persons[numPersons].number;
        numPersons++;
    } else {
        cout << "Can't add more persons, array is full." << endl;
    }
}

void saveToFile() {
    ofstream outfile("tel.txt");
    if (outfile.is_open()) {
        for (int i = 0; i < numPersons; i++) {
            outfile << persons[i].name << " " << persons[i].number << endl;
        }
        outfile.close();
        cout << "Data saved to tel.txt" << endl;
    } else {
        cout << "Unable to open file" << endl;
    }
}

int main() {
    int choice;
    string searchTerm;

    do {
        cout << "1. Search by name or number 2. Add new person 3. Save to file 4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name or number to search: ";
                cin >> searchTerm;
                searchByNameOrNumber(searchTerm);
                break;
            case 2:
                getInput();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
