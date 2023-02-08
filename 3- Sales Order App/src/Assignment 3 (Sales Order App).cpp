// Assignment 3 (Sales Order App).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#include <fstream>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

#include "Stock.h"
#include "Customers.h"
#include "Transaction.h"
#include "Credit.h"
#include "Cash.h"
#include "Check.h"

constexpr auto space = "\t\t";
constexpr auto invalid = "Invalid Input..\n";

Stock stock;
Customers customers;
vector <Transaction> TransactionList;
int countTransactions = 0;
vector <Product> Products; // abstract prodcuts
int countProducts = 0;
// utility function: 
bool compareNames(string n1, string n2)
{
    transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
    transform(n2.begin(), n2.end(), n2.begin(), ::tolower);

    return (n1 == n2);
}
// showing options functions:
void Header()
{
    cout << space << "~~Sales Manager App~~\n";
          cout << space << "-..-..-..-..-..-..-..-..-\n\n";
}

void mainMenu()
{
    cout << "Choose from the menu: \n";
         cout << space << "1- Data Entry & Processing\n";
         cout << space << "2- Sales Process\n";
         cout << space << "3- Print\n";
         cout << space << "4- Exit and Save Data\n";
}

void dataEntryMenu()
{
    cout << "Choose from the menu: \n";
    cout << space << "1- Add Customer\n";
    cout << space << "2- Update Customer\n";
    cout << space << "3- Delete Customer\n\n";
    cout << space << "4- Add a Product\n";
    cout << space << "5- Edit a Product\n";
    cout << space << "6- Delete a Product\n\n";
    cout << space << "7- Add Product to the Stock\n";
    cout << space << "8- Update Product in the Stock\n";
    cout << space << "9- Delete Product from the Stock\n";
}

void salesProcessMenu()
{
    cout << "Choose from the menu: \n";
    cout << space << "1- Add Transaction\n";
    cout << space << "2- Update Order\n";
    cout << space << "3- Pay Order\n";
}

void printMenu()
{
    cout << "Choose to print: \n";
    cout << space << "1- Customers\n";
    cout << space << "2- Stock Data\n";
    cout << space << "3- Transactions\n";
    cout << space << "4- Products\n";
}

void statusMenu()
{
    cout << "Choose the status: \n";
    cout << space << "1- NEW\n";
    cout << space << "2- HOLD\n";
    cout << space << "3- PAID\n";
    cout << space << "4- CANCELLED\n";
}

char getChoice()
{
    string choice;
    cin >> choice;
    
    char c;
    if (choice.size() > 1)
    {
        c = '*';
    }
    else c = choice[0];

    return c;
}

// printing functions:
void printTransactions()
{
    cout << "\n\t~~Your Transactions List~~\n" << "\t--------------------------\n";
    for (Transaction& t : TransactionList)
        cout << t << "\t--------------------------\n";
    cout << endl;
}

void printAllProducts()
{
    if (Products.size() > 0)
    {
        cout << "\tAll Products: \n";
        int i = 1;
        for (Product& p : Products)
            cout << i++ << "- " << p;
        cout << endl;
    }
    else cout << "No products found :)\n";
}


// sales process functions:
void addAbstractProduct()
{
    Product tempP(countProducts);
    cin >> tempP;

    bool found = 0;
    for (Product& p : Products)
    {
        if (compareNames(p.getName(), tempP.getName()))
        {
            found = 1;
            break;
        }
    }

    if (!found) {
        Products.push_back(tempP);
        countProducts++;
        cout << "ADDED~\n";
    }
    else cout << "\n this product is already exist..\n";
}

void editProduct(int _id)
{
    if (_id < 0 || _id >= countProducts) cout << invalid;
    else {
        Products[_id].update();
        cout << "UPDATED~\n";
    }
}

void deleteProduct(int _id)
{
    if (_id < 0 || _id >= countProducts) cout << invalid;
    else {
        swap(Products[_id], Products.back());
        Products.pop_back();
        countProducts--;
        
        cout << "DELETED~\n";
    }
}

void addTransaction()
{
    customers.printAllCustomers();
    cout << "Enter the Customer ID: ";
    int _id;  cin >> _id;
    if (_id < 0 || _id >= customers.getCustomersNum()) // invalid id
    {
        cout << "Invalid ID..\n";
        return;
    }

    Order tempO(customers.getCustomerPtr(_id));
    tempO.addItems(stock);

    statusMenu();
    int status;  cin >> status;
    tempO.setStatus(status);

    if (tempO.getTotal() == 0)
    {
        cout << "Garbage Transaction.. no items added :(\n";
        return;
    }
    
    TransactionList.push_back(Transaction(countTransactions, tempO));
    cout << "ADDED~\n";
    countTransactions++;
}

