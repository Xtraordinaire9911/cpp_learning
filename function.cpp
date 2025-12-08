#include<iostream>
using namespace std;


// 1. Default parameters in functions
// Note: default parameters must be trailing parameters (i.e., from right to left)
// Grammar: return_type function_name(data_type1 param1 = default_value1, data_type2 param2 = default_value2, ...)
int add1(int a, int b = 10, int c = 20)
{
    return a + b + c;
}
// int add2(int a, int b = 20, int c)  // Error: default parameter b must be trailing parameter
// {
//     return a + b + c;
// }

// Note: default parameters can only exists either in function declaration or in function definition, not both
// legal example 1:
int multiply1(int a, int b, int c);
int multiply1(int a, int b = 2, int c = 3) // default parameters in function definition
{
    return a * b * c;
}
// legal example 2:
int multiply2(int a = 1, int b = 2, int c = 3); // default parameters in function declaration
int multiply2(int a, int b, int c)
{
    return a * b * c;
}
// illegal example:
// int multiply3(int a, int b, int c = 3);
// int multiply3(int a, int b, int c = 3) // Error: default parameters in declaration cannot be re-defined 
// (even through the same value) in function definition



// 2. Placeholder parameters with default arguments
// Note: if a function has placeholder parameters (i.e., parameters without names),
// they must be assigned default arguments in function declaration or definition

// Method 1: unnamed parameter without default argument
// Grammar: return_type function_name(data_type1 param1, data_type2 param2, ..., data_typen )
int multiply4(int a, int b, int c, int)
{
    return  a * b * c;
}
// Method 2: unnamed parameter with default argument
// Grammar: return_type function_name(data_type1 param1 = default_value1, data_type2 /*param2*/ = default_value2, ...)
int multiply5(int a, int b, int c, int /*d*/ = 5)
{
    return  a * b * c * 10; // one is allowed to use value other than the default argument for the unnamed parameter
}
// Insight: placeholder parameters can be used when the parameter value is not needed in function body,
// but the parameter is required for function signature matching during function calls - e.g., function overloading



// 3. Function overloading (detailed conditions + case divisions + conflict/potential conflict/illegal form explanations)

//Note: the conditions for function overloading include:
// 1) Same scope
// 2) Same function name
// 3) Different function signatures (i.e., different number of non-default parameters, or different data types on some positions of the parameters)
// Note: function overloading cannot be done by only changing the return type of functions
// Note: function overloading is not allowed if two functions differ only in their default parameters

void func(int a)
{
    cout << "func(int a) called with a = " << a << endl;
}

// int func(int a) // Error: redefinition caused by same function signature (only differ in return type)
// {
//     cout << "func(int a) called with a = " << a << endl;
//     return a * 2;
// }

// void func(int ) // Error: redefinition caused by same function signature (only differ in undefault parameter name)
// {
//     cout << "func(int) called"<< endl;
// }

// int func(int x = 10)    // Error: re-definition caused by same function signature (differ in signature-irrelevant return type + elsely named default parameter)
// {
//     cout << "func(int a = 10) called with a = " << a << endl;
//     return a * 2;
// }

// int func(int a, int b = 10) // Error: re-definition caused by same function signature (differ in signature-irrelevant return type + extra default parameter)
// {
//     cout << "func(int a, int b = 10) called with a = " << a << ", b = " << b << endl;
//     return a + b;
// }

void func(double a)
{
    cout << "func(double a) called with a = " << a << endl;
}
void func(int a, double b)
{
    cout << "func(int a, double b) called with a = " << a << ", b = " << b << endl;
}
void func(double a, int b)
{
    cout << "func(double a, int b) called with a = " << a << ", b = " << b << endl;
}
// void func(double b, int a)  // Error: re-definition of func(double a, int b) (instead of func(int a, double b))
// {
//     cout << "func(double b, int a) called with b = " << b << ", a = " << a << endl;
// }
void func(int* a)
{
    cout << "func(int* a) called with a = " << a << endl;
}
void func(const int* a)
{
    cout << "func(const int* a) called with a = " << a << endl;
}
// Note: const int* <=> int const*, but int* const != const int* const
// void func(int const* a)
// {
//     cout << "func(const int* a) called with a = " << a << endl;
// }

// void func(const int* const a)   // potential conflict with func(int* a) if called with a constant pointer
// {
//     cout << "func(const int* const a) called with a = " << a << endl;
// }

// Note: int* const is seen as int* in function signature resolution, though they are two different types
// void func(int* const a) // Error: conflict with func(int* a)
// {
//     cout << "func(int* const a) called with a = " << a << endl;
// }

// Note: int& and const int& are two different types
// void func(int& a)   // potential conflict with func(int a) if called with an integer variable
// {
//     cout << "func(int& a) called with a = " << a << endl;
// }

// void func(const int& a) // potential conflict with func(int a) if called with a constant integer (literal)
// {
//     cout << "func(const int& a) called with a = " << a << endl;
// }

// void func(int& const a) // Illegal: reference to constant literal is not allowed
// {
//     cout << "func(int const& a) called with a = " << a << endl;
// }

// void func(const int& const a)   // Illegal: (constant) reference to constant literal is not allowed
// {
//     cout << "func(const int& const a) called with a = " << a << endl;
// }

// Note: it is not allowed to specify the same symbol (func) both as internal linkage (non-static) 
// and as external linkage (static) in the same scope.
// static void func(int a) // Error: conflict with func(int a)
// {
//     cout << "static func(int a) called with a = " << a << endl;
// }

int main()
{
    cout << "Default parameters demonstration" << endl;
    cout << "Result of add1(5): " << add1(5) << endl;               // uses default b=10, c=20
    cout << "Result of add1(5, 15): " << add1(5, 15) << endl;       // uses default c=20
    cout << "Result of add1(5, 15, 25): " << add1(5, 15, 25) << endl; // no default parameters used
    cout << "Result of multiply1(4): " << multiply1(4) << endl; // uses default b=2, c=3
    cout << "Result of multiply2(): " << multiply2() << endl;     // uses default a=1, b=2, c=3
    // cout << "Result of multiply3(4, 5, 6): " << multiply2(4, 5, 6) << endl; // function is illegally defined



    cout << "\nPlaceholder parameters demonstration" << endl;
    cout << "Result of multiply4(2, 3, 4, 5): " << multiply4(2, 3, 4, 5) << endl; // uses unnamed parameter without default argument
    cout << "Result of multiply5(2, 3, 4): " << multiply5(2, 3, 4) << endl; // uses default d=3



    int x = 100;
    cout << "\nFunction overloading demonstration" << endl;
    func(10);               // conflict: both func(int a) and func(const int& a) are possible to be called
    func(3.14);            // calls func(double a)
    func(10, 3.14);        // calls func(int a, double b)
    func(3.14, 10);        // calls func(double a, int b)
    // func(3.14, 10);        // calls func(double b, int a)
    func(x);                // conflict: both func(int a) and func(int& a) are possible to be called
    func(&x);              // calls func(int* a)
    // func(&10);            // illegal: cannot take address of a literal, as it is stored in read-only memory and is not a lvalue



    return 0;
}