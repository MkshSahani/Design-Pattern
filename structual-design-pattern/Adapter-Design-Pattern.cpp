// Adapter Design Pattern.
#include <bits/stdc++.h>

using namespace std;

class Lion {

    public: 
        virtual void roar() = 0;

};

class AfricanLion : public Lion {

    public: 
        void roar() {
            cout << "african lion roar" << endl;
        }

};

class AsianLion : public Lion {
    public: 
        void roar() {
            cout << "Asian lion roar" << endl;
        }
};

class Hunter {

    public: 
        void hunt(Lion *lion) {
            lion->roar();
        }

};

class Dog {

    public: 
        virtual void bark() = 0;

};

class WildDog : public Dog {
    public: 
        void bark() {
            cout << "dog bark..." << endl;
        }
};


class DogLionAdapter : public Lion {

    private: 
        Dog *dog;

    public: 

        DogLionAdapter(Dog *dog) {
            this->dog = dog;
        }

        void roar() {
            this->dog->bark();
        }

};


int main() {

    Hunter *hunter = new Hunter();
    Dog *dog = new WildDog();
    DogLionAdapter *doglionadapter = new DogLionAdapter(dog); 
    Lion *africanLion = new AfricanLion();
    hunter->hunt(africanLion);
    hunter->hunt(doglionadapter);
}