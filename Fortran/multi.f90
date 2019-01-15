PROGRAM multi
implicit none

real,dimension(4) :: x, y
real,dimension(0:1) :: a
real,dimension(0:1,0:1) :: b

x(:) = (/1,2,3,4/)
y(:) = (/3,4,5,6/)

a(:) = (/1,2/)
b(:,0) = (/3,3/)
b(:,1) = (/3,3/)

write(*,*)'x :',x(:)
write(*,*)'y :',y(:)

! sum of vector
write(*,*)'sum(x*y)',sum(x*y)

! vector dot product
write(*,*)'dot_product(x,y)',dot_product(x,y)


write(*,*)'a :',a(:)
write(*,*)'b :',b(:,:)

! matrix multiplication
write(*,*)'matmul(b,a)',matmul(b,a)

end program
