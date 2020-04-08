#include "hdf5.h"
#define H5FILE_NAME "test.hdf5"

int main()
{
	hid_t   file_id, ds_id;       /* File and dataset identifiers */
	hid_t   attr_id;              /* attribute identifier */
	hid_t       dataspace, memspace;   /* identifiers for data and memory space */
	hsize_t     dimsm[1];              /* memory space dimensions */

	herr_t  ret;                /* Return value */

	double t,a,gam,Rin,Rout,hslope,R0;
	int N1, N2, N3;
	int RANK_OUT=1;
	int i,j,z,gridIndex,gridIndex2D;
	double startx[3], dx[3];

	//double x1[1800];
	double *x1,*x2,*x3,*r,*h,*ph,*RHO,*UU,*U1,*U2,*U3,*B1,*B2,*B3,*gdet,*Ucov0,*Ucon0;


	file_id = H5Fopen(H5FILE_NAME, H5F_ACC_RDONLY, H5P_DEFAULT);

	attr_id = H5Aopen(file_id, "t", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_DOUBLE, &t);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "N1", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_INT, &N1);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "N2", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_INT, &N2);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "N3", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_INT, &N3);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "startx", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_DOUBLE, &startx[0]);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "dx", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_DOUBLE, &dx[0]);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "a", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_DOUBLE, &a);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "gam", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_DOUBLE, &gam);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "Rin", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_DOUBLE, &Rin);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "Rout", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_DOUBLE, &Rout);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "hslope", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_DOUBLE, &hslope);
	ret = H5Aclose(attr_id);

	attr_id = H5Aopen(file_id, "R0", H5P_DEFAULT);
	ret  = H5Aread(attr_id, H5T_NATIVE_DOUBLE, &R0);
	ret = H5Aclose(attr_id);

	printf("t: %g, N1: %d, N2: %d, N3: %d \n",t,N1,N2,N3);
	printf("startx: %g %g %g \n", startx[0],startx[1],startx[2]);
	printf("dx: %g %g %g \n", dx[0],dx[1],dx[2]);
	printf("a: %g, gam: %g, Rin: %g, Rout: %g, hslope: %g, R0: %g \n",a,gam,Rin,Rout,hslope,R0);

	x1    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	x2    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	x3    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	r     = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	h     = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	ph    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	RHO   = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	UU    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	U1    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	U2    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	U3    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	B1    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	B2    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	B3    = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	gdet  = (double *) malloc(N1*N2 * sizeof(double)); 
	Ucov0 = (double *) malloc(N1*N2*N3 * sizeof(double)); 
	Ucon0 = (double *) malloc(N1*N2*N3 * sizeof(double)); 

	dimsm[0] = N1*N2*N3;
	memspace = H5Screate_simple(RANK_OUT,dimsm,NULL);
	
	ds_id = H5Dopen(file_id, "x1", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &x1[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "x2", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &x2[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "x3", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &x3[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "r", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &r[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "h", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &h[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "ph", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &ph[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "RHO", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &RHO[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "UU", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &UU[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "U1", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &U1[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "U2", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &U2[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "U3", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &U3[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "B1", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &B1[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "B2", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &B2[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "B3", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &B3[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "Ucov0", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &Ucov0[0]);
	ret = H5Dclose(ds_id);

	ds_id = H5Dopen(file_id, "Ucon0", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &Ucon0[0]);
	ret = H5Dclose(ds_id);

    /* the memory space of "gdet" is 2D */
	dimsm[0] = N1*N2;
	memspace = H5Screate_simple(RANK_OUT,dimsm,NULL);

	ds_id = H5Dopen(file_id, "gdet", H5P_DEFAULT);
	dataspace = H5Dget_space(ds_id);    /* dataspace handle */
	ret = H5Dread(ds_id, H5T_NATIVE_DOUBLE, memspace, dataspace, H5P_DEFAULT, &gdet[0]);
	ret = H5Dclose(ds_id);

	ret = H5Fclose(file_id);
	
	for (i=0;i<N1;i++) for(j=0;j<N2;j++) for(z=0;z<N3;z++){
				gridIndex   = i*N2*N3 + j*N3 + z;
				gridIndex2D = i*N2 + j;
				printf("%d %d %d %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g %g \n",
						i,j,z,x1[gridIndex],x2[gridIndex],x3[gridIndex],
						r[gridIndex],h[gridIndex],ph[gridIndex],
						RHO[gridIndex],UU[gridIndex],U1[gridIndex],U2[gridIndex],U3[gridIndex],
						B1[gridIndex],B2[gridIndex],B3[gridIndex],gdet[gridIndex2D],
						Ucov0[gridIndex],Ucon0[gridIndex]); 
	}

	free(x1);
	free(x2);
	free(x3);
	free(r);
	free(h);
	free(ph);
	free(RHO);
	free(UU);
	free(U1);
	free(U2);
	free(U3);
	free(B1);
	free(B2);
	free(B3);
	free(gdet);
	free(Ucov0);
	free(Ucon0);
}

