#include <bits/stdc++.h>

using namespace std;

class KarakTea {

};

class TeaMaker {

    private: 
        unordered_map<string, KarakTea*> teaPreferencMap;

    public: 
        TeaMaker() {}
        KarakTea* make(string preference) {
            if(teaPreferencMap.count(preference) != 0) {
                teaPreferencMap[preference] = new KarakTea();
            }
            return teaPreferencMap[preference];
        }

};

class TeaShop {

    private: 
        unordered_map<string, KarakTea*> orders; 
        TeaMaker *teaMaker;

    public: 
        TeaShop() {
            this->teaMaker = new TeaMaker();
        }

        void takeOrder(string table, string preference) {
            orders[table] = this->teaMaker->make(preference);
        }

        void serve() {
            for(auto table : orders) {
                cout << "table :: " <<  table.first << endl;
            }
        }

};

int main() {

    TeaShop *teaShop = new TeaShop();
    teaShop->takeOrder("table-1", "karak");
    teaShop->takeOrder("table-2", "milk tea");
    teaShop->serve();

    return 0;
}