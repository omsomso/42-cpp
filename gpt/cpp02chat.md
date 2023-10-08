# Copy constructor

In C++, a copy constructor is a special member function that initializes a new object by making a copy of an existing object of the same class. It is invoked automatically when a new object is created from an existing object, typically through initialization or assignment. The copy constructor allows you to create a duplicate of an object, preserving its state.

The copy constructor has the following characteristics:

1. **Signature:** The copy constructor has the same name as the class it belongs to and takes a single parameter of the same class type as a reference or as a constant reference. Its signature typically looks like this:

   ```cpp
   ClassName(const ClassName& other);
   ```

2. **Purpose:** The primary purpose of the copy constructor is to create a new object that is a copy of an existing object. It initializes the new object's data members to the same values as the corresponding data members of the existing object.

3. **When It Is Called:**
   - When an object is created as a copy of an existing object during initialization.
   - When an object is passed by value as a function argument, and when it is returned by value from a function.
   - When an object is assigned the value of another object of the same class using the assignment operator (`=`).

Here's an example of a copy constructor:

```cpp
class MyClass {
public:
    int value;

    // Copy constructor
    MyClass(const MyClass& other) {
        value = other.value;
    }
};

int main() {
    MyClass obj1;
    obj1.value = 42;

    // Create obj2 as a copy of obj1 using the copy constructor
    MyClass obj2 = obj1;

    // obj3 is also created as a copy of obj1 using the copy constructor
    MyClass obj3(obj1);

    // Now, obj2 and obj3 have the same value as obj1
    std::cout << "obj2.value: " << obj2.value << std::endl; // 42
    std::cout << "obj3.value: " << obj3.value << std::endl; // 42

    return 0;
}
```

In this example, the copy constructor of `MyClass` is used to create `obj2` and `obj3` as copies of `obj1`.

If you do not provide a custom copy constructor, C++ will generate a default copy constructor for your class. However, if your class contains dynamically allocated resources or if you need to perform deep copying, it's often advisable to provide your own copy constructor to ensure proper handling of those resources.