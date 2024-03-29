//
// Created by tigerrrr on 2/11/2022.
//

#include <iostream>
#include <vector>
#include <string>
#include "../Headers/Orders.h"
#include <vector>

using namespace std;

class Territory;
class Player;

/**
 * Order class Implementation
 *
 */

// constructor implementation
Order::Order() = default;

// copy constructor implementation
Order::Order(const Order &order) {
    this->territory = order.territory;
    this->startTerritory = order.startTerritory;
    this->targetTerritory = order.targetTerritory;
    this->player = order.player;
    this->targetPlayer = order.targetPlayer;
    this->nrArmies = order.nrArmies;
    this->nrArmiesToAttack = order.nrArmiesToAttack;
    this->nrArmiesToDefend = order.nrArmiesToDefend;
}

//destructor implementation
Order::~Order() = default;

// assignment operator
Order &Order::operator=(const Order &order) {
    if (this != &order) {
        return *this;
    }
    return *this;
}

//stream insertion operator implementation
ostream &operator<<(ostream &os, const Order &order) {
    order.print(os);
    return os;
}

bool Order::validate() {
    return true;

}

void Order::print(ostream &os) const {
    cout << "Order" << endl;
}


/**
 * Orders List Class Implementation
 *
 */


// constructor implementation
OrdersList::OrdersList(const vector<Order *> &ordersList) : orders(ordersList) {
    this -> orders = ordersList;
}


// copy constructor implementation
OrdersList::OrdersList(const OrdersList &orderList) {
    this ->orders = orderList.orders;
}

//destructor implementation
OrdersList::~OrdersList() {
    this ->orders.clear();
}

// assignment operator
OrdersList& OrdersList::operator=(OrdersList *otherList) {

    this -> orders = otherList->orders;
    return *this;
}


//stream insertion operator implementation
ostream &operator<<(ostream &ostream, const OrdersList &ordersList) {
    ostream << "[\n";
    for (int i = 0; i < ordersList.orders.size(); ++i) {
        cout << *(ordersList.orders[i]);
    }
    ostream <<"]\n";
    return ostream;
}


// adds an order to the list
void OrdersList::add(Order* order) {
    orders.push_back(order);
}

//removes an order from the list
void OrdersList::remove(int index) {
    orders.erase(orders.begin() + index);
}

void OrdersList::move(int from, int to) {
    if (from < 0 || from > orders.size() || to < 0 || to > orders.size()) {
        throw std::invalid_argument("Provided indexes are out of vector range.");
    }
    iter_swap(orders.begin() + from, orders.begin() + to);
}




/**
* Deploy class implementation
*/

// constructor implementation
Deploy::Deploy(Player *player, Territory *targetTerritory, int nrArmies) {
    this -> player = player;
    this -> targetTerritory = targetTerritory;
    this -> nrArmies = nrArmies;
}

// copy constructor implementation
Deploy::Deploy(const Deploy& deploy)  : Order(deploy) {
    this -> player = deploy.player;
    this -> targetTerritory = deploy.targetTerritory;
    this -> nrArmies = deploy.nrArmies;
}

// destructor implementation
Deploy::~Deploy() = default;

// assignment operator implementation
Deploy& Deploy::operator=(const Deploy &deploy) {
    this -> player = deploy.player;
    this -> targetTerritory = deploy.targetTerritory;
    this -> nrArmies = deploy.nrArmies;

    return *this;
}

// stream insertion implementation
/*ostream& operator << (ostream &ostream, const Order &info) {
    info.print(ostream);
    return ostream;
    //return ostream << "Deploy " << deploy.nrArmies << " to " << deploy.targetTerritory << endl;
}*/
void Deploy::print(std::ostream &os) const {
    cout << "Deploy " << this->nrArmies << " to " << this->targetTerritory << endl;
}

bool Deploy::validate() {
    bool isValid;
    isValid = true;
    return isValid;
}

void Deploy::execute() {
    bool validOrder = this->validate();
    if(validOrder) {
        cout << "Troops have been deployed" << endl;
    }
}


/**
 * Class to handle advance order
 */


// constructor implementation
Advance::Advance(Player *player, Territory *startTerritory, Territory *targetTerritory, int nrArmies) {
    this->player = player;
    this->startTerritory = startTerritory;
    this->targetTerritory = targetTerritory;
    this->nrArmies = nrArmies;
}

// copy constructor implementation
Advance::Advance(const Advance &advance) : Order(advance){
    this->player = advance.player;
    this->startTerritory = advance.startTerritory;
    this->targetTerritory = advance.targetTerritory;
    this->nrArmies = advance.nrArmies;

}

// assignment operator implementation
Advance& Advance::operator=(const Advance &advance){
    this->player = advance.player;
    this->startTerritory = advance.startTerritory;
    this->targetTerritory = advance.targetTerritory;
    this->nrArmies = advance.nrArmies;

    return *this;
}

