#include "RecruitDB.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    RecruitDB recruitDb;
    ifstream inputFile("top100.txt");

    if (!inputFile.is_open()) 
    {
        cout << "Error: Could not open top100.txt!" << endl;
        return 1;
    }

    // reads the recruits
    recruitDb.read_txt(inputFile);
    inputFile.close();

    // debugging... 
    cout << "File read successfully!" << endl;
    cout << "Number of recruits loaded: " << recruitDb.getRecruitCount() << endl;

    // loop for display menu
    int choice;
    string input1, input2;
    while (true) 
    {
        // display menu
        cout << "Choose an option to search by:\n";
        cout << "1. Search by State\n";
        cout << "2. Search by Position\n";
        cout << "3. Search by Stars and State\n";
        cout << "4. Search by City and Highschool\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter State (e.g., AR): ";
                cin >> input1;
                recruitDb.searchState(input1);
                break;
            case 2:
                cout << "Enter Position (e.g., PF): ";
                cin >> input1;
                recruitDb.searchPosition(input1);
                break;
            case 3:
                int stars;
                cout << "Enter number of stars (e.g., 5): ";
                cin >> stars;
                cout << "Enter State (e.g., TX): ";
                cin >> input1;
                recruitDb.searchStarsAndState(stars, input1);
                break;
            case 4:
                cout << "Enter City (e.g., Miami): ";
                cin >> ws; 
                getline(cin, input1);
                cout << "Enter Highschool:";
                getline(cin, input2);
                recruitDb.searchCityAndHighschool(input1, input2);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
