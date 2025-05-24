#include<iostream>
using namespace std;



class Burger{

    public:
    virtual void prepare() = 0;  // pure virtual function
    virtual ~Burger() {}  // virtual destructor

};


class BasicBurger : public Burger{
    public:
    void prepare () override {
        cout << "Prparing basic burger: " << endl;
    }
};


class StandardBurger : public Burger{
    public:
    void prepare () override {
        cout << "preparing standar burger: " << endl;
    }

};


class PremiumBurger :  public Burger{
    public:
    void prepare () override {
        cout << "preparing premium burger: " << endl;
    }

};


class BurgerFactory{
    public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        } else if (type == "standard")
        {
            return new StandardBurger();
        } else if (type == "premium")
        {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type" << endl;
            return nullptr;     
        }
        


    }
};






int main(){

    string type = "premium";
    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger* burger = myBurgerFactory->createBurger(type);

    burger->prepare();



    return 0;
}