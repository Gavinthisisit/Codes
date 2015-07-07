 #include <iostream>
  using namespace std;
  
  char toch(int n) {
      return n+'0';
  }
  
  long long power(int e) {
      int sum = 1, i = 0;
     for (; i<e; i++)
         sum *= 10;
     return sum;
 }
 
 void gen(long long n, char* s) {
     long long i, lvl = 0, w, t, div;
     for (i=0; ; i++) {
         t = 9 * power(i/2);
         if (n <= lvl+t) {
             w = i+1;
             n -= lvl;
             break;
         }
         lvl += t;
     }    
     n--;    
     div = power((w-1)/2);
     for (i=0; i<(w+1)/2; i++) {
         s[i] = s[w-i-1] = toch(w<3 ? n/div+1 : (i?n/div:n/div+1));
         n %= div;
         div /= 10;
     }
 }
 
 int main() {
     long long t;
     while (1) {
         cin >> t;
         if (!t)
             break;
         char s[1000] = {0};
         gen(t, s);
         cout << s << endl;
     }
     return 0;
}
