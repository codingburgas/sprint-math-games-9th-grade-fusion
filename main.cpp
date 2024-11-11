#include <iostream>
using namespace std;
 
int main(){
    int n=0;
    cin>>n;
    int evenSum = 0;
    int oddSum = 0;
 
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
         if(i % 2 == 0){
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }

 
    
 
    

 
    if(evenSum == oddSum){
        cout << "Yes" << endl;
        cout << "Sum = " << evenSum << endl;
    } else {
        cout << "No" << endl;
        cout << "Diff = " << abs(evenSum - oddSum) << endl;
    }
 
 
}