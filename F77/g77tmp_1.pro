pro g77tmp_1

a = findgen(20) 

openw,lun1,'test_1.dat',/f77_unformatted,/get_lun
writeu,lun1,a
free_lun,lun1

stop
end
