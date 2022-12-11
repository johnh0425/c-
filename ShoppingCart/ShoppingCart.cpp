#include "ShoppingCart.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

ShoppingCart::ShoppingCart() {      // default constructor
    _customerName = "none";
    _currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string cName, string cDate) {
    _customerName = cName;
    _currentDate = cDate;
}
string ShoppingCart::customerName() const {     // returns customer's name
    return _customerName;
}
string ShoppingCart::date() const {     // returns date
    return _currentDate;
}
void ShoppingCart::addItem(ItemToPurchase itemToPurchase) {         // adds item to shopping cart
    _cartItems.push_back(itemToPurchase);
}

void ShoppingCart::removeItem(string itemName) {        // removes item from shopping cart
    unsigned int count = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        if (_cartItems.at(i).name() == itemName) {
            _cartItems.erase(_cartItems.begin()+i);
            break;
        }
        else {
            count++;
        }
    }
    if (count == _cartItems.size()) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::modifyItem(ItemToPurchase itemToPurchase) {      // modifies the item in shopping cart
    unsigned int count = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        if (_cartItems.at(i).name() == itemToPurchase.name()) {
            if (itemToPurchase.description() != "none") {
                _cartItems.at(i).setDescription(itemToPurchase.description());
            }
            if (itemToPurchase.price() != 0) {
                _cartItems.at(i).setPrice(itemToPurchase.price());
            }
            if (itemToPurchase.quantity() != 0) {
                _cartItems.at(i).setQuantity(itemToPurchase.quantity());
            }
            break;
        }
        else {
            count++;
        }
    }
    if (count == _cartItems.size()) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::numItemsInCart() {        // returns number of items in shopping cart
    int sumQuantity = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        sumQuantity = sumQuantity + _cartItems.at(i).quantity();
    }
    return sumQuantity;
}

int ShoppingCart::costOfCart() {        // returns the total cost of shopping cart
    int sumCost = 0;
    int itemTotal = 0;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        itemTotal = _cartItems.at(i).price() * _cartItems.at(i).quantity();
        sumCost = sumCost + itemTotal;
    }
    return sumCost;
}

void ShoppingCart::printTotal() {       // prints out the total cost of cart
    cout << customerName() << "'s Shopping Cart - " << date() << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    if (numItemsInCart() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
        cout << endl;
        cout << "Total: $0" << endl;
    }
    else {
        for (unsigned int i = 0; i < _cartItems.size(); ++i) {
            _cartItems.at(i).printItemCost();
            cout << endl;
        }
        cout << endl;
        cout << "Total: $" << costOfCart() << endl;
    }

}

void ShoppingCart::printDescriptions() {        // prints out description of item in cart
    cout << customerName() << "'s Shopping Cart - " << date() << endl;
    cout << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned int i = 0; i < _cartItems.size(); ++i) {
        _cartItems.at(i).printItemDescription();
        cout << endl;
    }
}
