/*
Implement a Rectangle class which include the following attributes and methods:
Two public attributes width and height.
A constructor which expects two parameters width and height of type int.
A method getArea which would calculate the size of the rectangle and return.

Example
Rectangle rec = new Rectangle(3, 4);
rec.getArea(); // should get 12
*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    /*
     * Define two public attributes width and height of type int.
     */
    // write your code here
    int width;
    int height;
public:
    /*
     * Define a constructor which expects two parameters width and height here.
     */
    // write your code here
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }
    /*
     * Define a public method `getArea` which can calculate the area of the
     * rectangle and return.
     */
    // write your code here
    int getArea() {
       return height*width; 
    }
};

int main() {
    // your code goes here
	  Rectangle r(3, 4);
	  cout<<r.getArea()<<endl;
	  return 0;
}
