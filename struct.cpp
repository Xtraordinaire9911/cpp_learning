#include<iostream>
using namespace std;

int main()
{
    // 1. Definition and value assignment methods
    struct Person
    {
        string name;
        int age;
        float height;
    };

    // Method 1: define struct variable and assign values later
    // Grammar: (struct) struct_name variable_name; then variable_name.member_name = value;
    Person person1; // struct variable created here
    person1.name = "Alice";
    person1.age = 25;
    person1.height = 5.5f;
    // Method 2: define and assign values at the same time
    // Grammar: (struct) struct_name variable_name = {value1, value2, ...};
    Person person2 = {"Bob", 30, 6.0f};
    
    cout << "Struct definition and value assignments demonstration" << endl;
    // use member access operator (.) to access struct members, e.g., variable_name.member_name
    cout << "Person 1: Name = " << person1.name << ", Age = " << person1.age << ", Height = " << person1.height << endl;
    cout << "Person 2: Name = " << person2.name << ", Age = " << person2.age << ", Height = " << person2.height << endl;



    // 2. Struct array
    Person people1[2]; // define an array of struct Person with 2 elements
    people1[0] = person1; // assign person1 to the first element
    people1[1] = person2; // assign person2 to the second element
    // Alternatively, define and assign values at the same time
    Person people2[2] = 
    {
        {"Charlie", 28, 5.8f}, 
        {"Diana", 22, 5.4f}
    };

    cout << "\nStruct array demonstration" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "Person " << i + 1 << ": Name = " << people1[i].name << ", Age = " << people1[i].age << ", Height = " << people1[i].height << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "Person " << i + 1 << ": Name = " << people2[i].name << ", Age = " << people2[i].age << ", Height = " << people2[i].height << endl;
    }



    // 3. Struct pointer (operator: * vs. ->)
    Person* pPerson; // define a pointer to struct Person
    pPerson = &person1; // assign the address of person1 to the pointer
    cout << "\nStruct pointer demonstration" << endl;
    cout << "Accessing struct members via pointer using first dereference operator (*) then member access operator (.) on the dereferenced struct" << endl;
    cout << "Person pointed to by pPerson: Name = " << (*pPerson).name << ", Age = " << (*pPerson).age << ", Height = " << (*pPerson).height << endl;
    cout << "Accessing struct members via pointer using directly arrow operator (->) on the struct pointer" << endl;
    cout << "Person pointed to by pPerson: Name = " << pPerson->name << ", Age = " << pPerson->age << ", Height = " << pPerson->height << endl;
    // Conclusion: when it is a struct on the left, use .; when it is a struct pointer on the left, use ->.




}