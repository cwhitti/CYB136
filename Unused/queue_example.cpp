#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Define the Account class
class Account {
public:
    string name;
    string password;
    int adminLevel;

    // Constructor
    Account(string n, string pass, int level) : name(n), password(pass), adminLevel(level) {}
};

// Define a custom comparator for Account objects based on adminLevel
struct AccountComparator {
    bool operator()(const Account& a1, const Account& a2) const {
        // Higher adminLevel has higher priority
        return a1.adminLevel < a2.adminLevel;
    }
};

int main() {
    // Creating a priority queue of Account objects
    priority_queue<Account, vector<Account>, AccountComparator> accountQueue;

    // Inserting elements into the priority queue
    accountQueue.push(Account("Alice", "password123", 2));
    accountQueue.push(Account("Bob", "password456", 3));
    accountQueue.push(Account("Charlie", "password789", 1));

    // Printing the elements of the priority queue
    cout << "Priority Queue elements: ";
    while (!accountQueue.empty()) {
        Account topAccount = accountQueue.top();
        cout << "Name: " << topAccount.name << ", Admin Level: " << topAccount.adminLevel << endl;
        accountQueue.pop();
    }

    return 0;
}
