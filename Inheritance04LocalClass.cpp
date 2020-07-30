/*
 * =====================================================================================
 *
 *       Filename:  Inheritance04LocalClass.cpp
 *
 *    Description:  Inheritance Local Classes
 *
 *        Created:  26/07/2020
 *
 *         Author:  Maikol Guzmán mike@guzmanalan.com
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */

#include <iostream>  // allows program to output data to the screen

class OtherClass {
  int numberA = 3; // private property
  friend class Test; // modify access
};

class Test {
  int numberB; // private property

public:
  int getValue() const {
    struct Local {
      Local(OtherClass &o)
        : mOtherClass(o)
      { }

      int get_other_value() {
        return mOtherClass.numberA;
      }

      OtherClass &mOtherClass;
    };

    OtherClass otherClass;
    Local local(otherClass);
    return local.get_other_value();
  }
};

int main() {
  std::cout << "Welcome to the UNA!" << std::endl;  // display message

  Test test;
  return test.getValue();
}
