#include <stdio.h>
#include <stdlib.h>

// Modify the code so it accept input data as command-line arguments.
int main(int argc, char *argv[]) {
  int empno;
  float rate, hours, pay;
  void calcpay(float *p, float r, float h);
  int i = 2;
  
  while(i < argc) {
      empno = atoi(argv[i++]);
      rate = atof(argv[i++]);
      hours = atof(argv[i++]);
      
      calcpay(&pay, rate, hours);
      printf("Employee=%d Rate=%.2f Hours=%.2f Pay=%.2f\n",empno, rate, hours, pay);
  } 
}

void calcpay(float *p, float r, float h) {
    if(h > 40) {
        *p = (r * 40) + ((r * 1.5) * (h - 40));
    } else {
        *p = r * h;
    }
}