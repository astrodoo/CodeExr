pro g77toidl

a = fltarr(20) 

dummy = bytarr(8)
openr,lun1,'test_3.dat',/get_lun
readu,lun1,dummy   ; for head
readu,lun1,a
readu,lun1,dummy   ; for tail
free_lun,lun1

forprint,a
stop
end
