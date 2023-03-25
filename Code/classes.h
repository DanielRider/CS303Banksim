#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Transaction {
    string type;
	double amt;
public:
    Transaction();
    string getType();
    double getAmount();
};


class Customer {

    string name;
	double balance;
    Transaction transaction; 

public: 
    Customer(string);
    string getName();
    double getBalance();
    void changeBalance();
};


#endif