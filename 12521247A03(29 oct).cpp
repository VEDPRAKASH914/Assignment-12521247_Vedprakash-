#include <iostream>
#include <string>
using namespace std;
class BaseAccountClass {
protected:
    string accholder;
    double bal;
    bool isflag;
public:
    BaseAccountClass(string name, double initialbal, bool flag) 
        : accholder(name), bal(initialbal), isflag(flag) {}

    virtual void SendMoney(double amount) {
        if (isflag) {
            cout << "permission denied: " << accholder <<endl;
            return;
        }
        if (amount > bal) {
            cout << "Insufficient balance."<<endl;
            return;
        }
        bal -= amount;
        cout << "Successfully sent " << amount <<endl<< "Remaining bal: " << bal <<endl;
    }

    virtual void ReceiveMoney(double amount) {
        if (isflag) {
            cout << "Insufficient balance." << accholder <<endl;
            return;
        }
        bal += amount;
        cout << "Successfully received " << amount << endl<<"New bal: " << bal <<endl;
    }

    void SetFlagStatus(bool status) {
        isflag = status;
        cout << "Account " << accholder << " flag status updated to: " << (isflag ? "flag (Restricted)" : "Normal (Active)") <<endl;
    }

    virtual ~BaseAccountClass() {}
};

class ConsumerAccountClass : public BaseAccountClass {
public:
    ConsumerAccountClass(string name, double initialbal, bool flag) 
        : BaseAccountClass(name, initialbal, flag) {}

    void SendMoney(double amount) override {
        if (isflag) {
            cout << "Security Alert: Outbound transaction blocked due to flag account status."<<endl;
            return;
        }
        if (amount > bal) {
            cout << "Transaction failed: Insufficient funds."<<endl;
            return;
        }
        bal -= amount;
        cout << "Sent " << amount << endl<<"Current bal: " << bal <<endl;
    }

    void ReceiveMoney(double amount) override {
        if (isflag) {
            cout << "Security Alert: Inbound deposit restricted due to flag account status.";
            return;
        }
        bal += amount;
        cout << " Received " << amount <<endl<<"Current bal: " << bal << endl;
    }
};

int main() {
    BaseAccountClass* userAccount = new ConsumerAccountClass("Alice", 5000.0, false);

    cout << "Normal State Operations "<<endl;
    userAccount->SendMoney(1000.0);
    userAccount->ReceiveMoney(500.0);

    cout << "Flagging Account"<<endl;
    userAccount->SetFlagStatus(true);

    cout << "Operations After Flagging"<<endl;
    userAccount->SendMoney(200.0);
    userAccount->ReceiveMoney(300.0);

    cout << "Restoring Account"<<endl;
    userAccount->SetFlagStatus(false);

    cout << "Operations After Restoring"<<endl;
    userAccount->SendMoney(200.0);

    delete userAccount;
    return 0;
}