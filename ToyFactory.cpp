/*
Factory is a design pattern in common usage. Please implement a ToyFactory which can generate proper toy based on the given type.

Have you met this question in a real interview? Yes
Example
ToyFactory tf = ToyFactory();
Toy toy = tf.getToy('Dog');
toy.talk(); 
>> Wow

toy = tf.getToy('Cat');
toy.talk();
>> Meow

Related Problems 
Easy Shape Factory
*/

/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    // Write your code here
public:
    Dog () {}
    virtual void talk () const {
        cout<<"Wow"<<endl;
    }
};

class Cat: public Toy {
    // Write your code here
public:
    Cat() {}
    virtual void talk () const {
        cout<<"Meow"<<endl;
    }
};

class ToyFactory {
    Toy *t;
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    ToyFactory() {
        t = NULL;
    }
    
    Toy* getToy(string& type) {
        // Write your code here
        if (type == "Dog") {
            t = new Dog();
        } else if (type == "Cat") {
            t = new Cat();
        }
        return t;
    }
};
