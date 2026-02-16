#include<iostream>
#include<cmath>
using namespace std;

// Define the function for the bisection method
float bisection(float x)
{
   float fun =x*x*x - x*x - x -5;  // Equation to solve
    return fun;
}

int main()
{
float fun, x;
x=3.57227;
fun=bisection(x);

cout <<fun;
return 0;
}
