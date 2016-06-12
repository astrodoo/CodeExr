       program g77tmp
       implicit none
   
       integer i
       real a(20)

c       open(unit=1,file='test_1.dat',form='unformatted')
       open(unit=1,file='test_2.dat',form='unformatted')

       read(1) a
       close(unit=1)

       do i=1,20 
       write(*,*) a(i)
       enddo

       stop
       end

