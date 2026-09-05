#include <bits/stdc++.h>

using namespace std;

class Lion {

    public:
        // Lion() {}
        virtual void roar() = 0;

};

class AsianLion : public Lion {

    public: 
        // AsianLion() {}
        void roar() {
            cout << "Asian Lion" << endl;
        }

};

class AfricanLion : public Lion {

    public: 
        // AfricanLion() {}

        void roar() {
            cout << "African Lion" << endl;
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
            cout << "wild dog bark" << endl;
        }

};


class LionDogAdapter : public Lion {

    public: 
        LionDogAdapter(Dog *dog) {
            this->dog = dog;
        }

        void roar() {
            this->dog->bark();
        }


    private: 
        Dog *dog;

};


int main() {

    Hunter *hunter = new Hunter();
    Lion *asianLion = new AsianLion();
    hunter->hunt(asianLion);

    LionDogAdapter *lionDogAdapter = new LionDogAdapter(new WildDog());
    hunter->hunt(lionDogAdapter);

    return 0;
}