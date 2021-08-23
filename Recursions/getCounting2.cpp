#include<bits/stdc++.h>
using namespace std;

void getCounting(int n){
    
    //Base condition
    if(n<=0)
    return;

    //Subproblem or recursive call
    getCounting(n-1);

    cout << n << endl;


}

int main(){

    int n;
    cout << "Please enter the input" << endl;
    cin >> n;

    cout << "Counting: " << endl;
    getCounting(n);
}

//This program will FIRST do the recursive call and then print the numbers.
