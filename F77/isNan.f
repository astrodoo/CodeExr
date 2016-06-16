      program isNan

      implicit none

      real :: a(10)
      logical :: b(10)
      integer :: i

      do i=1,10
         a(i) = i
      enddo 
      a(1) = -1

      write(*,*) a
      a = sqrt(a)
      write(*,*) a


      b = a.eq.a
      write(*,*) b

c      if (isnan(a)) stop '"a" is a NaN'

c      write(*,*) a

      stop
      end
