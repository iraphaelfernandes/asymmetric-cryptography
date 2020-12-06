#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int gcd(int a, int b);
// Utility function to find 
// GCD of 'a' and 'b' 

// Driver Code 
int main() {
   
	int arr[] = { 2, 3}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf("%d", findlcm(arr, n)); 
	return 0; 
} 


int gcd(int a, int b) 
{ 
	if (b == 0) 
		return a; 
	return gcd(b, a % b); 
} 

// Returns LCM of array elements 
int findlcm(int arr[], int n) 
{ 
	// Initialize result 
	ll ans = arr[0]; 

	// ans contains LCM of arr[0], ..arr[i] 
	// after i'th iteration, 
	for (int i = 1; i < n; i++) 
		ans = (((arr[i] * ans)) / 
				(gcd(arr[i], ans))); 

	return ans; 
} 

// Driver Code 
int main() {

	int arr[] = { 2, 3}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf("%lld", findlcm(arr, n)); 
	return 0; 
} 
