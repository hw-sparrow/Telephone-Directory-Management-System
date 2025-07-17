#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
const int MaxContacts = 100, MaxNameLength = 15, MaxAddressLength = 50, MaxCellLength = 17, MaxLandlineLength = 13;

int Menu() {
    int Choice = 0;

    cout << "\n----------------------<:><[0]><:>---------------------- TELEPHONE DIRECTORY MANAGEMENT SYSTEM ----------------------<:><[0]><:>---------------------\n\n1) Display all contacts.\n2) Search for a contact.\n3) Add a new contact.\n4) Delete a contact.\n5) Modify an existing contact.\n6) Display contacts starting from a pattern.\n7) Sort contacts (in file).\n8) Exit.\n\nSelect an option (1-8): ";

    while (!(cin >> Choice) || Choice < 1 || Choice > 8) {
        cout << "Invalid option! Please select a number from 1 to 8: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return Choice;
}

void DisplayAllContacts(char FirstNames[][MaxNameLength], char LastNames[][MaxNameLength], char Addresses[][MaxAddressLength], char CellNumbers[][MaxCellLength], char LandlineNumbers[][MaxLandlineLength], int ContactCount) {
    for (int i = 0; i < ContactCount; i++) {
        cout << "CONTACT " << i + 1 << ":-\n-----------\nFirst Name: " << FirstNames[i] << "\nLast Name: " << LastNames[i] << "\nAddress: " << Addresses[i] << "\nCell Phone Number: " << CellNumbers[i] << "\nLandline Number: " << LandlineNumbers[i] << "\n\n";
    }
}

void SearchContact(char FirstNames[][MaxNameLength], char LastNames[][MaxNameLength], char Addresses[][MaxAddressLength], char CellNumbers[][MaxCellLength], char LandlineNumbers[][MaxLandlineLength], int ContactCount) {
    if (ContactCount == 0) {
        cout << "No contacts available to search.\n";
        return;
    }

    int SearchOption = 0;
    char SearchFirstName[MaxNameLength]{}, SearchLastName[MaxNameLength]{}, SearchCellPhone[MaxCellLength]{}, SearchLandline[MaxLandlineLength]{};

    cout << "Search contact by:-\n1) First Name\n2) Last Name\n3) Cell Phone Number\n4) Landline Number\n\nSelect an option (1-4): ";

    while (!(cin >> SearchOption) || SearchOption < 1 || SearchOption > 4) {
        cout << "Invalid choice. Please select a number from 1 to 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

Search:
    switch (SearchOption) {
    case 1: {
        cout << "Enter the first name of the contact you want to search for: ";
        cin.getline(SearchFirstName, MaxAddressLength);
        break;
    }
    case 2: {
        cout << "Enter the last name of the contact you want to search for: ";
        cin.getline(SearchLastName, MaxAddressLength);
        break;
    }
    case 3: {
        cout << "Enter the cell phone number of the contact you want to search for: ";
        cin.getline(SearchCellPhone, MaxAddressLength);
        break;
    }
    case 4: {
        cout << "Enter the landline of the contact you want to search for: ";
        cin.getline(SearchLandline, MaxAddressLength);
        break;
    }
    }

    bool found = false;

    cout << "\nSearch Results:-\n";

    for (int i = 0; i < ContactCount; i++) {
        bool match = false;

        if (SearchOption == 1 && strcmp(FirstNames[i], SearchFirstName) == 0) {
            match = true;
        }
        else if (SearchOption == 2 && strcmp(LastNames[i], SearchLastName) == 0) {
            match = true;
        }
        else if (SearchOption == 3 && strcmp(CellNumbers[i], SearchCellPhone) == 0) {
            match = true;
        }
        else if (SearchOption == 4 && strcmp(LandlineNumbers[i], SearchLandline) == 0) {
            match = true;
        }

        if (match) {
            found = true;
            cout << "\nContact " << i + 1 << ":-\n----------\nFirst Name: " << FirstNames[i] << "\nLast Name: " << LastNames[i] << "\nAddress: " << Addresses[i] << "\nCell Number: " << CellNumbers[i] << "\nLandline Number: " << LandlineNumbers[i] << "\n";
        }
    }

    if (!found) {
        cout << "No matching contacts found.\n\n";
        goto Search;
    }
}

void AddNewContact(char FirstNames[][MaxNameLength], char LastNames[][MaxNameLength], char Addresses[][MaxAddressLength], char CellNumbers[][MaxCellLength], char LandlineNumbers[][MaxLandlineLength], int& ContactCount) {
    if (ContactCount >= MaxContacts) {
        cout << "Error: Contact directory is full!\n";
        return;
    }

    char tempFirstName[MaxNameLength]{}, tempLastName[MaxNameLength]{}, tempAddress[MaxAddressLength]{}, tempCellNumber[MaxCellLength]{}, tempLandlineNumber[MaxLandlineLength]{};

    do {
        cout << "Enter first name (Max 15 characters): ";
    FirstName:
        cin.getline(tempFirstName, MaxNameLength);
        if (cin.fail() || strlen(tempFirstName) > 15) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Input too long! Please try again: ";
            goto FirstName;
        }
    } while (strlen(tempFirstName) > 15);

    do {
        cout << "Enter last name (Max 15 characters): ";
    LastName:
        cin.getline(tempLastName, MaxNameLength);
        if (cin.fail() || strlen(tempLastName) > 15) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Input too long! Please try again: ";
            goto LastName;
        }
    } while (strlen(tempLastName) > 15);

    do {
        cout << "Enter address (Max 50 characters): ";
    Address:
        cin.getline(tempAddress, MaxAddressLength);
        if (cin.fail() || strlen(tempAddress) > 50) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Input too long! Please try again: ";
            goto Address;
        }
    } while (strlen(tempAddress) > 50);

    do {
        cout << "Enter cell phone number (Format: +92-XXX-XXXXXXXX): ";
    CellNumber:
        cin.getline(tempCellNumber, MaxCellLength);
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Input too long. Please try again: ";
            goto CellNumber;
        }
        if (strlen(tempCellNumber) != 16 || strncmp(tempCellNumber, "+92-", 4) != 0) {
            cout << "Error: Invalid cell phone number format. Please try again.\n";
        }
    } while (strlen(tempCellNumber) != 16 || strncmp(tempCellNumber, "+92-", 4) != 0);

    do {
        cout << "Enter landline number (Format: 0XX-XXXXXXXX): ";
    LandlineNumber:
        cin.getline(tempLandlineNumber, MaxLandlineLength);
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Input too long. Please try again: ";
            goto LandlineNumber;
        }
        if (strlen(tempLandlineNumber) != 12 || tempLandlineNumber[0] != '0') {
            cout << "Error: Invalid landline number format. Please try again.\n";
        }
    } while (strlen(tempLandlineNumber) != 12 || tempLandlineNumber[0] != '0');

    strcpy_s(FirstNames[ContactCount], MaxNameLength, tempFirstName);
    strcpy_s(LastNames[ContactCount], MaxNameLength, tempLastName);
    strcpy_s(Addresses[ContactCount], MaxAddressLength, tempAddress);
    strcpy_s(CellNumbers[ContactCount], MaxCellLength, tempCellNumber);
    strcpy_s(LandlineNumbers[ContactCount], MaxLandlineLength, tempLandlineNumber);

    ofstream TextFile("Contacts.txt", ios::app);

    if (!TextFile) {
        cout << "Error: Unable to open file for writing!\n";
        return;
    }

    TextFile << tempFirstName << '|' << tempLastName << '|' << tempAddress << '|' << tempCellNumber << '|' << tempLandlineNumber << endl;
    TextFile.close();

    ContactCount++;

    cout << "\nContact added successfully!\n\nCONTACT " << ContactCount << ":-\n-----------\nFirst Name: " << tempFirstName << "\nLast Name: " << tempLastName << "\nAddress: " << tempAddress << "\nCell Phone Number: " << tempCellNumber << "\nLandline Number: " << tempLandlineNumber << "\n\n";
}

