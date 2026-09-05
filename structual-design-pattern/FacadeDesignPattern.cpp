// FacadeDesignPattern.cpp
#include <bits/stdc++.h>

using namespace std;

class Computer {

    public: 
        
        void getElectricShock() {
            cout << "Ouch !!" << endl;
        }

        void makeSound() {
            cout << "beep beep !!" << endl;
        }

        void showLoadingScreen() {
            cout << "Loading..." << endl;
        }

        void bam() {
            cout << "Ready to used!!!" << endl;
        }

        void closeEveryting() {
            cout << "closing everyting !!" << endl;
        }

        void pullCurrent() {
            cout << "pulling current" << endl;
        }

        void turnOff() {
            cout << "turn off" << endl;
        }
};

class ComputerFacade {

    private: 
        Computer *computer; 

    public:
        ComputerFacade(Computer *computer) {
            this->computer = computer;
        } 

        void turnON() {
            this->computer->getElectricShock();
            this->computer->makeSound();
            this->computer->showLoadingScreen();
        }

        void turnOff() {
            this->computer->closeEveryting();
            this->computer->pullCurrent();
        }

};

int main() {

    Computer *computer = new Computer();
    ComputerFacade *computerFacade = new ComputerFacade(computer);
    computerFacade->turnON();
    computerFacade->turnOff();

    return 0;
}