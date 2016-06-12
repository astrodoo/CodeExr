      program g77toidl
      implicit none
  
      integer i
      real    a(20)

      do i=1,20
        a(i)=i-1
        write(*,*) a(i)
      enddo
 
      open(unit=1,file='test_3.dat',form='unformatted')
      write(1) a
      close(unit=1)

      stop
      end