void DeleteContact(char FirstNames[][MaxNameLength], char LastNames[][MaxNameLength], char Addresses[][MaxAddressLength], char CellNumbers[][MaxCellLength], char LandlineNumbers[][MaxLandlineLength], int& ContactCount) {
    if (ContactCount == 0) {
        cout << "No contacts available to delete.\n";
        return;
    }

    cout << "Search for the contact you want to delete.\n\n";
    SearchContact(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);

    int ContactToDelete = -1;

    cout << "\nEnter the number of the contact you want to delete (1-" << ContactCount << ") or 0 to cancel: ";

    while (!(cin >> ContactToDelete) || ContactToDelete < 0 || ContactToDelete > ContactCount) {
        cout << "Invalid choice! Please select a valid contact number (1-" << ContactCount << ") or 0 to cancel: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (ContactToDelete == 0) {
        cout << "Deletion cancelled.\n";
        return;
    }

    // Adjust to zero-based index
    int IndexToDelete = ContactToDelete - 1;

    // Shift the arrays to remove the contact
    for (int i = IndexToDelete; i < ContactCount - 1; i++) {
        strcpy_s(FirstNames[i], MaxNameLength, FirstNames[i + 1]);
        strcpy_s(LastNames[i], MaxNameLength, LastNames[i + 1]);
        strcpy_s(Addresses[i], MaxAddressLength, Addresses[i + 1]);
        strcpy_s(CellNumbers[i], MaxCellLength, CellNumbers[i + 1]);
        strcpy_s(LandlineNumbers[i], MaxLandlineLength, LandlineNumbers[i + 1]);
    }
    ContactCount--;

    ofstream TextFile("Contacts.txt");

    if (!TextFile) {
        cout << "Error: Unable to open file for updating!\n";
        return;
    }

    for (int i = 0; i < ContactCount; i++) {
        TextFile << FirstNames[i] << '|' << LastNames[i] << '|' << Addresses[i] << '|' << CellNumbers[i] << '|' << LandlineNumbers[i] << endl;
    }
    TextFile.close();

    cout << "\nContact deleted successfully!\n\n";

    DisplayAllContacts(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);
}

