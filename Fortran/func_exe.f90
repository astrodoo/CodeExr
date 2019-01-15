Module funcs
contains
!function f(x,a,narray)
function f(x)
    implicit none
    real(kind=8), intent(in) :: x
    !integer,intent(in) :: narray
    !real(kind=4),intent(in),dimension(0:narray-1) :: a

    real(kind=8) :: f

    f = x**2
    !write(*,*) a(0:1)

end function f

function f2(x)
    implicit none
    real(kind=8) :: f2
    real(kind=8), intent(in) :: x

    f2 = f(x)+2
end function f2

function f3(a,b,n)
    implicit none
    integer, intent(in) :: n
    real(kind=8),dimension(n,n),intent(in) :: a,b

    real(kind=8),dimension(n,n) :: f3
    integer :: i,j

    do i=1,n
        do j = 1,n
            f3(i,j) = a(i,j) + b(i,j)
        enddo
    enddo

end function f3
end Module

program func_exe
    use funcs
    implicit none
    real(kind=8) :: y,z
    !real(kind=8), external :: f
    real(kind=4),allocatable,dimension(:) :: a

    real(kind=8),dimension(0:1,0:1) :: aa, bb, cc
    integer :: i,j

    allocate(a(2))
    a = (/1.,2./)
    !a(3) = 3.
    !a(0) = 1.
    !a(1) = 2.
    y = 2.
    z = f2(y)
    !z = f(y,a,2)
    print *, "z = ",z
    write(*,*) a(1:2)
    deallocate(a)
    
    !matrix aa, bb
    data (aa(0,i), i=0,1) / 1.,2./
    data (aa(1,i), i=0,1) / 2.,3./
    data (bb(0,i), i=0,1) / 5.,6./
    data (bb(1,i), i=0,1) / 6.,8./

! print a header and the original matrix
  write(*,*) 'aa matrix'
  do i=0,1
     write (*,201) (aa(i,j),j=0,1)
  end do
  write(*,*) 'bb matrix'
  do i=0,1
     write (*,201) (bb(i,j),j=0,1)
  end do

  cc = f3(aa,bb,2)
 
  write(*,*) 'after f3 function: cc matrix'
! print the result of f3
  do i = 0,1
     write (*,201)  (cc(i,j),j=0,1)
  end do
201 format (2f12.6)


end program func_exe


