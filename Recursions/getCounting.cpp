#include<bits/stdc++.h>
using namespace std;

void getCounting(int n){
    
    //Base condition
    if(n<=0)
    return;

    cout << n << endl;

    //Subproblem or recursive call
    getCounting(n-1);
}

int main(){

    int n;
    cout << "Please enter the input" << endl;
    cin >> n;

    cout << "Counting: " << endl;
    getCounting(n);
}

//This program will print the numbers FIRST and then do the recursive call
