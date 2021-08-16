Module funcs
contains
function f(x,ain)
    implicit none
    real(kind=8), intent(in) :: x
    real(kind=8), intent(in), optional :: ain
    real(kind=8) :: f, a

    ! default value
    a = 100.

    ! updated by optional values
    if (present(ain)) a = ain

    write(*,*) 'a =', a
    f = x**2.5 + a
end function f

function f2(x,a)
    implicit none
    real(kind=8) :: f2
    real(kind=8), intent(in) :: x,a

    f2 = f(x,a)+2
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
    real(kind=8) :: y,z,a
    real(kind=8), dimension(10) :: kk
    character(len=3) :: str_kk

    do a=1,10
        kk(a) = a*20.
    enddo

    write(*,*) (int(kk(a)),a=1,10)

    write(str_kk,'(I3.3)') int(kk(1))
    write(*,*) 'hey_'//str_kk//'_print'

    a=10.

    y = 2.
    z = f(y, ain=5.d0)   ! type should be matched (e.g., here double precision)
    print *, "z(x=y, ain=5.d0) = ",z
    z = f(x=y)
    print *, "z(x=y) = ",z
    
end program func_exe


