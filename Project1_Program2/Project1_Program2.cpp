// Project1_Program2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
using namespace std;

// Function to calculate commission rate based on sales 
double calculateCommission(double sales) {
    if (sales < 10000) return 0.05;
    else if (sales < 15000) return 0.10;
    else if (sales < 18000) return 0.12;
    else if (sales < 22000) return 0.14;
    else return 0.16;

}

struct Salesperson {
    string name;
    double sales;
    double advance;
    double commission;
    double finalPay;
};

int main() {
    int numSalespeople = 2; // You can modify this to handle more people
    vector<Salesperson> salespeople(numSalespeople);

    // Input for each salesperson
    for (int i = 0; i < numSalespeople; i++) {
        cout << "Enter the name of salesperson" << i + 1 << ":";
        cin >> salespeople[i].name;
        cout << "Enter" << salespeople[i].name << "'s total sales:$";
        cin >> salespeople[i].sales;
        cout << "Enter" << salespeople[i].name << "'s advance taken:$";
        cin >> salespeople[i].advance;

        // Calculate commission and final pay
        double commissionRate = calculateCommission(salespeople[i].sales);
        salespeople[i].commission = salespeople[i].sales * commissionRate;
        salespeople[i].finalPay = salespeople[i].commission - salespeople[i].advance;
    }

    // Output the results
    cout << "\nSalesperon Summary:\n";
    for (int i = 0; i < numSalespeople; i++) {
        cout << "\n" << salespeople[i].name;
        cout << "\nSales:$" << salespeople[i].name;
        cout << "\nCommission: $" << salespeople[i].commission;
        if (salespeople[i].finalPay >= 0) {
            cout << "\nFinal Pay after advance:$" << salespeople[i].finalPay << endl;
        }
        else {
            cout << "\nReimbursement needed:$" << -salespeople[i].finalPay << endl;
        }
    }

    return 0;

}
