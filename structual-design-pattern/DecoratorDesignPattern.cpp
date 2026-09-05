#include <bits/stdc++.h>

using namespace std;

class Coffee {
    public: 
        Coffee() {}
        virtual int getCost() = 0;
        virtual string getContent() = 0;
};

class SimpleCoffee : public Coffee {
    
    public: 
    
    int getCost() {
        return 10;
    }

    string getContent() {
        return "coffee";
    }


    private: 
        Coffee *coffee;
};

class MilkCoffee : public Coffee {
    public: 
        MilkCoffee(Coffee *coffee) {
            this->coffee = coffee;
        } 
    
        int getCost() {
            return this->coffee->getCost() + 2;
        }

        string getContent() {
            return this->coffee->getContent() + ", milk";
        }

    private: 
        Coffee *coffee;

};

class WhipCoffee : public Coffee {
    public: 
        WhipCoffee(Coffee *coffee) {
            this->coffee = coffee;
        } 
    
        int getCost() {
            return this->coffee->getCost() + 3;
        }

        string getContent() {
            return this->coffee->getContent() + ", whip";
        }

    private: 
        Coffee *coffee;

};


int main() {

    Coffee *coffee = new SimpleCoffee();
    Coffee *milkCoffee = new MilkCoffee(coffee);
    Coffee *whipCreamCoffee = new WhipCoffee(milkCoffee); 
    cout << milkCoffee->getContent() << ", " << milkCoffee->getCost() << endl;
    cout << whipCreamCoffee->getContent() << ", " << whipCreamCoffee->getCost() << endl;

    return 0;
}