pro speedtestloop, narray=narray

resolve_routine,'tic',/compile_full_file

if not keyword_set(narray) then narray=100
array = fltarr(narray,narray,narray)

tic
for i=0,narray-1 do begin
    for j=0,narray-1 do begin
        for k=0,narray-1 do begin
            array[i,j,k] = i*j*k
        endfor
    endfor
endfor
toc,elapse=time1,/silent

tic
for k=0,narray-1 do begin
    for j=0,narray-1 do begin
        for i=0,narray-1 do begin
            array[i,j,k] = i*j*k
        endfor
    endfor
endfor
toc,elapse=time2,/silent

print,'elapsed time w/ ascent sequence  (for i,j,k in array[i,j,k]): ',time1
print,'elapsed time w/ descent sequence (for k,j,i in array[i,j,k]): ',time2

end
