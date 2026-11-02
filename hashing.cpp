#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Client {
    string name;
    string phone;
    bool occupied;

    Client() {
        name = "";
        phone = "";
        occupied = false;
    }
};

// 1. LINEAR PROBING
class LinearHashTable {
    Client table[SIZE];

    int hashFunction(string name) {
        int hash = 0;
        for (char c : name)
            hash = (hash + c) % SIZE;
        return hash;
    }

public:
    void insert(string name, string phone) {
        int index = hashFunction(name);
        int original = index;

        do {
            if (!table[index].occupied) {
                table[index].name = name;
                table[index].phone = phone;
                table[index].occupied = true;
                cout << "Client inserted successfully.\n";
                return;
            }

            if (table[index].name == name) {
                cout << "Client already exists.\n";
                return;
            }

            index = (index + 1) % SIZE;

        } while (index != original);

        cout << "Hash table is full!\n";
    }

    void search(string name) {
        int index = hashFunction(name);
        int original = index;

        do {
            if (!table[index].occupied)
                break;

            if (table[index].name == name) {
                cout << "Phone number: "
                     << table[index].phone << endl;
                return;
            }

            index = (index + 1) % SIZE;

        } while (index != original);

        cout << "Client not found.\n";
    }

    void display() {
        cout << "\n--- Linear Probing ---\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";

            if (table[i].occupied)
                cout << table[i].name << " -> "
                     << table[i].phone;
            else
                cout << "Empty";

            cout << endl;
        }
    }
};


// 2. QUADRATIC PROBING
class QuadraticHashTable {
    Client table[SIZE];

    int hashFunction(string name) {
        int hash = 0;
        for (char c : name)
            hash = (hash + c) % SIZE;
        return hash;
    }

public:
    void insert(string name, string phone) {
        int start = hashFunction(name);

        for (int i = 0; i < SIZE; i++) {
            int index = (start + i * i) % SIZE;

            if (!table[index].occupied) {
                table[index].name = name;
                table[index].phone = phone;
                table[index].occupied = true;

                cout << "Client inserted successfully.\n";
                return;
            }

            if (table[index].name == name) {
                cout << "Client already exists.\n";
                return;
            }
        }

        cout << "No available slot found by quadratic probing.\n";
    }

    void search(string name) {
        int start = hashFunction(name);

        for (int i = 0; i < SIZE; i++) {
            int index = (start + i * i) % SIZE;

            if (!table[index].occupied)
                break;

            if (table[index].name == name) {
                cout << "Phone number: "
                     << table[index].phone << endl;
                return;
            }
        }

        cout << "Client not found.\n";
    }

    void display() {
        cout << "\n--- Quadratic Probing ---\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";

            if (table[i].occupied)
                cout << table[i].name << " -> "
                     << table[i].phone;
            else
                cout << "Empty";

            cout << endl;
        }
    }
};


// 3. DOUBLE HASHING
class DoubleHashTable {
    Client table[SIZE];

    int hash1(string name) {
        int hash = 0;
        for (char c : name)
            hash = (hash + c) % SIZE;
        return hash;
    }

    int hash2(string name) {
        int hash = 0;
        for (char c : name)
            hash = (hash + c) % 4;

        const int steps[4] = {1, 3, 7, 9};
        return steps[hash];
    }

public:
    void insert(string name, string phone) {
        int h1 = hash1(name);
        int h2 = hash2(name);

        for (int i = 0; i < SIZE; i++) {
            int index = (h1 + i * h2) % SIZE;

            if (!table[index].occupied) {
                table[index].name = name;
                table[index].phone = phone;
                table[index].occupied = true;

                cout << "Client inserted successfully.\n";
                return;
            }

            if (table[index].name == name) {
                cout << "Client already exists.\n";
                return;
            }
        }

        cout << "Hash table is full!\n";
    }

    void search(string name) {
        int h1 = hash1(name);
        int h2 = hash2(name);

        for (int i = 0; i < SIZE; i++) {
            int index = (h1 + i * h2) % SIZE;

            if (!table[index].occupied)
                break;

            if (table[index].name == name) {
                cout << "Phone number: "
                     << table[index].phone << endl;
                return;
            }
        }

        cout << "Client not found.\n";
    }

    void display() {
        cout << "\n--- Double Hashing ---\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";

            if (table[i].occupied)
                cout << table[i].name << " -> "
                     << table[i].phone;
            else
                cout << "Empty";

            cout << endl;
        }
    }
};


// MAIN FUNCTION
int main() {
    LinearHashTable linear;
    QuadraticHashTable quadratic;
    DoubleHashTable doubleHash;

    int choice, operation;
    string name, phone;

    do {
        cout << "\n===== HASHING TECHNIQUES =====\n";
        cout << "1. Linear Probing\n";
        cout << "2. Quadratic Probing\n";
        cout << "3. Double Hashing\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {

            do {
                cout << "\n1. Insert Client\n";
                cout << "2. Search Client\n";
                cout << "3. Display Hash Table\n";
                cout << "4. Back to Main Menu\n";

                cout << "Enter operation: ";
                cin >> operation;

                if (operation == 1) {
                    cout << "Enter client name: ";
                    cin >> ws;
                    getline(cin, name);

                    cout << "Enter phone number: ";
                    getline(cin, phone);

                    if (choice == 1)
                        linear.insert(name, phone);
                    else if (choice == 2)
                        quadratic.insert(name, phone);
                    else
                        doubleHash.insert(name, phone);
                }

                else if (operation == 2) {
                    cout << "Enter client name to search: ";
                    cin >> ws;
                    getline(cin, name);

                    if (choice == 1)
                        linear.search(name);
                    else if (choice == 2)
                        quadratic.search(name);
                    else
                        doubleHash.search(name);
                }

                else if (operation == 3) {
                    if (choice == 1)
                        linear.display();
                    else if (choice == 2)
                        quadratic.display();
                    else
                        doubleHash.display();
                }

                else if (operation != 4) {
                    cout << "Invalid operation. Try again.\n";
                }

            } while (operation != 4);
        }

        else if (choice != 4) {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    cout << "Program terminated.\n";

    return 0;
}
