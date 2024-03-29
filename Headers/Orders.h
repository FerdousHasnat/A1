//
// Created by tigerrrr on 2/11/2022.
//

#ifndef COMP345_ORDERS_H
#define COMP345_ORDERS_H

#include <iostream>
#include <vector>
#include <string>
#include "Map.h"
#include "Player.h"

using namespace std;

class Territory;
class Player;

/**
 * Class declaration Orders
 */
class Order{
public:
    // default constructor
    Order();

    //copy constructor
    Order(const Order &order);

    //destructor
    ~Order();

    //assignment operator
    Order& operator=(const Order &order);

    //stream insertion operator for Orders
    friend ostream& operator << (ostream &os, const Order &order);

    //validate methods to be inherited by the Orders subclasses
    bool validate();

    //execute methods to be inherited by the Orders subclasses
    void execute();

    // stream assignment operator
    virtual void print(std::ostream& os) const;


    Territory* territory{};
    Territory* startTerritory{};
    Territory* targetTerritory{};
    Player* player{};
    Player* targetPlayer{};
    vector<Territory*> territories;
    int nrArmies{};
    int nrArmiesToAttack{};
    int nrArmiesToDefend{};
};

/**
 * Class declaration Orders List
 */
class OrdersList {
public:
    vector<Order*> orders;

public:

    //default constructor
    OrdersList() = default;

    //constructor
    OrdersList(const vector<Order *> &orders);

    //copy constructor
    OrdersList(const OrdersList &orderList);

    //destructor
    ~OrdersList();

    // assignment operator
    OrdersList& operator = (OrdersList *orderList);

    // stream insertion operator
    friend ostream& operator << (ostream &ostream, const OrdersList &orderList);

    void add(Order* order);
    void remove(int index);
    void move(int from, int to);

};

/**
 * Class declaration Deploy
 */
class Deploy : public Order {
public:

    //default constructor
    Deploy() = default;

    // constructor
    Deploy(Player* player, Territory* targetTerritory, int nrArmies);

    //copy constructor
    Deploy(const Deploy &deploy);

    // destructor
    ~Deploy();

    // assignment operator
    Deploy& operator = (const Deploy &deploy);

    //stream insertion operator
    friend ostream& operator << (ostream &ostream, const Order &order);

    bool validate();
    void execute() ;
    void print(std::ostream& os) const override;

};

/**
 * Class declaration Orders
 */
class Advance : public Order {
public:
    // default constructor
    Advance() = default;
    // constructor
    Advance(Player* player, Territory* startTerritory, Territory* targetTerritory, int nrArmies);

    //copy constructor
    Advance(const Advance &advance);

    // destructor
    ~Advance() = default;

    // assignment operator
    Advance& operator = (const Advance &advance);

    //stream insertion operator
    //friend ostream& operator << (ostream &ostream, const Advance &advance);

    bool validate();
    void execute();
    void print(std::ostream& os) const override;

};

/**
 * Class declaration  Bomb
 */
class Bomb : public Order {
public:
    // default constructor
    Bomb() = default;

    // constructor
    Bomb(Player* player, Territory* target);

    //copy constructor
    Bomb(const Bomb &bomb);

    // destructor
    ~Bomb();

    // assignment operator
    Bomb& operator = (const Bomb &bomb);

    //stream insertion operator
    //friend ostream& operator << (ostream &ostream, const Bomb &bomb);

    bool validate();
    void execute();
    void print(std::ostream& os) const override;
};

/**
 * C;ass declaration Blockade
 */
class Blockade : public Order {
public:
    // default constructor
    Blockade() = default;

    // constructor
    Blockade(Player* player, Territory* target);

    //copy constructor
    Blockade(const Blockade &blockade);

    // destructor
    ~Blockade();

    // assignment operator
    Blockade& operator = (const Blockade &blockade);

    //stream insertion operator
    //friend ostream& operator << (ostream &ostream, const Blockade &blockade);

    bool validate();
    void execute();
    void print(std::ostream& os) const override;
};

/**
 * Class declaration Airlift
 */
class Airlift : public Order {
public:
    Airlift() = default;
    // constructor
    Airlift(Player* player, Territory* startTerritory, Territory *targetTerritory, int nrArmies);

    //copy constructor
    Airlift(const Airlift &airlift);

    // destructor
    ~Airlift();

    // assignment operator
    Airlift& operator = (const Airlift &airlift);

    //stream insertion operator
    //friend ostream& operator << (ostream &ostream, const Airlift &airlift);

    bool validate();
    void execute();
    void print(std::ostream& os) const override;
};

/**
 * Class declatation Negotiate
 */
class Negotiate : public Order {
public:
    //default constructor
    Negotiate() = default;

    // constructor implementation
    Negotiate(Player* player, Player* targetPlayer);

    //copy constructor
    Negotiate(const Negotiate &negotiate);

    // destructor
    ~Negotiate();

    // assignment operator
    Negotiate& operator = (const Negotiate &negotiate);

    //stream insertion operator
    //friend ostream& operator << (ostream &ostream, const Negotiate &negotiate);

    bool validate();
    void execute();
    void print(std::ostream& os) const override;
};


#endif //COMP345_ORDERS_H
