# Tower-of-Hanoi

This program solves the Tower of Hanoi problem using recursion. 

Algorithm: https://www.cs.cmu.edu/~cburch/survey/recurse/hanoiimpl.html 

In main.cpp, I tried to solve this problem using C++ Object Oriented Programming concepts. Objects in this program are passed by references. This helps us in two ways:
1. Modifying local variables at the caller function
2. Passing large arguments in the function

When passing arguments by reference, only the reference to the object is passed. If we had passed by value, a copy of the object is created and passed as argument.
