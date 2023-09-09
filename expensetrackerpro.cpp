#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class User {
public:
    string username;
    string password;

    User() : username(""), password("") {}
    User(const string& username, const string& password) : username(username), password(password) {}
};

class Transaction {
public:
    string description;
    double amount;

    Transaction() : description(""), amount(0.0) {}
    Transaction(const string& description, double amount) : description(description), amount(amount) {}
};

class Budget {
public:
    double income;
    double expense;

    Budget() : income(0.0), expense(0.0) {}
    Budget(double income, double expense) : income(income), expense(expense) {}
};

class FinancialGoal {
public:
    string description;
    double targetAmount;
    double currentAmount;

    FinancialGoal() : description(""), targetAmount(0.0), currentAmount(0.0) {}
    FinancialGoal(const string& description, double targetAmount) : description(description), targetAmount(targetAmount), currentAmount(0.0) {}
};

class TransactionManagementSystem {
private:
    map<string, User> users;
    vector<Transaction> transactions;
    Budget budget;
    vector<FinancialGoal> goals;

    const string userFile = "users.txt";
    const string transactionFile = "transactions.txt";

public:
    TransactionManagementSystem() {
        loadUsers();
        loadTransactions();
    }

    void loadUsers() {
        ifstream file(userFile);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(',');
                if (pos != string::npos) {
                    string username = line.substr(0, pos);
                    string password = line.substr(pos + 1);
                    users[username] = User(username, password);
                }
            }
            file.close();
        }
    }

    void loadTransactions() {
        ifstream file(transactionFile);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(',');
                if (pos != string::npos) {
                    string description = line.substr(0, pos);
                    double amount = stod(line.substr(pos + 1));
                    transactions.push_back(Transaction(description, amount));
                }
            }
            file.close();
        }
    }

    void saveUsers() {
        ofstream file(userFile);
        if (file.is_open()) {
            for (const auto& entry : users) {
                file << entry.first << "," << entry.second.password << endl;
            }
            file.close();
        }
    }

    void saveTransactions() {
        ofstream file(transactionFile);
        if (file.is_open()) {
            for (const Transaction& transaction : transactions) {
                file << transaction.description << "," << transaction.amount << endl;
            }
            file.close();
        }
    }

    double getTotalSpent() const {
        double totalSpent = 0.0;
        for (const Transaction& transaction : transactions) {
            totalSpent += transaction.amount;
        }
        return totalSpent;
    }

    double getRemainingBalance() const {
        return budget.income - getTotalSpent();
    }

    void registerUser() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        users[username] = User(username, password);
        saveUsers();
    }

    bool authenticateUser() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (users.count(username) > 0 && users[username].password == password) {
            return true;
        }
        return false;
    }

    void addTransaction() {
        string description;
        double amount;
        cout << "Enter transaction description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter transaction amount: $";
        cin >> amount;
        transactions.push_back(Transaction(description, amount));
        saveTransactions();
    }

    void setBudget() {
        double income, expense;
        cout << "Enter income: $";
        cin >> income;
        cout << "Enter expenses: $";
        cin >> expense;
        budget = Budget(income, expense);
    }

    void addFinancialGoal() {
        string description;
        double targetAmount;
        cout << "Enter financial goal description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter target amount: $";
        cin >> targetAmount;
        goals.push_back(FinancialGoal(description, targetAmount));
    }

    void displayTransactions() {
        cout << "Transactions:\n";
        for (const Transaction& t : transactions) {
            cout << t.description << ": $" << t.amount << endl;
        }
    }

    void displayBudget() {
        cout << "Budget:\n";
        cout << "Income: $" << budget.income << "\nExpense: $" << budget.expense << endl;
    }

    void displayFinancialGoals() {
        cout << "Financial Goals:\n";
        for (const FinancialGoal& goal : goals) {
            cout << goal.description << ": $" << goal.currentAmount << " / $" << goal.targetAmount << endl;
        }
    }
};

int main() {
    TransactionManagementSystem tms;

    int choice;
    bool authenticated = false;

    while (true) {
        cout << "\nWelcome to ExpenseTrackerPro!\n";
        cout << "\nMENU:\n";
        cout << "\n1. Register\n";
        cout << "2. Login\n";
        cout << "3. Add Transaction\n";
        cout << "4. Set Budget\n";
        cout << "5. Add Financial Goal\n";
        cout << "6. Display Transactions\n";
        cout << "7. Display Budget\n";
        cout << "8. Display Financial Goals\n";
        cout << "9. Logout\n";
        cout << "10. Check Balance\n";
        cout << "11. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tms.registerUser();
                break;
            case 2:
                authenticated = tms.authenticateUser();
                if (authenticated) {
                    cout << "Authentication successful.\n";
                } else {
                    cout << "Authentication failed.\n";
                }
                break;
            case 3:
                if (authenticated) {
                    tms.addTransaction();
                } else {
                    cout << "Please log in first.\n";
                }
                break;
            case 4:
                if (authenticated) {
                    tms.setBudget();
                } else {
                    cout << "Please log in first.\n";
                }
                break;
            case 5:
                if (authenticated) {
                    tms.addFinancialGoal();
                } else {
                    cout << "Please log in first.\n";
                }
                break;
            case 6:
                if (authenticated) {
                    tms.displayTransactions();
                } else {
                    cout << "Please log in first.\n";
                }
                break;
            case 7:
                if (authenticated) {
                    tms.displayBudget();
                } else {
                    cout << "Please log in first.\n";
                }
                break;
            case 8:
                if (authenticated) {
                    tms.displayFinancialGoals();
                } else {
                    cout << "Please log in first.\n";
                }
                break;
            case 9:
                authenticated = false;
                cout << "Logged out successfully.\n";
                break;
            case 10:
                if (authenticated) {
                    double spent = tms.getTotalSpent();
                    double remaining = tms.getRemainingBalance();
                    cout << "Total Spent: $" << spent << endl;
                    cout << "Remaining Balance: $" << remaining << endl;
                } else {
                    cout << "Please log in first.\n";
                }
                break;
            case 11:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
