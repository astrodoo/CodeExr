program test_hdf5

    use HDF5

    implicit none

    character(len=9), parameter :: fname = "test.hdf5"


    integer(HID_T) :: file_id       ! File identifier
    integer(HID_T) :: grp_grid_id,grp_data_id        ! Group identifier
    integer(HID_T) :: ds_rho_id,ds_x_id       ! Dataset identifier
    integer(HID_T) :: spc_id         ! Dataspace identifier
    integer(HID_T) :: att_global_id, att_rho0_id, att_file_id
!    integer(HID_T) :: mem_type         ! Dataspace identifier

    integer(HID_T) :: ftype_id !file type identifier

!    INTEGER(HID_T)  :: filetype, dset, grp_grid, grp_data, attr ! Handles

!    INTEGER(HSIZE_T)     ::   type_sizei  ! Size of the integer datatype
    integer(HSIZE_T), dimension(1) :: data_dims
    integer(HSIZE_T), dimension(1) :: dim_rho, max_dims
!    integer(HID_T) :: dt2_id

    integer(kind=4) :: glob
    real(kind=4),dimension(3) :: glob2
    real(kind=4)   :: rho0
    real(kind=4),dimension(:),allocatable   :: rho

    real(kind=4) :: att_file

!    integer(HSIZE_T), DIMENSION(2) :: dims = (/4,6/) ! Dataset dimensions
!    integer     ::   rank = 2                        ! Dataset rank

    integer     ::   hdferr ! Error flag

!    TYPE(C_PTR) :: f_ptr

    integer :: i

    character(len=9),dimension(2) :: var_names
 
    call h5open_f(hdferr)

    var_names = (/"global ","global2"/)
    write(*,*) var_names
!    CALL h5tget_size_f(H5T_NATIVE_INTEGER, type_sizei, hdferr)
!    CALL h5tcreate_f(H5T_COMPOUND_F, type_sizei, dt2_id, hdferr)

    call h5fopen_f(TRIM(fname),H5F_ACC_RDONLY_F,file_id,hdferr)
    call h5gopen_f(file_id, "grid", grp_grid_id, hdferr)
    call h5dopen_f(grp_grid_id, "x", ds_x_id, hdferr)

    call h5gopen_f(file_id, "data", grp_data_id, hdferr)
    data_dims(1) = 1
    ftype_id = H5T_NATIVE_INTEGER
!    call h5aopen_f(grp_data_id, "global", att_global_id, hdferr)
    call h5aopen_f(grp_data_id, trim(var_names(1)), att_global_id, hdferr)
    call h5aread_f(att_global_id,ftype_id,glob,data_dims, hdferr)
!   call h5aread_f(att_global_id,H5T_NATIVE_INTEGER,glob,data_dims, hdferr)
    data_dims(1) = 3
    ftype_id = H5T_NATIVE_REAL
!    call h5aopen_f(grp_data_id, "global2", att_global_id, hdferr)
    call h5aopen_f(grp_data_id, trim(var_names(2)), att_global_id, hdferr)
    call h5aread_f(att_global_id,ftype_id,glob2,data_dims, hdferr)
!   call h5aread_f(att_global_id,H5T_NATIVE_REAL,glob2,data_dims, hdferr)

    write(*,*) glob
    write(*,*) glob2
!    write(*,*) H5T_NATIVE_REAL, H5T_NATIVE_DOUBLE, H5T_NATIVE_INTEGER

    call h5dopen_f(grp_data_id, "rho", ds_rho_id, hdferr)

!Get dataspace ID
    CALL h5dget_space_f(ds_rho_id, spc_id,hdferr)
   !Get dataspace dims
    CALL h5sget_simple_extent_dims_f(spc_id,dim_rho, max_dims, hdferr)

!    write(*,*) dim_rho
    allocate(rho(dim_rho(1)))
    call h5dread_f(ds_rho_id,H5T_NATIVE_REAL,rho,dim_rho, hdferr)

    call h5aopen_f(ds_rho_id, "rho0", att_rho0_id, hdferr)
    call h5aread_f(att_rho0_id,H5T_NATIVE_REAL,rho0,data_dims, hdferr)

    call h5aopen_f(file_id, "file_attr", att_file_id, hdferr)
    call h5aread_f(att_file_id, H5T_NATIVE_REAL, att_file, data_dims, hdferr)

    write(*,*) rho0

    write(*,*) rho(:)
    write(*,*) att_file
    !do i = 1, dim_rho(2)
    !   write(*,*) rho(i,1)
    !enddo

    deallocate(rho)
    call H5aclose_f(att_rho0_id, hdferr)
    call H5aclose_f(att_global_id, hdferr)
    call H5dclose_f(ds_x_id, hdferr)
    call H5gclose_f(grp_grid_id, hdferr)
    call H5gclose_f(grp_data_id, hdferr)
    call H5Fclose_f(file_id, hdferr)


end program test_hdf5
