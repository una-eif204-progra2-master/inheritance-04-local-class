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
  Test test;
  return test.getValue();
}
