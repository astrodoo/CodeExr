#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>

int
main (void)
{
  //double y = gsl_sf_bessel_J0 (x);
  double x,y;

  for( int i=1; i<500; i++) {
	x = (float)i / 100.*10;
	y = gsl_sf_bessel_Knu(1./3., x);
	//printf ("Knu(%g) = %.18e\n", x, y);
	printf ("%.10e \t %.10e\n", x, y);
  }
  return 0;
}
