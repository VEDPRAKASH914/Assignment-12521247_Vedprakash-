#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class GPayUser {
private:
    string userId;
    string name;
    string upiId;
    double balance;

public:
    // Parameterless Constructor
    GPayUser() {
        userId = "";
        name = "";
        upiId = "";
        balance = 0.0;
    }

    // Destructor
    ~GPayUser() {
        cout<<"user account destroyed Successfully";
    }

    void setUserId(string id) { userId = id; }
    void setName(string newName) { name = newName; }
    void setUpiId(string newUpiId) { upiId = newUpiId; }
    void setBalance(double newBalance) {
        if (newBalance >= 0) {
            balance = newBalance;
        } else {
            cout << "Invalid balance amount.\n";
        }
    }
    string getUserId() { return userId; }
    string getName() { return name; }
    string getUpiId() { return upiId; }
    double getBalance() { return balance; }

    void addMoney(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Added Rs " << amount << " to " << name << "'s account.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    bool sendMoney(GPayUser& receiver, double amount) {
        if (amount <= 0) {
            cout << "Transaction failed: Invalid amount.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Transaction failed: Insufficient balance for " << name << ".\n";
            return false;
        }
        
        balance -= amount;
        receiver.balance += amount;

        cout << "Successfully transferred Rs " << fixed << setprecision(2) 
             << amount << " from " << name << " (" << upiId 
             << ") to " << receiver.getName() << " (" << receiver.getUpiId() << ").\n";
        return true;
    }

    void displayDetails() {
        cout << "User ID: " << userId
             << " Name: " << name 
             << " UPI ID: " << upiId 
             << " Balance: Rs " << fixed << setprecision(2) << balance << "\n";
    }
};

int main() {
    GPayUser user[5];

    // Read input using temporary local variables
    cout << "Enter details for 5 users (UserID Name UPI_ID Balance):\n";
    for(int i = 0; i < 5; i++) {
        string id, uName, upi;
        double bal;
        
        cin >> id >> uName >> upi >> bal;

        user[i].setUserId(id);
        user[i].setName(uName);
        user[i].setUpiId(upi);
        user[i].setBalance(bal);
    }

    cout << "\nInitial Account Details:\n";
    for(int i = 0; i < 5; i++) {
        user[i].displayDetails();
    }
 
    cout << "\nUpdating User Profile:\n";
    user[4].setName("Evan Wright");
    user[4].setBalance(100.00);
    cout << "Updated User 5 Name: " << user[4].getName() << "\n";
    cout << "Updated User 5 Balance: Rs " << user[4].getBalance() << "\n\n";

    cout << "Payment Simulations:\n";
    user[0].sendMoney(user[1], 150.00);
    user[2].sendMoney(user[3], 500.00); 
    user[3].sendMoney(user[4], 200.00); 

    cout << "\nFinal Account Details:\n";
    for(int i = 0; i < 5; i++) {
        user[i].displayDetails();
    }

    return 0;
}