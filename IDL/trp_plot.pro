pro trp_plot, alpha=alpha, ps=ps

; draw transparent patch on tv images

if not keyword_set(alpha) then alpha=0.2
if keyword_set(ps) then win_opt = ',/pixmap' else win_opt=''

a=dist(500,500)

loadct,0,/sil

strexe = execute('window,0,xs=500,ys=500'+win_opt)
tvscl,a

win1=tvrd(true=3)

strexe = execute('window,1,xs=500,ys=500'+win_opt)
tvscl,a

tvlct,r,g,b,/get
polyfill,[100,400,400,100,100],[100,100,200,200,100],/dev,color=fsc_color('magenta')
tvlct,r,g,b
win2=tvrd(true=3)

win3 = alpha*win2 + (1.-alpha)*win1

if keyword_set(ps) then mkeps,'trp_plot',xs=20.,ys=20. $
  else window,2,xs=500,ys=500

tv,win3,true=3

if keyword_set(ps) then epsfree
stop
end

;====================================================================================
pro trp_plot2, alpha=alpha, ps=ps

; draw transparent patch on plot images

if not keyword_set(alpha) then alpha=0.2

x=findgen(100)
y=x^2.


loadct,0,/sil

if keyword_set(ps) then mkeps,'trp_plot2',xs=20.,ys=20.*6./8. $
 else begin
   !p.background=255 & !p.color=0
   window,0
endelse

plot,x,y,/nodata

tvlct,r,g,b,/get
polyfill,[30,80,80,30,30],[2000,2000,4000,4000,2000],/data,color=trp_color(fsc_color('magenta'),alpha=alpha,/whitebg)
tvlct,r,g,b

plot,x,y,/noerase

if keyword_set(ps) then epsfree
stop
end


;=====================================================================================
pro trp_plot3, alpha=alpha, ps=ps

; draw transparent patch on contour images

if not keyword_set(alpha) then alpha=0.2
if keyword_set(ps) then win_opt = ',/pixmap' else win_opt=''

a=dist(500,500)
x = findgen(500)/100.
y = findgen(500)/100.

levs = findgen(256)/256.*(max(a)-min(a))+min(a)

loadct,0,/sil
!p.background=255 & !p.color=0
strexe = execute('window,0,xs=500,ys=500'+win_opt)

if not keyword_set(ps) then $
  contour,a,x,y,levels=levs,/fill,/iso,xtitle='x', ytitle='y',/xst,/yst $
 else $
  tvcoord,bytscl(a,min=min(a),max=max(a)),x,y,/scale

win1 = tvrd(/true)

strexe = execute('window,1,xs=500,ys=500'+win_opt)

if not keyword_set(ps) then $
  contour,a,x,y,levels=levs,/fill,/iso,xtitle='x', ytitle='y',/xst,/yst $
 else $
  tvcoord,bytscl(a,min=min(a),max=max(a)),x,y,/scale

tvlct,r,g,b,/get
polyfill,[1,4,4,1,1],[1,1,3,3,1],/data,color=fsc_color('magenta')
tvlct,r,g,b

win2 = tvrd(/true)

win3 = alpha*win2 + (1.-alpha)*win1


if keyword_set(ps) then begin
  px=20. & py=20.

  figx0=0.1 & figdx=0.85
  figy0=0.1 & figdy=0.85

  mkeps,'trp_plot3',xs=px,ys=py 
;  plot,x,y,xra=[min(x),max(y)],yra=[min(x),max(y)],/xst,/yst,/nodata,position=[figx0,figy0,figx0+figdx,figy0+figdy],/iso
  
;  tv,win3,/true,figx0*px,figy0*py,/centimeter,xsize=figdx*px,ysize=figdy*py
;  plot,x,y,xra=[min(x),max(y)],yra=[min(x),max(y)],/xst,/yst,/nodata,position=[figx0,figy0,figx0+figdx,figy0+figdy],/iso,/noerase,xtitle='x',ytitle='y'

   tvcoord,win3,x,y,/true,/axes,position=[figx0,figy0],psx=figdx
endif else begin
   window,2,xs=500,ys=500

   tv,win3,/true
endelse

if keyword_set(ps) then epsfree

stop
end
