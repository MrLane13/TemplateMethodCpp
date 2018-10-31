#include <iostream>

using namespace std;

class AbstractClass {
    public:
    // The template. It is exposed as an invokable method to the concrete classes
    void TemplateMethod() {
        primitiveOperation1();
        primitiveOperation2();
        invariantOperation();
        hookedOperation();
    }
    // Primitives are instantiated at compile time and must be implemented by the subclasses (ConcreteClassA/B)
    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;
    // Invariants are defined and will not be implemented by the subclasses (ConcreteClassA/B)
    void invariantOperation() {
        cout << "Store Location : 555" << endl;
    }
    // Hooks are left uninstantiated. It is left up to the subclasses (ConcreteClassA/B) to implement hooks or not
    virtual void hookedOperation() {}
};

class ConcreteClassA : public AbstractClass {
    public:
    void primitiveOperation1() {
        cout << "PO1 A" << endl;
    }
    void primitiveOperation2() {
        cout << "PO2 A" << endl;
    }
    // Note no definition for the hoookedOperation here. It is not required.
};

class ConcreteClassB : public AbstractClass {
    public:
    void primitiveOperation1() {
        cout << "PO1 B" << endl;
    }
    void primitiveOperation2() {
        cout << "PO2 B" << endl;
    }
    // Does not need to be defined in a subclass, but we choose to do so here
    void hookedOperation() {
        cout << "Hook! B" << endl;
    }
}

int main() {
    // Create instances of the concrete classes
    ConcreteClassA ca;
    ConcreteClassB cb;
    // Invoke the template method on both concrete classes
    ca.TemplateMethod();
    cb.TemplateMethod();
    return 0;
}