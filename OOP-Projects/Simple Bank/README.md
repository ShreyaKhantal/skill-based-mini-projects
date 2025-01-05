# Bank Management System

## Overview

The **Bank Management System** is a C++ console application designed to simulate a banking environment where users can manage different types of accounts, including **Savings Accounts** and **Checking Accounts**. The system supports operations like account creation, deposit, withdrawal, balance check, interest application, money transfer between accounts, and account deletion.

## Features

1. **Create Account**: 
   - Create a Savings Account with interest rate and Checking Account with overdraft limit.
   
2. **Deposit**: 
   - Deposit funds into an existing account.
   
3. **Withdraw**: 
   - Withdraw funds from an account with checks for sufficient balance and overdraft limit (for checking accounts).
   
4. **Check Balance**: 
   - View the balance of an account.
   
5. **Apply Interest (for Savings Accounts)**: 
   - Apply interest to savings account based on the interest rate.
   
6. **Transfer Money**: 
   - Transfer funds between two different accounts.
   
7. **Delete Account**: 
   - Delete an existing account.
   
8. **Display Account Information**: 
   - View account details, including account holder’s name, account number, balance, and additional details like interest rate (Savings Account) or overdraft limit (Checking Account).
   
9. **Display All Accounts**: 
   - View details for all created accounts.

## Technologies

- **Language**: C++
- **Paradigm**: Object-Oriented Programming (OOP)
- **Key Concepts**: Inheritance, Polymorphism, Virtual Functions

## Class Structure

1. **Account Class**:
   - Base class for both Savingacc and Checkingacc. Handles basic operations like deposit, withdraw, check balance, transfer money, and display account details.

2. **Savingacc Class**:
   - Derived from the Account class, it implements savings-specific behavior, such as applying interest.

3. **Checkingacc Class**:
   - Derived from the Account class, it includes features related to checking accounts, such as handling overdraft limits when withdrawing funds.

## How to Run

1. Ensure you have a C++ compiler (such as GCC or MSVC).
2. Create a file named `bank_system.cpp` and paste the provided code into it.
3. Compile the code:
   ```bash
   g++ bank_system.cpp -o bank_system
   ```
4. Run the compiled application:
   ```bash
   ./bank_system
   ```

## Usage

Once the program is executed, you will be presented with a menu with the following options:

1. **Create Savings Account**: Create a savings account for a customer.
2. **Create Checking Account**: Create a checking account for a customer.
3. **Deposit**: Deposit a specified amount into an account.
4. **Withdraw**: Withdraw a specified amount from an account.
5. **Check Balance**: Check the current balance of an account.
6. **Apply Interest (Savings Account)**: Apply interest to a savings account.
7. **Display Account Information**: View details of an account.
8. **Delete Account**: Delete an account.
9. **Display All Accounts**: View details of all accounts.
10. **Transfer Money**: Transfer money between two accounts.
11. **Exit**: Exit the program.

### Example of Operations

- **Create a Savings Account**:
  - Account Holder: John Doe
  - Account Number: 123456
  - Initial Balance: 1000 Rs
  - Interest Rate: 4.5%
  
- **Deposit 500 Rs into the account**:
  - The new balance will be displayed after the deposit.
  
- **Withdraw 200 Rs from the account**:
  - If the balance is sufficient, the withdrawal will be successful and the new balance will be displayed.
  
- **Apply Interest**:
  - If the account is a savings account, applying the interest will increase the balance based on the specified rate.

## Known Issues

- Ensure that account numbers are unique.
- Maximum number of accounts is fixed at 100. The system will not allow more accounts to be created beyond this limit.
