#include <bits/stdc++.h>
using namespace std;

class Account {
private:
    int accNo;
    string name;
    double balance;

public:
    Account() {}
    Account(int accNo, string n, double b) {
        this->accNo = accNo;  // ✅ member variable ঠিকভাবে assign
        name = n;
        balance = b;
    }

    void createAccount() {
        cout << "Enter Account number: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit(double amt) {
        balance += amt;
        cout << "Deposited: " << amt << " | New Balance: " << balance << endl;
    }

    void withdraw(double amt) {
        if (amt > balance)
            cout << "Insufficient Balance!\n";
        else {
            balance -= amt;
            cout << "Withdrawn: " << amt << " | New Balance: " << balance << endl;
        }
    }

    void display() const {
        cout << "Account No: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    int getAccNo() const { return accNo; }
    double getBalance() const { return balance; }
    string getName() const { return name; }
};

// -------- File Handling --------
void saveAccount(const Account &acc) {
    ofstream fout("bankdata.txt", ios::app);
    if (fout.is_open()) {
        fout << acc.getAccNo() << "," << acc.getName() << "," << acc.getBalance() << "\n";
        fout.close();
    }
}

void showAllAccounts() {
    ifstream fin("bankdata.txt");
    string line;
    cout << "\n--- All Account Details ---\n";
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

int main() {
    vector<Account> accounts;
    int choice;
    do {
        cout << "\n===== Bank Management System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show All Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Account acc;
            acc.createAccount();
            accounts.push_back(acc);
            saveAccount(acc);
        }
        else if (choice == 2) {
            int no; double amt;
            cout << "Enter Account No: "; cin >> no;
            cout << "Enter Amount: "; cin >> amt;
            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccNo() == no) {
                    acc.deposit(amt);
                    found = true;
                }
            }
            if (!found) cout << "Account not found!\n";
        }
        else if (choice == 3) {
            int no; double amt;
            cout << "Enter Account No: "; cin >> no;
            cout << "Enter Amount: "; cin >> amt;
            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccNo() == no) {
                    acc.withdraw(amt);
                    found = true;
                }
            }
            if (!found) cout << "Account not found!\n";
        }
        else if (choice == 4) {
            showAllAccounts();
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
