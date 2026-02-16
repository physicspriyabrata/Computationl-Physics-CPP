#include<iostream>
#include<cmath>
using namespace std;
float simpson( float x){
float fun= 4*x*x*x;
return fun;
}

int main() {
    int i, n;
    float a, b, h;
    float y0, yn, sum2 = 0, sum4 = 0, sum,ans;

    // User input
    cout << "Enter the lower limit, upper limit, and number of iterations (must be even): ";
    cin >> a >> b >> n;

    // Simpson's rule requires n to be even
    if (n % 2 != 0) {
        cout << "Error: Number of intervals (n) must be even for Simpson's 1/3 Rule!" << endl;
        return 1;  // Exit program with error
    }

    // Step size
    h = (b - a) / n;

    // Function values at endpoints
    y0 = simpson(a);
    yn = simpson(b);
    sum=y0 + yn;
    // Compute the sum for odd and even indices
   for(i=1; i<n; i++){
   if(i%2==0){
   sum2 +=2*simpson(a+i*h);
   }
    else{
   sum4 += 4*simpson(a+i*h);
   }

    cout<<"iteration: "<<i<<"	 integration value: "<<(h/3)*(sum+sum2+sum4)<<endl;
    }

    // Apply Simpson's 1/3 Rule formula
    ans = (h / 3) * (sum +  sum4 + sum2);

    // Output final result
    cout << "Final Integration Value: " << ans << endl;

    return 0;
}

