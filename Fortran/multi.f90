PROGRAM multi
implicit none

real,dimension(4) :: x, y

x(:) = (/1,2,3,4/)
y(:) = (/3,4,5,6/)

write(*,*)'x :',x(:)
write(*,*)'y :',y(:)

write(*,*)'sum(x*y)',sum(x*y)

write(*,*)'dot_product(x,y)',dot_product(x,y)

end program