/*ostream &operator<<(ostream &ostream, const Advance &advance) {
    return <#initializer#>;
}*/

// method to validate an order
bool Advance::validate() {
    bool isValid;
    isValid = true;
    return isValid;
}

// method to execute an order
void Advance  :: execute() {
    bool orderValid = this->validate();
    if (orderValid) {
        cout << "Advance order executed" << endl;
    }
}

void Advance::print(ostream &os) const {
    cout << "Advance " << this->nrArmies << " to " << this->targetTerritory << endl;
}



/**
 * Class to implement Bomb
 */

// constructor implementation
Bomb::Bomb(Player* player, Territory* targetTerritory){
    this->player = player;
    this->targetTerritory=targetTerritory;
}

//copy constructor implementation
Bomb::Bomb(const Bomb &bomb) : Order(bomb){
    this->player=bomb.player;
    this->targetTerritory=bomb.targetTerritory;
}

//assignment operator implementation
Bomb& Bomb::operator=(const Bomb &bomb){
    this->player=bomb.player;
    this->targetTerritory = bomb.targetTerritory;

    return *this;
}


// method to validate an order
bool Bomb  :: validate() {
    bool isValid;
    isValid = true;
    return isValid;
}

// method to execute an order
void Bomb  :: execute() {
    bool orderValid = this->validate();
    if (orderValid) {
        cout << "Bomb order executed" << endl;
    }
}

void Bomb::print(ostream &os) const {
    cout << "Bomb " << this->targetTerritory << endl;
}


/**
 * Class to hande Blockade
 */

//constructor implementation
Blockade::Blockade(Player* player, Territory* territory){
    this->player = player;
    this->territory = territory;
}

//copy constructor implementation
Blockade::Blockade(const Blockade &blockade) : Order(blockade){
    this->player = blockade.player;
    this->territory = blockade.territory;
}

//assignment operator implementation
Blockade& Blockade::operator=(const Blockade &blockade){
    this->player = blockade.player;
    this->territory=blockade.territory;

    return *this;
}

//stream insertion operator for Blockade implementation
void Blockade::print(ostream &os) const {
    cout << "Blockade " << this->targetTerritory << endl;
}

// method to valida an order
bool Blockade  :: validate() {
    bool isValid;
    isValid = true;
    return isValid;
}

// method to execute an order
void Blockade  :: execute() {
    bool orderValid = this->validate();
    if (orderValid) {
        cout << "Blockade order executed" << endl;
    }
}



/**
 * Class to handle Airlift
 */

// constructor implementation
Airlift::Airlift(Player *player, Territory *startTerritory, Territory *targetTerritory, int nrArmies) {
    this->player = player;
    this->startTerritory = startTerritory;
    this->targetTerritory = targetTerritory;
    this->nrArmies = nrArmies;

}

// copy constructor implementation
Airlift::Airlift(const Airlift &airlift) : Order(airlift){
    this->player= airlift.player;
    this->startTerritory = airlift.startTerritory;
    this->targetTerritory = airlift.targetTerritory;
    this->nrArmies = airlift.nrArmies;
}

// assignment operator implementation
Airlift& Airlift::operator=(const Airlift &airlift){
    this->player = airlift.player;
    this->startTerritory = airlift.startTerritory;
    this->targetTerritory = airlift.targetTerritory;
    this->nrArmies = airlift.nrArmies;

    return *this;
}

void Airlift::print(ostream &os) const {
    cout << "Airlift " << this->nrArmies <<" armies" << " from " << this->startTerritory << " to " << this->targetTerritory << endl;
}


// method to valida an order
bool Airlift  :: validate() {
    bool isValid;
    isValid = true;
    return isValid;
}

// method to execute an order
void Airlift  :: execute() {
    bool orderValid = this->validate();
    if (orderValid) {
        cout << "Airlift order executed" << endl;
    }
}



/**
 * Class to handle Negotiate
 */

// constructor implementation
Negotiate::Negotiate(Player* player, Player* targetPlayer){
    this->player = player;
    this->targetPlayer = targetPlayer;
}

// copy constructor implementation
Negotiate::Negotiate(const Negotiate &negotiate) : Order(negotiate){
    this->player = negotiate.player;
    this->targetPlayer = negotiate.targetPlayer;
}

// assignment operator implementation
Negotiate& Negotiate::operator=(const Negotiate &negotiate){
    this->player = negotiate.player;
    this->targetPlayer = negotiate.targetPlayer;

    return *this;
}

// stream assignment operator implementation
void Negotiate::print(ostream &os) const {
    cout << "Negotiate with " << this->targetPlayer << endl;
}

// method to validate an order
bool Negotiate  :: validate() {
    bool isValid;
    isValid = true;
    return isValid;
}

// method to execute an order
void Negotiate  :: execute() {
    bool orderValid = this->validate();
    if (orderValid) {
        cout << "Negotiate order executed" << endl;
    }
}

