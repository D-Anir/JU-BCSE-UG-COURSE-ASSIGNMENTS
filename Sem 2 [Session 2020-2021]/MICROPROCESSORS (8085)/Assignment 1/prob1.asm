;<load, add and store contents of different registers>

LDA 2200H
MOV H,A
LDA 2201H
ADD H
MOV L,A
MVI A,00H
ADC A
MOV H,A
SHLD 2202H
hlt