#include<iostream>
#include<cstdint> // for casting operators like NULL to pointer types
using namespace std;

int main()
{
    // 1. Define a pointer and assign it the address of an integer variable.
    int a = 10;
    int* p; // pointer declaration; * here is the pointer indicator
    // Grammar: data_type *pointer_name; or data_type* pointer_name;
    p = &a; // assign address of a to pointer p

    cout << "Pointer definition demonstration" << endl;
    cout << "Value of a: a = " << a << endl;
    cout << "Address of a: &a = " << &a << endl;            // & is the address-of operator
    cout << "Value of pointer p (address of a): p = " << p << endl;
    cout << "Value pointed to by p: *p = " << *p << endl;      // * here is the dereference operator
    // Conclusion:  value: a = *p, address: &a = p

    
   
    // 2. Use pointer arithmetic to modify the value of the integer variable.
    *p = 20; // modify the value at the address stored in p
    cout << "\nPointer arithmetic demonstration" << endl;
    cout << "New value of a after modifying through pointer p: a = " << a << endl;
    cout << "Value pointed to by p after modification: *p = " << *p << endl;
    // Insight: the usage of pointers allows indirect access and manipulation of variable values via their memory addresses.

    
    
    // 3. Memory of pointer variables
    // Note: The size of a pointer variable is typically constant regardless of the data type it points to.
    // On a 32-bit system, pointer size is usually 4 bytes; on a 64-bit system, it is usually 8 bytes.
    cout << "\nMemory demonstration" << endl;
    cout << "Size of integer type: sizeof(int) = " << sizeof(int) << " bytes" << endl;
    cout << "Size of pointer type: sizeof(int*) = " << sizeof(int*) << " bytes" << endl;
    cout << "Size of integer variable a: sizeof(a) = " << sizeof(a) << " bytes" << endl;
    cout << "Size of pointer variable p: sizeof(p) = " << sizeof(p) << " bytes" << endl;

    cout << "Size of double type: sizeof(double) = " << sizeof(double) << " bytes" << endl;
    cout << "Size of pointer to double type: sizeof(double*) = " << sizeof(double*) << " bytes" << endl;
    cout << "Size of float type: sizeof(float) = " << sizeof(float) << " bytes" << endl;
    cout << "Size of pointer to float type: sizeof(float*) = " << sizeof(float*) << " bytes" << endl;
    cout << "Size of long type: sizeof(long) = " << sizeof(long) << " bytes" << endl;
    cout << "Size of pointer to long type: sizeof(long*) = " << sizeof(long*) << " bytes" << endl;
    cout << "Size of short type: sizeof(short) = " << sizeof(short) << " bytes" << endl;
    cout << "Size of pointer to short type: sizeof(short*) = " << sizeof(short*) << " bytes" << endl;
    cout << "Size of char type: sizeof(char) = " << sizeof(char) << " bytes" << endl;
    cout << "Size of pointer to char type: sizeof(char*) = " << sizeof(char*) << " bytes" << endl;
    // Insight: pointer variables typically have a fixed size depending on the system architecture, not the data type they point to.

    
    
    // 4. Null pointer and wild pointer
    // Note: A null pointer is a pointer that does not point to any valid memory location (e.g., 0-255, which is normally reserved by the system). 
    // It is often initialized to NULL.
    int* nullPtr = NULL; // null pointer initialization (fix the pointing address of the declared pointer variable - to NULL)

    cout << "\nNull pointer demonstration" << endl;
    if (nullPtr == NULL)
    {
        cout << "Value of nullPtr is NULL=0: nullPtr = " << nullPtr << endl;
    }
    else
    {
        cout << "nullPtr is not a null pointer." << endl;
    }
    // Note: The memory pointed to by a null pointer cannot be accessed nor modified.
    // cout << "Attempting to dereference (access) nullPtr: *nullPtr = " << *nullPtr << endl; // This will likely cause a runtime error (segmentation fault).
    // *nullPtr = 1000; // This will likely cause a runtime error (segmentation fault) despite successful compilation.
    // cout << "After attempting to assign another value through nullPtr: *nullPtr = " << *nullPtr << endl;

    // wild pointer: a pointer that has not been initialized and points to an unknown/unrequested memory location.
    int* wildPtr1; // wild pointer declaration (uninitialized pointer variable)
    int* wildPtr2 = (int*) 0xDEADBEEF; // another wild pointer declaration (uninitialized pointer variable)
    cout << "\nWild pointer demonstration" << endl;
    cout << "Value of wildPtr1 (uninitialized): wildPtr1 = " << wildPtr1 << endl;
    cout << "Value of wildPtr2 (uninitialized): wildPtr2 = " << wildPtr2 << endl;
    // Note: The unrequested memory pointed to by a wild pointer cannot be accessed nor modified.
    // cout << "Attempting to dereference (access) wildPtr1: *wildPtr1 = " << *wildPtr1 << endl; // This will likely cause a runtime error (segmentation fault).
    // *wildPtr1 = 2000; // This will likely cause a runtime error (segmentation fault).
    // cout << "After attempting to assign another value through wildPtr1: *wildPtr1 = " << *wildPtr1 << endl;
    // cout << "Attempting to dereference (access) wildPtr2: *wildPtr2 = " << *wildPtr2 << endl; // This will likely cause a runtime error (segmentation fault).
    // *wildPtr2 = 3000; // This will likely cause a runtime error (segmentation fault).
    // cout << "After attempting to assign another value through wildPtr2: *wildPtr2 = " << *wildPtr2 << endl;

    
    
    // 5. Declaring pointers with const qualifier
    int b1 = 30;
    int b2 = 30;
    int b3 = 30;
    // Note: const int* <=> int const*, but int* const != const int* const
    const int* p1 = &b1; // pointer to const int (the value being pointed to cannot be modified through this pointer)
    int const* p1 = &b1; // pointer to const int (the value being pointed to cannot be modified through this pointer)
    int* const p2 = &b2; // const pointer to int (the pointing address stored in the pointer cannot be modified)
    // const* int p2 = &b2; // illegal syntax because * must not come before data type
    const int* const p3 = &b3; // const pointer to const int (neither the pointer nor the value being pointed to can be changed)

    p1 = &b1;  // OK: can change the address stored in the pointer
    // *p1 = 50; // Syntax Error: cannot modify value through pointer to const
    // p2 = &b2; // Syntax Error: cannot change the address stored in const pointer
    *p2 = 50; // OK: can modify value through const pointer
    // p3 = &b3;  // Syntax Error: cannot change the address stored in const pointer
    // *p3 = 50; // Syntax Error: cannot modify value through const pointer to const

    cout << "\nConst pointer demonstration" << endl;
    cout << "Address stored in p1 (pointer to const int): p1 = " << p1 << endl;
    cout << "Value pointed to by p1 (pointer to const int): *p1 = " << *p1 << endl;
    cout << "Address stored in p2 (const pointer to int): p2 = " << p2 << endl;
    cout << "Value pointed to by p2 (const pointer to int): *p2 = " << *p2 << endl;
    cout << "Address stored in p3 (const pointer to const int): p3 = " << p3 << endl;
    cout << "Value pointed to by p3 (const pointer to const int): *p3 = " << *p3 << endl;


    
    // 6. Using pointer to access array elements
    int arr[] = {10, 20, 30, 40, 50};
    int* pArr = arr; // the address of (the first element of) an array arr is just arr, not &arr

    cout << "\nPointer to array demonstration" << endl;
    // method 1: access array elements using pointer arithmetic
    for (int i = 0; i < 5; i++)
    {
        cout << "Element " << i << " of array using pointer: *(pArr + " << i << ") = " << *(pArr + i) << endl;
    }
    // method 2: access array elements by incrementing the pointer
    for (int i = 0; i < 5; i++)
    {
        cout << "Element " << i << " of array using pointer: *pArr = " << *pArr << endl;
        pArr++; // re-point the pointer to the next element
    }



    // 7. Using pointer as formal function parameter (value passing vs. address passing)
    int x1 = 100;
    int y1 = 200;
    int x2 = 100;
    int y2 = 200;

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

    cout << "\nPointer as function parameter demonstration" << endl;
    cout << "Before swap_by_value: x1 = " << x1 << ", y1 = " << y1 << endl;
    swap_by_value(x1, y1);
    cout << "After swap_by_value: x1 = " << x1 << ", y1 = " << y1 << " (no change)" << endl;
    cout << "Before swap_by_address: x2 = " << x2 << ", y2 = " << y2 << endl;
    swap_by_address(&x2, &y2);
    cout << "After swap_by_address: x2 = " << x2 << ", y2 = " << y2 << " (swapped)" << endl;
    // Conclusion: using pointers as function parameters allows functions to modify the original variables 
    // by passing their addresses, while value passing only works on copies of the variables.


    return 0;
}