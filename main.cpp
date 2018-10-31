#include <iostream>

using namespace std;

class AbstractClass {
    public:
    void storeItem() {
        name();
        category();
        storeId();
        itemNote();
    }
    virtual void name() = 0;
    virtual void category() = 0;
    void storeId() {
        cout << "Store Location : 555" << endl;
    }
    virtual void itemNote() {}
};

class ConcreteClassA : public AbstractClass {
    public:
    void name() {
        cout << "Milk" << endl;
    }
    void category() {
        cout << "Dairy" << endl;
    }
};

class ConcreteClassB : public AbstractClass {
    public:
    void name() {
        cout << "Celery" << endl;
    }
    void category() {
        cout << "Produce" << endl;
    }
    void itemNote() {
        cout << "Sub category: vegtable" << endl;
    }
}

int main() {
    ConcreteClassA ca;
    ConcreteClassB cb;
    ca.storeItem();
    cb.storeItem();
    return 0;
}