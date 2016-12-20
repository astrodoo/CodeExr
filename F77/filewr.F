      program filewr

      implicit none

      real*8 :: a,b

      a=1.14143
      b=2345235

      open(unit=1,file='filewr.txt',status='unknown',access='append')

      write(1,11)'hey3',a,b

11    format(a8,2(2p,e16.6))
      close(1)

      stop
      end
