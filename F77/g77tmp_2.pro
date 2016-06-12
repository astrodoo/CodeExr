pro g77tmp_2

a = findgen(20) 

dummy = bytarr(8)
dummy[0] = 80
openw,lun1,'test_2.dat',/get_lun
writeu,lun1,dummy   ; for head
writeu,lun1,a
writeu,lun1,dummy   ; for tail
free_lun,lun1

stop
end
