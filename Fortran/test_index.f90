program test_index

real, dimension(10) :: a
integer, dimension(10) :: i
integer, dimension(:), allocatable:: ind

a = (/1.,3.,5.,7.,9.,11.,13.,15.,17.,19./)
i = (/1,2,3,4,5,6,7,8,9,10/)

write(*,*) a

ind = pack(i, a==5.)

write(*,*) ind

deallocate(ind)

end program test_index