void updateOrder()
{
    printTransactions();
    cout << "\nEnter the ID of the transaction to update: ";
    int _id;  cin >> _id;
    if (_id < 0 || _id >= countTransactions) // invalid
    {
        cout << "Invalid ID..\n";
        return;
    }

    cout << "Choose to update: \n";
    cout << space << "1- Quantity\n";
    cout << space << "2- Status\n";

    int choice;  cin >> choice;
    switch (choice)
    {
    case 1: 
        TransactionList[_id].updateOrderQuantities(stock);
        break;
    case 2:
        statusMenu();
        short int new_status;
        cin >> new_status;
        TransactionList[_id].updateOrderStatus(new_status);
        break;
    default: invalid;
    }
    
}

void payOrder()
{
    printTransactions();
    cout << "Enter the ID of the transaction to pay for: ";
    int _id;  cin >> _id;
    if (_id < 0 || _id >= countTransactions) // invalid
    {
        cout << "Invalid ID..\n";
        return;
    }

    cout << "Enter the amount to pay: ";
    double _amount; cin >> _amount;
    if (_amount < 0)
    {
        cout << invalid;
            return;
    }
    else if (_amount > TransactionList[_id].getOrderTotal())
        _amount = TransactionList[_id].getOrderTotal();

    cout << "Choose the paying method: \n";
    cout << space << "1- Credit\n";
    cout << space << "2- Cash\n";
    cout << space << "3- Check\n";

    int choice;  cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Credit cr(_amount);
        TransactionList[_id].payOrder(cr);
        break;
    }
    case 2: 
    {
        Cash ca(_amount);
        TransactionList[_id].payOrder(ca);
        break;
    }
    case 3:
    {
        Check ch(_amount);
        TransactionList[_id].payOrder(ch);
        break;
    }
    default: cout << invalid;
    }
}

// saving to file functions:
void saveStockFile()
{
    ofstream fout("Stock.txt");

    fout << stock;

    fout.close();
}

void saveProductsFile()
{
    ofstream fout("Products.txt");

    fout << "\tProudct List\n\n";
    int i = 1;
    for (Product& p : Products)
        fout << i++ << "- " << p;

    fout.close();
}

void saveTransactionsFile()
{
    ofstream fout("Transactions.txt");
    if (TransactionList.empty())
    {
        fout << "Sorry.. you have no transactions .-.\n"; 
        return;
    }

    int i = 1;
    fout << "\tTransaction List\n\n";
    for (Transaction& t : TransactionList)
        fout << "\t(" << i++ << ")\n" << t;

    fout.close();
}

int main()
{
    system("Color 02");
    bool exit = 0;
    char ch;
    int _id;

    while (!exit)
    {
        system("cls");

        Header();
        mainMenu();

        ch = getChoice();
        switch (ch)
        {
        case '1':
            dataEntryMenu();
            ch = getChoice();
            switch (ch)
            {
            case '1':
                customers.addCustomer();
                break;
            case '2':
                customers.editCustomer();
                break;
            case '3':
                customers.deleteCustomer();
                break;
            case '4':
                addAbstractProduct();
                break;
            case '5': 
                printAllProducts();
                cout << "Enter the id of the product: ";
                cin >> _id;
                editProduct(_id);
                break;
            case '6': 
                printAllProducts();
                cout << "Enter the id of the product: ";
                cin >> _id;
                deleteProduct(_id);
                break;
            case '7':
                stock.addProduct(Products);
                break;
            case '8':
                /// here i get the id in the main and check it in the main before passing it 
                // to the function
                cout << stock;
                cout << "Enter the id of the Product to update the quantity: ";
                cin >> _id;
                if (_id < 0 || _id >= stock.getProductsCount())
                {
                    cout << invalid;
                }
                else
                {
                    cout << "Enter the new quantity: ";
                    int new_quant;  cin >> new_quant;
                    stock.setQuant(_id, new_quant);
                    cout << "UPDATED~\n";
                }
                break;
            case '9':
                cout << stock;
                cout << "Enter the id of the Product to delete: ";
                cin >> _id;
                stock.deleteProduct(_id);
                break;
            default: cout << invalid;
            }
            break;
        case '2':
            salesProcessMenu();
            ch = getChoice();
            switch (ch)
            {
            case '1':
                addTransaction();
                break;
            case '2':
                updateOrder();
                break;
            case '3':
                payOrder();
                break;
            default: cout << invalid;
            }
            break;
        case '3':
            printMenu();
            ch = getChoice();
            switch (ch)
            {
            case '1': 
                customers.printAllCustomers();
                break;
            case '2':
                cout << stock;
                break;
            case '3':
                printTransactions();
                break;
            case '4':
                printAllProducts();
                break;
            default: cout << invalid;
            }
            break;
        case '4':
            exit = 1;
            customers.saveCustomersFile(); // save customers file
            saveStockFile(); // save stock data
            saveProductsFile(); // save products
            saveTransactionsFile(); // save transactions
            break;
        default: cout << invalid;
        }

        if (!exit)
        {
            cout << "\nPress enter to continue..";
            while (!_kbhit()) Sleep(1);
        }

    }
    cout << "See You Soon :)\n";
    Sleep(2000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
