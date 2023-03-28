#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
  int i, npts;
  double dz, D, dr, drbydz, t, dt, dtbydz;
  float  c = 3e5, z, om0 = 0.27, ol0 = 0.73, h0 = 71, age = 977.7/h0, temp, ztemp;
   
   printf("\nRedshift? "); scanf("%f", &z);

   D = 0; // initialize

   npts = 10000; 
   dz = z/(float)npts;
   for (i=0; i<npts; ++i){  
     ztemp = i*dz; // calculating for each small slice of z
     temp = ol0 + ((1-ol0-om0)*pow(ztemp+1,2)) + (om0*pow(ztemp+1,3)); 
     drbydz = (c/h0)*(pow(temp,-0.5)); 
     D = D + drbydz*dz;  // summing

     dtbydz = (1/h0)*(1/(ztemp+1))*(pow(temp,-0.5));  
     t = t + dtbydz*dz;
   }
   printf("For z = %1.5f, D_c = %1.2f Mpc, D_A = %1.2f Mpc and D_L = %1.2f Mpc = %1.4e m, LBT = %1.4f Gyr, age of Universe = %1.4f Gyr\n", z, D, D/(z+1), D*(z+1), D*(z+1)*1e6*3.0857e16,977.7*t,age-(977.7*t));

   

}
// gcc -o cosm cosm.c; ./cosm 
