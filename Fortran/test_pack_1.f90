PROGRAM test_pack_1
   INTEGER :: m(6)
   m = (/ 1, 0, 0, 0, 7, 0 /)
   WRITE(*, FMT="(6(I0, ' '))") pack(m, m == 7)  ! "1 5"
End program 
