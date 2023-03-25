#include "names.h"
//Written by Daniel Rider, Zanderz McCluer, and Jacob Rand

//constructor for transaction 
Transaction::Transaction () {
    int val = rand() % 2;   //type of transaction randomly generated
    if(val == 1) {
        type = "Deposit";
    }
    else {
        type = "Withdrawal";
    }
    amt = rand() % 100000; //deposits and withdrawals over 100000 require consultation
}
string Transaction::getType() {  
    return type;
}
double Transaction::getAmount() { 
    return amt;
}

//constructor for the customer
Customer::Customer (string newName) {
    name = newName;
    balance = rand() % 1000000;   //this clerk only deals with customers with less than 1 million at the time of service
    Transaction newTransaction;  //generates new instance of transaction to be used by the transaction field
    transaction = newTransaction;

}
string Customer::getName() {
    return name;
}
double Customer::getBalance() {
    return balance;
}

// changes customer balance
void Customer::changeBalance () {
    int sign = 1;
    if(transaction.getType() == "Deposit") {
        sign = 1;
    }
    else {
        sign = -1;
    }
    balance += sign * transaction.getAmount();  //sign changes negative if its a withdrawal therefore reducing customer balance
} 

int main()
{
    srand(time(NULL));

    int n;

    
    cout << "How many customers <<<< ";
    cin >> n;
    
    stack<Customer> bankStack;
    int j=0;
    for (int i=0; i<n; i++) {
        j = rand() % 99;                       //pulls a random name from the list
        Customer newCustomer(custNames[j]);         //create new customer, push onto stack
        bankStack.push(newCustomer);
    }
    int custServed= 0;
    while(!bankStack.empty()) {
        if(custServed % 5 == 0 && custServed != 0){
            cout << "The stack is now " << bankStack.size() << " customers tall. Now serving " << bankStack.top().getName() << "." << endl;     //prints message after 5 customers served
        }
        bankStack.top().changeBalance();    //changes balance and then removes customer from stack
        bankStack.pop();
        custServed++;

    }

    return 0; 
}
