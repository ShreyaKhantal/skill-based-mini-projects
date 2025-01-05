#include <iostream>
#include<string>
using namespace std;

class Account{
protected:
    string name;
    double bal;//balance
    string accnum;

public:
    Account(string n, double b,string c) :name(n),bal(b),accnum(c) {}

    double checkbalance() {return bal;} 
    string getaccnum(){ return accnum;}

    void deposit(double amt){
        if (amt>0){
            bal+=amt;
            cout<<"Deposited: "<<amt<<" Rs"<<endl;
        }else{
            cout<<"Invalid Deposit Amount"<<endl;
        }
    }
    virtual void withdraw(double amt){
        if(amt > 0 && amt <=bal){
            bal-=amt;
            cout<<"Withdrew: "<<amt<<" Rs"<<endl;
        }else{
            cout<<"Insufficient balance or invalid amount\n";
        }
    }
    virtual void displayacc() {
        cout<<"Account Holder Name: "<<name<<endl;
        cout<<"Account number: "<<accnum<<endl;
        cout<<"Balance: "<<bal<<" Rs"<<endl;
    }
    virtual bool isSavingsAccount(){
        return false;
    }
    virtual void applyint() {}

    void transfer(Account* to, double amt) {
        if (amt > 0 && amt <= bal) {
            bal -= amt;
            to->deposit(amt);
            cout << "Transferred: " << amt << " Rs to Account Number: " << to->getaccnum() << endl;
        } else {
            cout << "Insufficient balance or invalid amount\n";
        }
    }
};

class Savingacc : public Account{
    double rate;

public:
    Savingacc(string n, string an, double bal, double r) : Account(n,bal,an),rate(r){}

    bool isSavingsAccount()override {
        return true;
    }
    void applyint() override{
        double interest = bal * (rate/100);
        bal+=interest;
        cout<<"Interest applied: "<<interest<<endl;
        cout<<"New Balance: "<<bal<<endl;
    }
    void displayacc() override {
        cout << "--- Savings Account ---" << endl;
        Account::displayacc();
        cout << "Interest Rate: " << rate << "%" << endl;
    }
};

class Checkingacc : public Account{
    double overdraft;
public:
    Checkingacc(string n, string an, double bal, double r) : Account(n,bal,an),overdraft(r){}

