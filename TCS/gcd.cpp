class Solution {
  public:
    int gcd(int a, int b) {
      while(b)
      {
          int rem=a%b;
          a=b;
          b=rem;
      }
      return a;
    }
};
