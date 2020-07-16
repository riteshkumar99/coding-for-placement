#include <iostream>
#include <string>
#include <bitset>
using namespace std;

string BinaryReversal(string str) {
  long num = stol(str);
  long result = 0;
  if(num < (1u<<8)) {
    const bitset<8> b(num);
    for(int i = 0; i<8; i++) {
        if(b[i]) {
            result += (1 << (7-i));
        }
    }
  } else if(num < (1u<<16)) {
    const bitset<16> b(num);
    for(int i = 0; i<16; i++) {
        if(b[i]) {
            result += (1 << (15-i));
        }
    }
  } else {
    const bitset<32> b(num);
    for(int i = 0; i<32; i++) {
        if(b[i]) {
            result += (1 << (31-i));
        }
    }
  }
  return to_string(result);
}

int main(void) { 
   
  // keep this function call here
  cout << BinaryReversal("213");
  return 0;
    
}
