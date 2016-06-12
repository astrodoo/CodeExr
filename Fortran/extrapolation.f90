PROGRAM extrapolation 
! 2012.04.20.
! exercise the extrapolation schecme (actually just being followed by
! interplation scheme from (Numerical Analysis, Brian Bradie, p363)
! also, exercise the array-based function

implicit none

real,dimension(4) :: x, y
real,dimension(4) :: ext_x
real,dimension(size(ext_x)) :: ext_y
integer :: ii
! setting parameters
ext_x(:) = (/(ii,ii=1,4)/)
x(:) = (/(ii,ii=5,8)/)
y(:) = x(:)**2. + 5.

write(*,*)'x :',x(:)
write(*,*)'y :',y(:)

! extrapolation by newton method
ext_y = extpol_nwt(x,y,ext_x)

write(*,*)'ext_x :',ext_x(:)
write(*,*)'ext_y :',ext_y(:)

! function of extrapolation
contains

function extpol_nwt(x0,fx0,xx)
implicit none

real,dimension(:),intent(in) :: x0,fx0,xx
real,dimension(size(xx)) :: extpol_nwt, term
real,dimension(size(x0)) :: x1,x2,fx
real,dimension(size(x0)) :: coeff
integer :: i,j,nx

nx = size(x0)

fx(:) = fx0(:)
x1(:) = x0(:)
x2(:) = x0(:)

coeff(1) = fx0(1)

! construct divided difference matrix
do i=2, nx 
  do j = 1, nx-i+1
    fx(j) = (fx(j+1) - fx(j)) / (x2(j+1) - x1(j))
    x2(j) = x2(j+1)
  enddo
  coeff(i) = fx(1)
enddo

! results = a0 + a1*(x-x0) + a2*(x-x0)(x-x1) + ... +an*(x-x0)(x-x1)...(x-x_(n-1))
! divded differences 
term(:) = 1.
extpol_nwt(:) = coeff(1)

do i=2, nx
   term(:) = term(:)*(xx(:) - x0(i-1))
   extpol_nwt(:) = extpol_nwt(:) + term(:)*coeff(i)
enddo

return
end FUNCTION extpol_nwt

end program
