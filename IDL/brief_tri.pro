pro brief_tri

Again:

answer=''
read, answer, prompt='yes or no ? '

case answer of 
  'yes': a=1
  'no' : a=0
 else  : goto, Again
endcase

strOut = a ? 'You Select YES!' : 'You Select No!'

print,strOut

end
