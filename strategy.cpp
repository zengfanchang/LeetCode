#include <iostream>
#include <string>

using namespace std;

class FlyBehavior {
    public:
        virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
    public:
        void fly() {
            cout << "I'm flying!!" << endl;
        }
};

class FlyNoWay : public FlyBehavior {
    public:
        void fly() {
            cout << "I can't fly" << endl;
        }
};

class QuackBehavior {
    public:
        virtual void quack() = 0;
};

class Quack : public QuackBehavior {
    public:
        void quack() {
            cout << "Quack" << endl;
        }
};

class MuteQuack : public QuackBehavior {
    public:
        void quack() {
            cout << "<< Silence >>" << endl;
        }
};


class Duck {
    protected:
        FlyBehavior *flyBehavior;
        QuackBehavior *quackBehavior;
    public:
        virtual void quack() = 0;
        virtual void fly() = 0;
};

class MallardDuck : public Duck {
    public:
        MallardDuck() {
            quackBehavior = new Quack();
            flyBehavior = new FlyWithWings();
        }
        void quack() {
            quackBehavior->quack();
        }
        void fly() {
            flyBehavior->fly();
        }
};

int main() {
    int i;
    if (i = 0) {
        cout << "i = 0" << endl;
    } else {
        cout << "i != 0" << endl;
    }
    return 0;
}
