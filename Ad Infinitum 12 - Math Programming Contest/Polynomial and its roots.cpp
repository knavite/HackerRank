#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int degree;
	cin>>degree;
	int a,b,z;
	for(int i=0;i<=degree;i++) {
		int temp;
		cin>>temp;
		if(i==0)
			z=temp;
		else if(i==degree-1)
			b=temp;
		else if(i==degree)
			a=temp;
	}
	if(degree>=2)
		cout<<-b/a<<" "<<(degree%2==0 ? z/a : -z/a )<<endl;
	else	
		cout<<-z/a<<" "<<-z/a<<endl;
    return 0;
}
