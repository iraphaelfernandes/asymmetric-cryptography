#include <bits/stdc++.h> 

using namespace std; 

//cppimplementation of the above approach 

//Function to return an array 
//of prime numbers upto n 
//using Sieve of Eratosthenes 
vector<int> seive(int n){ 
	vector<int> prime (n + 1,0); 
	int p = 2; 
	while(p * p<= n){ 
		if(prime[p]== 0){ 
			for (int i=2*p;i<n+1;i+=p) 
					prime[i]= 1; 
			} 
		p+= 1; 
	} 


	vector<int> allPrimes; 
	for (int i =2;i<n;i++) if (prime[i]==0) allPrimes.push_back(i); 
	return allPrimes; 
} 

//Function to return distinct 
//prime factors from the given array 
vector<int> distPrime(vector<int> arr, vector<int> allPrimes){ 

	//Creating an empty array 
	//to store distinct prime factors 
	vector<int> list1; 

	//Iterating through all the 
	//prime numbers and check if 
	//any of the prime numbers is a 
	//factor of the given input array 
	for (int i : allPrimes){ 
		for (int j :arr){ 
			if(j % i == 0){ 
				list1.push_back(i); 
				break; 
			} 
			} 
		} 
	return list1; 
} 

//Driver code 

int main() 
{ 
//Finding prime numbers upto 10000 
//using Sieve of Eratosthenes 
vector<int> allPrimes = seive(10000); 

vector<int> arr = {15, 30, 60}; 
vector<int> ans = distPrime(arr, allPrimes); 
cout<<"["; 
for(int i:ans) cout<<i<<" "; 
cout<<"]"; 

} 
