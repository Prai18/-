#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
  FILE *fp;
  // getchar() waiting can be used instead of "persist" option.
  //  fp = popen("gnuplot -persist", "w");
  fp = popen("gnuplot -persist", "w");
  if (fp == NULL) {
    fprintf(stderr, "gnuplot can't open\n");
    exit(1);
  }
  
  // statically assign the x-y axis
  fprintf(fp, "set xrange [0:4*3.14]\n");
  fprintf(fp, "set yrange [-1.0:1.0]\n");
  fflush(fp);

  
  for (int i=0; i<100; ++i) {
    fprintf(fp, "plot '-' with lines\n");
    for (double x=0; x<4*M_PI; x+=0.01) {
      fprintf(fp, "%f %f\n",x, sin(x+0.1*i));
    }
    fprintf(fp, "e\n");
    fflush(fp);
  }
    
  // close
  fprintf(fp, "exit\n");
  fflush(fp);
  pclose(fp);
  return 0;
}