#include<iostream>
using namespace std;


// an in-compilation-stage illegal function: do not return reference of local variable
// int& return_local_reference()
// {
//     int local_var = 10;
//     return local_var; // return an alias of the local variable local_var
// }

int& return_static_reference()
{
    static int static_var = 20; // static variable is stored in the static/global storage area, 
    // and is released by the system when the program (instead of the function) ends
    return static_var; // return an alias of the static variable static_var
}

int main()
{
    // 1. Definition and grammar of reference
    int a = 10;
    // int &b; // Error: reference must be immediately initialized when declared
    int& b = a; // reference declaration and initialization
    // Grammar: data_type& reference_name = variable_name;

    cout << "Reference definition demonstration" << endl;
    cout << "Value of a: a = " << a << endl;
    cout << "Value of reference b: b = " << b << endl;
    cout << "Address of a: &a = " << &a << endl;
    cout << "Address of reference b: &b = " << &b << endl;
    // Conclusion: reference is an alias for the original variable; both share the same memory address
    b = 20; // modify the value of a through reference b
    cout << "Value of a after modification through reference b: a = " << a << endl;
    cout << "Value of reference b: b = " << b << endl;
    cout << "Address of a: &a = " << &a << endl;
    cout << "Address of reference b: &b = " << &b << endl;
    a = 30; // modify the value of a directly
    cout << "Value of a after direct modification: a = " << a << endl;
    cout << "Value of reference b: b = " << b << endl;
    cout << "Address of a: &a = " << &a << endl;
    cout << "Address of reference b: &b = " << &b << endl;
    // Conclusion: reference is an alias for the original variable; 
    // modifying the reference resp. original modifies the original resp. reference, 
    // while their addresses remain the same.

    // Insight: references provide a way to create aliases for variables, 
    // allowing indirect access and modification of variable values without the need for explicit pointer syntax.



    // 2. Reference as formal function parameter (address passing)
    int x1 = 100;
    int y1 = 200;
    int x2 = 100;
    int y2 = 200;
    int x3 = 100;
    int y3 = 200;

    // classic swap function using value passing (will not swap the original values)
    auto swap_by_value = [](int x, int y) 
    {
        int temp = x;
        x = y;
        y = temp;
    };
    // swap function using address passing (will swap the original values)
    auto swap_by_address = [](int* x, int* y) 
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    };
    // swap function using references as parameters
    auto swap_by_reference = [](int& x, int& y)
    {
        int temp = x;
        x = y;
        y = temp;
    };

    cout << "\nReference as function parameter demonstration" << endl;
    cout << "Before swap_by_value: x1 = " << x1 << ", y1 = " << y1 << endl;
    swap_by_value(x1, y1);
    cout << "After swap_by_value: x1 = " << x1 << ", y1 = " << y1 << " (no change)" << endl;
    cout << "Before swap_by_address: x2 = " << x2 << ", y2 = " << y2 << endl;
    swap_by_address(&x2, &y2);
    cout << "After swap_by_address: x2 = " << x2 << ", y2 = " << y2 << " (swapped)" << endl;
    cout << "Before swap_by_reference: x3 = " << x3 << ", y3 = " << y3 << endl;
    swap_by_reference(x3, y3);
    cout << "After swap_by_reference: x3 = " << x3 << ", y3 = " << y3 << " (swapped)" << endl;
    // Conclusion: using references as function parameters allows functions to modify the original variables 
    // directly by passing them as aliases, similar to value passing but works on the original variables. instead of copies.



    // 3. Using reference as return value from function
    // Note: do not return reference of local variable (will cause undefined behavior)
    // int& ref = return_local_reference(); // Error: undefined behavior
    cout << "\nReference as return value demonstration" << endl;
    // cout << "Value of ref returned from return_local_reference(): ref = " << ref << endl;
    // Conclusion: returning reference to local variable leads to undefined behavior since the local variable goes
    // out of scope after the function returns.

    int& static_ref = return_static_reference(); // get reference to static variable
    cout << "Value of static variable before modification through static_ref: return_static_reference() = " << return_static_reference() << endl;
    static_ref = 50; // modify the static variable through the returned reference
    cout << "Value of static variable after modification through static_ref: return_static_reference() = " << return_static_reference() << endl;
    // Conclusion: returning reference to static variable is valid since static variable remains in scope for the program's lifetime.
    // The returned reference can be used as an lvalue to modify the original static variable.


    // Note: call of functions can be used as lvalues if the function returns a reference (of non-local variable)
    return_static_reference() = 100; // modify the static variable directly via function call (as lvalue - on the left of =)
    cout << "Value of static variable after direct modification via function call as lvalue: return_static_reference() = " << return_static_reference() << endl;
    cout << "Value of static_ref after modification via function call: static_ref = " << static_ref << endl;
    // Conclusion: modify the function call as lvalue = modify the reference (alias) of the static variable returned by the function.


    // Note: once a reference is initialized to a variable, it cannot be changed to refer to another variable
    int c = 1000;
    int d = 2000;
    int& ref_c = c; // reference ref_c refers to variable c
    cout << "Value of c after 'ref_c = c': c = " << c << endl;
    cout << "Value of d after 'ref_c = c': d = " << d << endl;
    cout << "Value of ref_c: ref_c = " << ref_c << endl;
    ref_c = d; // Note: this does NOT re-reference ref_c to refer to d; 
    //instead, it only re-assigns the value of d to c (the original variable of ref_c), thus still legal
    cout << "Value of c after 'ref_c = d': c = " << c << endl;
    cout << "Value of d after 'ref_c = d': d = " << d << endl;
    cout << "Value of ref_c: ref_c = " << ref_c << endl;
    // &ref_c = &d; // Error: cannot change the address of reference ref_c to refer to d; will cause compilation error
    // cout << "Value of c after '&ref_c = &d': c = " << c << endl;
    // cout << "Value of d after '&ref_c = &d': d = " << d << endl;
    // cout << "Value of ref_c: ref_c = " << ref_c << endl;
    // Conclusion: references cannot be re-bound to refer to another variable after initialization; 
    // assignment to a reference modifies the original variable it refers to
    
    // Insight: the essense of reference is a constant pointer (that is automatically dereferenced by the compiler during assignment).
    // i.e., int& ref = a <=> int* const ref = &a
    // i.e., ref = 100 <=> *ref = 100



    // 4. Constant reference
    // Note: reference must be referenced to a variable (on stack or heap), not a constant (on literal pool)
    // int& const_ref = 10; // Error: refer to constant literal directly
    const int& const_ref = a; // constant reference declaration and initialization
    // Insight: const int& const_ref = 10 <=> int temp = 10; const int& const_ref = temp;
    cout << "\nConstant reference demonstration" << endl;
    cout << "Value of a: a = " << a << endl;
    cout << "Value of constant reference const_ref: const_ref = " << const_ref << endl;
    cout << "Address of a: &a = " << &a << endl;
    cout << "Address of constant reference const_ref: &const_ref = " << &const_ref << endl;
    // const_ref = 40; // Error: cannot modify value through constant
    


    return 0;
}