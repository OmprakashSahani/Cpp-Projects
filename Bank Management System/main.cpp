#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

// Class to represent a bank account
class BankAccount {
public:
    int accountNumber;
    string accountHolderName;
    float balance;

    BankAccount(int accNum, string name, float initialDeposit)
        : accountNumber(accNum), accountHolderName(name), balance(initialDeposit) {}

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: $" << fixed << setprecision(2) << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    void display() const {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolderName;
        cout << "\nBalance: $" << fixed << setprecision(2) << balance << "\n";
    }
};

// Function prototypes
void createAccount(vector<BankAccount>& accounts);
void depositMoney(vector<BankAccount>& accounts);
void withdrawMoney(vector<BankAccount>& accounts);
void viewAccount(const vector<BankAccount>& accounts);
void saveAccountsToFile(const vector<BankAccount>& accounts);
void loadAccountsFromFile(vector<BankAccount>& accounts);

// Main menu function
void menu() {
    vector<BankAccount> accounts;
    loadAccountsFromFile(accounts);

    int choice;
    do {
        cout << "\n--- Bank Management System ---";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. View Account Details";
        cout << "\n5. Save and Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                depositMoney(accounts);
                break;
            case 3:
                withdrawMoney(accounts);
                break;
            case 4:
                viewAccount(accounts);
                break;
            case 5:
                saveAccountsToFile(accounts);
                cout << "Data saved. Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

// Function to create a new account
void createAccount(vector<BankAccount>& accounts) {
    int accountNumber;
    string name;
    float initialDeposit;

    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Initial Deposit: ";
    cin >> initialDeposit;

    accounts.emplace_back(accountNumber, name, initialDeposit);
    cout << "Account created successfully!\n";
}

// Function to deposit money
void depositMoney(vector<BankAccount>& accounts) {
    int accountNumber;
    float amount;

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to withdraw money
void withdrawMoney(vector<BankAccount>& accounts) {
    int accountNumber;
    float amount;

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account.withdraw(amount);
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to view account details
void viewAccount(const vector<BankAccount>& accounts) {
    int accountNumber;

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (const auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            account.display();
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to save accounts to a file
void saveAccountsToFile(const vector<BankAccount>& accounts) {
    ofstream outFile("BankAccounts.txt");
    if (outFile.is_open()) {
        for (const auto& account : accounts) {
            outFile << account.accountNumber << " "
                    << account.accountHolderName << " "
                    << account.balance << "\n";
        }
        outFile.close();
    } else {
        cout << "Error saving data to file.\n";
    }
}

// Function to load accounts from a file
void loadAccountsFromFile(vector<BankAccount>& accounts) {
    ifstream inFile("BankAccounts.txt");
    if (inFile.is_open()) {
        int accountNumber;
        string name;
        float balance;

        while (inFile >> accountNumber) {
            inFile.ignore();
            getline(inFile, name);
            inFile >> balance;
            accounts.emplace_back(accountNumber, name, balance);
        }
        inFile.close();
    }
}

int main() {
    menu();
    return 0;
}
