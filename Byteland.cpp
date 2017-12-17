#include <stdio.h>
#include <iostream>
#define MOD 1000000007

using namespace std;

void multiply(long long int Fib[2][2], long long int Mul[2][2]);
 
void getPower(long long int Fib[2][2], long long int n);

long long int getFib(long long int n){
	
	long long int Fib[2][2] = {{1,1},{1,0}};
	
	if (n == 0){
		return 0;
	}else if (n == 1 || n == 2){
		return n+1;
	}
	
	getPower(Fib, n-2);
	
	return (Fib[0][0]*3+Fib[0][1]*2)%MOD;
}

void multiply(long long int Fib[2][2], long long int Mul[2][2]){
	
	long long int x =  ((Fib[0][0]*Mul[0][0])%MOD + (Fib[0][1]*Mul[1][0])%MOD)%MOD;
	long long int y =  ((Fib[0][0]*Mul[0][1])%MOD + (Fib[0][1]*Mul[1][1])%MOD)%MOD;
	long long int z =  ((Fib[1][0]*Mul[0][0])%MOD + (Fib[1][1]*Mul[1][0])%MOD)%MOD;
	long long int w =  ((Fib[1][0]*Mul[0][1])%MOD + (Fib[1][1]*Mul[1][1])%MOD)%MOD;
	
	Fib[0][0] = x;
	Fib[0][1] = y;
	Fib[1][0] = z;
	Fib[1][1] = w;
	
}

void getPower(long long int Fib[2][2], long long int n){
	
	if( n == 0 || n == 1){
		return;
	}
	
	long long int Mul[2][2] = {{1,1},{1,0}};
	
	getPower(Fib, n/2);
	multiply(Fib, Fib);
	
	if (n%2 != 0){
		multiply(Fib, Mul);
	}
	
}

int main()
{
	long long int Tc;
	cin >> Tc;
	while(Tc--)
	{
		long long int num;
		cin >> num;
		cout << getFib(num) << endl;
	}
	return 0;
}