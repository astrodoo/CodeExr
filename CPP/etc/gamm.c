#include <stdio.h>
#include <math.h>
#include <gsl/gsl_sf_gamma.h>

int
main (void)
{ 
  //double y = gsl_sf_bessel_J0 (x);
  double x,y;

  x = gsl_sf_gamma(100.);
  y = gsl_sf_lngamma(100.);
  printf ("%e \t %e \t %e\n", x, log(x), y);
  
  return 0;
}
