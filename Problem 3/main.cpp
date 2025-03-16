#include <iostream>
#include <fstream>
#include "SortedLinkedList/SortedLinkedList.h"

using namespace std;

int menuCheck(const string& menu){
    cout << menu << endl;
    string choice;
    getline(cin, choice);
    if (choice.length() == 1 && isdigit(choice[0]))
        return choice[0] - '0';
    throw invalid_argument("Invalid input. Please enter a valid number.");
}

void readFromFile(SortedLinkedList& list){
    ifstream infile("input.txt");

    if (!infile) {
        cerr << "Error: Unable to open input.txt" << endl;
        return;
    }

    int number;
    while (infile >> number) {
        list.insert(number);
    }

    infile.close();
}


int main(){
    SortedLinkedList list;
    int choice = 0;

    while (true) {
        while (true) {
            try {
                choice = menuCheck("Welcome to My linked list \n1. Read numbers from input.txt\n2. Exit\nChoose an option: ");
                if (choice == 1 || choice == 2) break;
            }
            catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
                cout << "Please enter a valid input." << endl;
            }
        }

        if (choice == 1) {
            readFromFile(list);
            break;
        }
        return 0;
    }

    while (true) {
        cout << "Your list: " << list << endl;
        try {
            choice = menuCheck("Choose an operation\n1. Insert a number\n2. Delete a number\n3. Get by Index\n4. Exit\nChoose an option: ");
            if (choice < 1 || choice > 4) throw invalid_argument("Invalid choice.");
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
            cout << "Please enter a valid input." << endl;
            continue;
        }

        try {
            int num;
            switch (choice) {
                case 1:
                    cout << "Enter a number to insert: ";
                    if (!(cin >> num)) {
                        cin.clear();
                        cin.ignore(0, '\n');
                        throw invalid_argument("Invalid input. Please enter a valid number.");
                    }
                    list.insert(num);
                    cout << "Number inserted successfully.\n";
                    break;

                case 2:
                    int delIndex;
                    cout << "Enter an index to delete: ";
                    if (!(cin >> delIndex) || delIndex < 0) {
                        cin.clear();
                        cin.ignore(0, '\n');
                        throw invalid_argument("Invalid input. Please enter a valid index.");
                    }
                    list.remove(delIndex);
                    cout << "Number deleted successfully.\n";
                    break;

                case 3:
                    int index;
                    cout << "Enter an index to get: ";
                    if (!(cin >> index) || index < 0) {
                        cin.clear();
                        cin.ignore(0, '\n');
                        throw invalid_argument("Invalid input. Please enter a valid index.");
                    }
                    cout << "Number at index " << index << ": " << list[index] << endl;
                    break;

                case 4:
                    cout << "Exiting...\n";
                    return 0;
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
            cout << "Please enter a valid input." << endl;
        }
    }

    return 0;
}