    void withdraw(double amt) override{
    if (amt > 0 && amt <= bal + overdraft) {
            bal -= amt;
            cout<< "Withdrew: " <<amt<<" Rs"<<endl;
        } else {
            cout<<"Overdraft limit exceeded or invalid amount!"<<endl;
        }
    }
     void displayacc()override {
        cout << "--- Checking Account ---" << endl;
        Account::displayacc();
        cout << "Overdraft Limit: "<< overdraft<<" Rs"<<endl;
    }
};
int main(){
    const int maxacc=100;
    Account* acc[maxacc];
    int numacc=0;
    int ch;

    cout << "\n--- Bank Management System ---" << endl;
    cout << "1. Create Savings Account" << endl;
    cout << "2. Create Checking Account" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Check Balance" << endl;
    cout << "6. Apply Interest (Savings Account)" << endl;
    cout << "7. Display Account Information" << endl;
    cout << "8. Delete Account" << endl;
    cout << "9. Display All Accounts" << endl;
    cout << "10. Transfer Money"<<endl;
    cout << "11. Exit" << endl;

    do{
        cout << "\nEnter your choice: ";
        cin>>ch;
        cin.ignore();

        string name, accnum,toaccnum;
        double amt, balance, rate, overdraft;
        switch (ch) {
            case 1:
                if (numacc < maxacc) {
                    cout << "Enter account holder name: ";
                    getline(cin,accnum);
                    cout << "Enter account number: ";
                    cin >> accnum;
                    cout << "Enter initial balance: ";
                    cin >> balance;
                    cout << "Enter interest rate: ";
                    cin >> rate;
                    acc[numacc++] = new Savingacc(name, accnum, balance, rate);
                    cout << "Savings account created successfully!" << endl;
                } else {
                    cout << "Maximum number of accounts reached." << endl;
                }
                break;
            case 2:
                if (numacc < maxacc) {
                    cout << "Enter account holder name: ";
                    getline(cin,accnum);
                    cout << "Enter account number: ";
                    cin >> accnum;
                    cout << "Enter initial balance: ";
                    cin >> balance;
                    cout << "Enter overdraft limit: ";
                    cin >> overdraft;
                    acc[numacc++] = new Checkingacc(name, accnum, balance, overdraft);
                    cout << "Checking account created successfully!" << endl;
                }else{
                    cout << "Maximum number of accounts reached." << endl;
                }
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accnum;
                cout << "Enter deposit amount: ";
                cin >> amt;
                for (int i = 0; i < numacc; ++i) {
                    if (acc[i]->getaccnum() == accnum) {
                        acc[i]->deposit(amt);
                        break;
                    }else{
                        cout<<"Account does not exist!\n";
                    }
                }
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> accnum;
                cout << "Enter withdrawal amount: ";
                cin >> amt;
                for (int i = 0; i < numacc; ++i) {
                    if (acc[i]->getaccnum() == accnum) {
                        acc[i]->withdraw(amt);
                        break;
                    }
                }
                break;
            case 5:
                cout << "Enter account number: ";
                cin >> accnum;
                for (int i = 0; i < numacc; ++i) {
                    if (acc[i]->getaccnum() == accnum) {
                        cout << "Balance: " << acc[i]->checkbalance()<<" Rs" << endl;
                        break;
                    }else{
                        cout<<"Account does not exist!\n";
                    }
                }
                break;
            case 6:{
                cout << "Enter account number: ";
                cin >> accnum;
                bool found = false;
                for (int i = 0; i < numacc; ++i) {
                    if (acc[i]->getaccnum() == accnum) {
                        if (acc[i]->isSavingsAccount()) {
                            acc[i]->applyint();
                        } else {
                            cout << "Not a savings account!" << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account does not exist" << endl;
                }
                break;
            }
            case 7:{
                bool found = false;
                cout << "Enter account number: ";
                cin >> accnum;
                for (int i = 0; i < numacc; ++i) {
                    if (acc[i]->getaccnum() == accnum) {
                        acc[i]->displayacc();
                        found=true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account does not exist" << endl;
                }
                break;
            }
            case 8:
                cout << "Enter account number to delete: ";
                cin >> accnum;
                for (int i = 0; i < numacc; ++i) {
                    if (acc[i]->getaccnum() == accnum) {
                        delete acc[i];
                        for (int j = i; j < numacc - 1; ++j) {
                            acc[j] = acc[j + 1];
                        }
                        numacc--;
                        cout << "Account deleted successfully!" << endl;
                        break;
                    }
                }
                break;
            case 9:
                for (int i = 0; i < numacc; ++i) {
                    acc[i]->displayacc();
                }
                break;
            case 10: { // Transfer money case
                cout << "Enter source account number: ";
                cin >> accnum;
                cout << "Enter destination account number: ";
                cin >> toaccnum;
                cout << "Enter transfer amount: ";
                cin >> amt;
                Account* fromacc = nullptr;
                Account* toacc = nullptr;
                for (int i = 0; i < numacc; ++i) {
                    if (acc[i]->getaccnum() == accnum) {
                        fromacc = acc[i];
                    }
                    if (acc[i]->getaccnum() == toaccnum) {
                        toacc = acc[i];
                    }
                }
                if (fromacc && toacc) {
                    fromacc->transfer(toacc, amt);
                } else {
                    cout << "Invalid account number(s) provided." << endl;
                }
                break;
            }

            case 11:
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (ch != 11);
    return 0;
}
    
