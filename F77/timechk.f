      Program timechk
      implicit none

      real(4) :: e,d,t(2)
      integer i,j,k,h

      e = etime(t)
      d = dtime(t)
      do i=1,1000
         do j=1,1000
            do k=1,1000
               h=h+1
            enddo
         enddo
      enddo
      e = etime(t)
      d = dtime(t)
      print *,"etime:", e,t(1),t(2)
      print *,"dtime:", d,t(1),t(2)
      do i=1,1000
         do j=1,1000
            do k=1,1000
               h=h+1
            enddo
         enddo
      enddo
      e = etime(t)
      d = dtime(t)
      print *,"etime:", e,t(1),t(2)
      print *,"dtime:", d,t(1),t(2)


      stop
      end
