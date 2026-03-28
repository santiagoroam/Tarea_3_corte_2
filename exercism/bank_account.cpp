#include <iostream>
#include <mutex>
using namespace std;

class BankAccount {
private:
    int balance;
    bool abierta;
    mutex mtx;

public:
    BankAccount() {
        balance = 0;
        abierta = false;
    }

    void open() {
        mtx.lock();
        abierta = true;
        balance = 0;
        mtx.unlock();
    }

    void close() {
        mtx.lock();
        abierta = false;
        mtx.unlock();
    }

    void deposit(int amount) {
        mtx.lock();

        if (abierta) {
            balance = balance + amount;
        } else {
            cout << "Cuenta cerrada\n";
        }

        mtx.unlock();
    }

    void withdraw(int amount) {
        mtx.lock();

        if (abierta && balance >= amount) {
            balance = balance - amount;
        } else {
            cout << "Operacion invalida\n";
        }

        mtx.unlock();
    }

    int getBalance() {
        mtx.lock();

        int temp;
        if (abierta) {
            temp = balance;
        } else {
            temp = 0;
        }

        mtx.unlock();
        return temp;
    }
};

int main() {
    BankAccount cuenta;

    cuenta.open();
    cuenta.deposit(100);
    cuenta.withdraw(30);

    cout << "Saldo: " << cuenta.getBalance() << endl;

    cuenta.close();
    cuenta.deposit(50);

    return 0;
}