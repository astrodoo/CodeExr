      program isNan

      implicit none

      real :: a(5,5)
      logical :: b(5,5)
      integer :: i,j

      do i=1,5
         do j=1,5
           a(i,j) = i
         enddo
      enddo 
      a(3,5) = -1

      write(*,*) a
      a = sqrt(a)
      write(*,*) a


      b = a.eq.a

      do i=1,5
         do j=1,5
            if (a(i,j) .ne. a(i,j)) write(*,*) 'hey!!!',i,j
         enddo
      enddo
c      write(*,*) b
c      if (b(i,j) .eqv. .false.) stop 'hey'

c      if (isNan(a)) stop '"a" is a NaN'

c      write(*,*) a

      stop
      end