void ModifyContact(char FirstNames[][MaxNameLength], char LastNames[][MaxNameLength], char Addresses[][MaxAddressLength], char CellNumbers[][MaxCellLength], char LandlineNumbers[][MaxLandlineLength], int& ContactCount) {
    if (ContactCount == 0) {
        cout << "No contacts available to modify.\n";
        return;
    }

    cout << "Search for the contact you want to modify.\n\n";
    SearchContact(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);

    int ContactToModify = -1;

    cout << "\nEnter the number of the contact you want to modify (1-" << ContactCount << ") or 0 to cancel: ";

    while (!(cin >> ContactToModify) || ContactToModify < 0 || ContactToModify > ContactCount) {
        cout << "Invalid choice! Please select a valid contact number (1-" << ContactCount << ") or 0 to cancel: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (ContactToModify == 0) {
        cout << "Modification cancelled.\n";
        return;
    }

    // Adjust to zero-based index
    int IndexToModify = ContactToModify - 1, ModifyOption = 0;

    cout << "\nWhat would you like to modify?\n1) First Name\n2) Last Name\n3) Address\n4) Cell Number\n5) Landline Number\n\nSelect an option (1-5): ";

    while (!(cin >> ModifyOption) || ModifyOption < 1 || ModifyOption > 5) {
        cout << "Invalid choice. Please select a number from 1 to 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char NewFirstName[MaxNameLength]{}, NewLastName[MaxNameLength]{}, NewAddress[MaxAddressLength]{}, NewCellNumber[MaxCellLength]{}, NewLandlineNumber[MaxLandlineLength]{};

    switch (ModifyOption) {
    case 1: {
        cout << "Enter new first name: ";
        cin.getline(NewFirstName, MaxNameLength);
        strcpy_s(FirstNames[IndexToModify], MaxNameLength, NewFirstName);
        break;
    }
    case 2: {
        cout << "Enter new last name: ";
        cin.getline(NewLastName, MaxNameLength);
        strcpy_s(LastNames[IndexToModify], MaxNameLength, NewLastName);
        break;
    }
    case 3: {
        cout << "Enter new address: ";
        cin.getline(NewAddress, MaxAddressLength);
        strcpy_s(Addresses[IndexToModify], MaxAddressLength, NewAddress);
        break;
    }
    case 4: {
        do {
            cout << "Enter new cell phone number (Format: +92-XXX-XXXXXXXX): ";
            cin.getline(NewCellNumber, MaxCellLength);
            if (strlen(NewCellNumber) != 16 || strncmp(NewCellNumber, "+92-", 4) != 0) {
                cout << "Error: Invalid cell phone number format. Please try again.\n";
            }
        } while (strlen(NewCellNumber) != 16 || strncmp(NewCellNumber, "+92-", 4) != 0);
        strcpy_s(CellNumbers[IndexToModify], MaxCellLength, NewCellNumber);
        break;
    }
    case 5: {
        do {
            cout << "Enter new landline number (Format: 0XX-XXXXXXXX): ";
            cin.getline(NewLandlineNumber, MaxLandlineLength);
            if (strlen(NewLandlineNumber) != 12 || NewLandlineNumber[0] != '0') {
                cout << "Error: Invalid landline number format. Please try again.\n";
            }
        } while (strlen(NewLandlineNumber) != 12 || NewLandlineNumber[0] != '0');
        strcpy_s(LandlineNumbers[IndexToModify], MaxLandlineLength, NewLandlineNumber);
        break;
    }
    }

    ofstream TextFile("Contacts.txt");

    if (!TextFile) {
        cout << "Error: Unable to open file for updating!\n";
        return;
    }

    for (int i = 0; i < ContactCount; i++) {
        TextFile << FirstNames[i] << '|' << LastNames[i] << '|' << Addresses[i] << '|' << CellNumbers[i] << '|' << LandlineNumbers[i] << endl;
    }
    TextFile.close();

    cout << "\nContact modified successfully!\n\nCONTACT " << ContactToModify << ":-\n----------\nFirst Name: " << FirstNames[IndexToModify] << "\nLast Name: " << LastNames[IndexToModify] << "\nAddress: " << Addresses[IndexToModify] << "\nCell Phone Number: " << CellNumbers[IndexToModify] << "\nLandline Number: " << LandlineNumbers[IndexToModify] << "\n\n";
}

void DisplayPattern(char FirstNames[][MaxNameLength], char LastNames[][MaxNameLength], char Addresses[][MaxAddressLength], char CellNumbers[][MaxCellLength], char LandlineNumbers[][MaxLandlineLength], int ContactCount) {
    if (ContactCount == 0) {
        cout << "No contacts available to display.\n";
        return;
    }

    char Pattern[11];

    cout << "Enter the pattern to search for (max 10 characters): ";
    cin.getline(Pattern, 11); // Read up to 10 characters for the pattern

    if (strlen(Pattern) > 10) {
        cout << "Error: Pattern is too long. Please try again.\n";
        return;
    }

    bool Found = false;

    cout << "\nContacts matching the pattern \"" << Pattern << "\"\n";

    for (int i = 0; i < ContactCount; i++) {
        if (strncmp(FirstNames[i], Pattern, strlen(Pattern)) == 0) {
            Found = true;
            cout << "\nContact " << i + 1 << ":-\n----------\nFirst Name: " << FirstNames[i] << "\nLast Name: " << LastNames[i] << "\nAddress: " << Addresses[i] << "\nCell Number: " << CellNumbers[i] << "\nLandline Number: " << LandlineNumbers[i] << "\n";
        }
    }

    for (int i = 0; i < ContactCount; i++) {
        if (strncmp(LastNames[i], Pattern, strlen(Pattern)) == 0) {
            Found = true;
            cout << "\nContact " << i + 1 << ":-\n----------\nFirst Name: " << FirstNames[i] << "\nLast Name: " << LastNames[i] << "\nAddress: " << Addresses[i] << "\nCell Number: " << CellNumbers[i] << "\nLandline Number: " << LandlineNumbers[i] << "\n";
        }
    }

    for (int i = 0; i < ContactCount; i++) {
        if (strncmp(Addresses[i], Pattern, strlen(Pattern)) == 0) {
            Found = true;
            cout << "\nContact " << i + 1 << ":-\n----------\nFirst Name: " << FirstNames[i] << "\nLast Name: " << LastNames[i] << "\nAddress: " << Addresses[i] << "\nCell Number: " << CellNumbers[i] << "\nLandline Number: " << LandlineNumbers[i] << "\n";
        }
    }

    for (int i = 0; i < ContactCount; i++) {
        if (strncmp(CellNumbers[i], Pattern, strlen(Pattern)) == 0) {
            Found = true;
            cout << "\nContact " << i + 1 << ":-\n----------\nFirst Name: " << FirstNames[i] << "\nLast Name: " << LastNames[i] << "\nAddress: " << Addresses[i] << "\nCell Number: " << CellNumbers[i] << "\nLandline Number: " << LandlineNumbers[i] << "\n";
        }
    }

    for (int i = 0; i < ContactCount; i++) {
        if (strncmp(LandlineNumbers[i], Pattern, strlen(Pattern)) == 0) {
            Found = true;
            cout << "\nContact " << i + 1 << ":-\n----------\nFirst Name: " << FirstNames[i] << "\nLast Name: " << LastNames[i] << "\nAddress: " << Addresses[i] << "\nCell Number: " << CellNumbers[i] << "\nLandline Number: " << LandlineNumbers[i] << "\n";
        }
    }

    if (!Found) {
        cout << "No contacts found with \"" << Pattern << "\".\n";
    }
}

void SortContacts(char FirstNames[][MaxNameLength], char LastNames[][MaxNameLength], char Addresses[][MaxAddressLength], char CellNumbers[][MaxCellLength], char LandlineNumbers[][MaxLandlineLength], int ContactCount) {
    if (ContactCount == 0) {
        cout << "No contacts available to sort.\n";
        return;
    }

    int SortOption = 0;

    cout << "Sort contacts by:\n1) First Name\n2) Last Name\n3) Cell Phone Number\n4) Landline Number\n\nSelect an option (1-4): ";

    while (!(cin >> SortOption) || SortOption < 1 || SortOption > 4) {
        cout << "Invalid choice! Please select a number from 1 to 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < ContactCount - 1; i++) {
        for (int j = i + 1; j < ContactCount; j++) {
            bool Swap = false;

            switch (SortOption) {
            case 1:
                if (strcmp(FirstNames[i], FirstNames[j]) > 0) {
                    Swap = true;
                }
                break;
            case 2:
                if (strcmp(LastNames[i], LastNames[j]) > 0) {
                    Swap = true;
                }
                break;
            case 3:
                if (strcmp(CellNumbers[i], LandlineNumbers[j]) > 0) {
                    Swap = true;
                }
                break;
            case 4:
                if (strcmp(LandlineNumbers[i], CellNumbers[j]) > 0) {
                    Swap = true;
                }
                break;
            }

            if (Swap) {
                char tempFirstName[MaxNameLength];
                strcpy_s(tempFirstName, FirstNames[i]);
                strcpy_s(FirstNames[i], FirstNames[j]);
                strcpy_s(FirstNames[j], tempFirstName);

                char tempLastName[MaxNameLength];
                strcpy_s(tempLastName, LastNames[i]);
                strcpy_s(LastNames[i], LastNames[j]);
                strcpy_s(LastNames[j], tempLastName);

                char tempAddress[MaxAddressLength];
                strcpy_s(tempAddress, Addresses[i]);
                strcpy_s(Addresses[i], Addresses[j]);
                strcpy_s(Addresses[j], tempAddress);

                char tempCellNumber[MaxCellLength];
                strcpy_s(tempCellNumber, CellNumbers[i]);
                strcpy_s(CellNumbers[i], CellNumbers[j]);
                strcpy_s(CellNumbers[j], tempCellNumber);

                char tempLandlineNumber[MaxLandlineLength];
                strcpy_s(tempLandlineNumber, LandlineNumbers[i]);
                strcpy_s(LandlineNumbers[i], LandlineNumbers[j]);
                strcpy_s(LandlineNumbers[j], tempLandlineNumber);
            }
        }
    }

    ofstream TextFile("Contacts.txt");

    if (!TextFile) {
        cout << "Error: Unable to open file for updating!\n";
        return;
    }

    for (int i = 0; i < ContactCount; i++) {
        TextFile << FirstNames[i] << '|' << LastNames[i] << '|' << Addresses[i] << '|' << CellNumbers[i] << '|' << LandlineNumbers[i] << endl;
    }
    TextFile.close();

    cout << "\nContacts sorted successfully by ";
    switch (SortOption) {
    case 1: cout << "First Name.\n"; break;
    case 2: cout << "Last Name.\n"; break;
    case 3: cout << "Cell Phone Number.\n"; break;
    case 4: cout << "Landline Number.\n"; break;
    }

    cout << "Updated list of contacts:-\n\n";
    DisplayAllContacts(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);
}

int main() {
    char FirstNames[MaxContacts][MaxNameLength]{}, LastNames[MaxContacts][MaxNameLength]{}, Addresses[MaxContacts][MaxAddressLength]{}, CellNumbers[MaxContacts][MaxCellLength]{}, LandlineNumbers[MaxContacts][MaxLandlineLength]{};
    int ContactCount = 0; // Actual number of contacts in the file

    ifstream TextFile("Contacts.txt");

    if (!TextFile) {
        cout << "Error: Unable to open file!\n";
        return 1;
    }

    // Read the data line by line
    while (TextFile && ContactCount < MaxContacts) {
        TextFile.getline(FirstNames[ContactCount], MaxNameLength, '|');
        TextFile.getline(LastNames[ContactCount], MaxNameLength, '|');
        TextFile.getline(Addresses[ContactCount], MaxAddressLength, '|');
        TextFile.getline(CellNumbers[ContactCount], MaxCellLength, '|');
        TextFile.getline(LandlineNumbers[ContactCount], MaxLandlineLength);

        // If any field fails to read, break out of the loop
        if (TextFile.fail()) {
            break;
        }

        ContactCount++;
    }

    while (true) {
        int Choice = Menu();

        switch (Choice) {
        case 1: {
            cout << "\n------------------------------<:>------------------------------ DISPLAY ALL CONTACTS ------------------------------<:>------------------------------\n\n";
            DisplayAllContacts(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);
            break;
        }
        case 2: {
            cout << "\n------------------------------<:>------------------------------- SEARCH FOR A CONTACT ------------------------------<:>-----------------------------\n\n";
            SearchContact(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);
            break;
        }
        case 3: {
            cout << "\n-------------------------------<:>-------------------------------- ADD A NEW CONTACT ------------------------------<:>------------------------------\n\n";
            AddNewContact(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);
            break;
        }
        case 4: {
            cout << "\n-------------------------------<:>------------------------------- DELETE A CONTACT -------------------------------<:>-------------------------------\n\n";
            DeleteContact(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);
            break;
        }
        case 5: {
            cout << "\n----------------------------<:>------------------------------ MODIFY AN EXISTING CONTACT ----------------------------<:>----------------------------\n\n";
            ModifyContact(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);
            break;
        }
        case 6: {
            cout << "\n-----------------------------<:>---------------------------- DISPLAY CONTACTS BY PATTERN -----------------------------<:>---------------------------\n\n";
            DisplayPattern(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);
            break;
        }
        case 7: {
            cout << "\n-------------------------------<:>-------------------------------- SORT CONTACTS -------------------------------<:>---------------------------------\n\n";
            SortContacts(FirstNames, LastNames, Addresses, CellNumbers, LandlineNumbers, ContactCount);
            break;
        }
        case 8: {
            cout << "Exiting program...\n";
            exit(0);
            break;
        }
        }
    }

    return 0;
}