# Bank-Management-System-Using-Cpp-Language
The Bank Management System allows users to manage bank accounts by performing basic operations like creating an account, depositing money, withdrawing money, viewing account details, and saving/loading data to/from a file.

Bank Management System

Overview:
The Bank Management System allows users to manage bank accounts by performing basic operations like creating an account, depositing money, withdrawing money, viewing account details, and saving/loading data to/from a file.

Features:
1. Create Account: Users can create new bank accounts by providing an account number, account holder's name, and an initial deposit.
2. Deposit Money: Users can deposit money into an existing account.
3. Withdraw Money: Users can withdraw money from an existing account if there is sufficient balance.
4. View Account Details: Users can view the details of an existing account, including the account number, holder's name, and balance.
5. Save and Load Data: The system saves the bank account details to a text file and loads the data when the program is restarted.

Technologies Used:

C++ Programming Language

File I/O for saving and loading account data


File Structure:
The program uses the following files:

BankAccounts.txt: This file is used to store the bank account data (account number, account holder name, and balance). It is read when the program starts and saved when the program exits.


How to Use:

1. Compile the program: To compile the C++ program, use the following command in your terminal:
   g++ -o BankManagementSystem BankManagementSystem.cpp

2. Run the program: After compiling, run the program with the following command:
   ./BankManagementSystem


3. Use the menu: The program will present a menu with the following options:

1. Create Account: Create a new bank account.
2. Deposit Money: Deposit money into an existing account.
3. Withdraw Money: Withdraw money from an existing account.
4. View Account Details: View details of an existing account.
5. Save and Exit: Save all account data to a file and exit the program.
4. Data Persistence:
Bank account details are automatically saved to BankAccounts.txt when you exit the program (option 5).
Upon starting the program again, data will be loaded from BankAccounts.txt if it exists.

Example Usage:

Create an Account: Enter account number, holder's name, and an initial deposit.

Enter Account Number: 12345

Enter Account Holder Name: John Doe

Enter Initial Deposit: 1000

Account created successfully!

Deposit Money: Enter the account number and amount to deposit.

Enter Account Number: 12345

Enter amount to deposit: 500

Deposit successful! New balance: $1500.00

Withdraw Money: Enter the account number and amount to withdraw.

Enter Account Number: 12345

Enter amount to withdraw: 200

Withdrawal successful! New balance: $1300.00

View Account Details: Enter the account number to view the details.

Enter Account Number: 12345

Account Number: 12345

Account Holder: John Doe

Balance: $1300.00

Error Handling:
Invalid deposit or withdrawal amounts are handled with appropriate error messages.
If an account number does not exist, the user is informed that the account is not found.

Notes:
The system uses file-based storage, so the data persists between runs of the program. The file BankAccounts.txt is created in the working directory.
Ensure that the program has read/write permissions for the file BankAccounts.txt.
