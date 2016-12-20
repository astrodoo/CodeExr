      program bnrwr

      implicit none

      real*8 :: a,b
      real*4 :: c,d,e

      open(unit=4,file='bnrwr',status='unknown',form='unformatted')

      a = 3.2134234523d-20
      b = 3.2134234523d-15
      c = 3.2134234523e-13
      d = 3.2134234523e-11
      e = 3.2134234523e20


      write(4) a,b,c,d,e

      stop
      end
