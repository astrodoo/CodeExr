      program bnrwr

      implicit none

      real*8 :: a,b
      real*4 :: c,d,e

      open(unit=4,file='bnrwr',status='old',form='unformatted')

      read(4) a,b,c,d,e

      write(*,*) a
      write(*,*) b
      write(*,*) c
      write(*,*) d
      write(*,*) e
      stop
      end
