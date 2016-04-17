/*
Factory is design pattern in common usage. Implement a ShapeFactory that can generate correct shape.

Example,
ShapeFactory sf = new ShapeFactory();
Shape shape = sf.getShape("Square");
shape.draw();
>>  ----
>> |    |
>> |    |
>>  ----

shape = sf.getShape("Triangle");
shape.draw();
>>   /\
>>  /  \
>> /____\

shape = sf.getShape("Rectangle");
shape.draw();
>>  ----
>> |    |
>>  ----

Tags 
OO Design
Related Problems 
Easy Toy Factory
*/

/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
class Shape {
public:
    virtual void draw() const=0;
};

class Rectangle: public Shape {
    // Write your code here
    virtual void draw() const {
        cout<<" ---- "<<endl;
        cout<<"|    |"<<endl;
        cout<<" ---- "<<endl;
    };
};

class Square: public Shape {
    // Write your code here
    virtual void draw() const {
        cout<<" ---- "<<endl;
        cout<<"|    |"<<endl;
        cout<<"|    |"<<endl;
        cout<<" ---- "<<endl;
    };
};

class Triangle: public Shape {
    // Write your code here
    virtual void draw() const {
        cout<<"  /\\  "<<endl;
        cout<<" /  \\ "<<endl;
        cout<<"/____\\"<<endl;
    };
};

class ShapeFactory {
private:
    Shape* s;
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    ShapeFactory () {
        s = NULL;
    }
    Shape* getShape(string& shapeType) {
        // Write your code here
        if (shapeType == "Square") {
            s = new Square();
        } else if (shapeType == "Triangle") {
            s = new Triangle();
        } else if (shapeType == "Rectangle") {
            s = new Rectangle();
        }
        return s;
    }
};

