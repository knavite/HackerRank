#include <iostream>
#include <cmath>
using namespace std;

bool check(int num, int x, int y, int z) {
  while(num) {
    int digit = num % 10;
    if (digit == 4 && x) x--;
    else if (digit == 5 && y) y--;
    else if (digit == 6 && z) z--;
    else return false;
    num /= 10;
  }
  return true;
}

#define X 1
#define Y 1
#define Z 2

int main() {
  long long sum = 0;
  int cnt4=0,cnt5=0,cnt6=0;
  for (int i = 10; i <= 100; i++) {
    if (check(i, X, Y, Z)) {
      if (sum) {
        cout << " + ";
      }
      sum += i;
      cout << i;
	  if(i%10==4)
		cnt4++;
	if(i%10==5)
		cnt5++;
		if(i%10==6)
		cnt6++;
    }
  }
  
  cout << " = " << sum << " "<<cnt4<<" "<<cnt5<<" "<<cnt6<<" "<< endl;
}