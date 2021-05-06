;count number of 1s ans 0s in a 8-bit number from a register

LDA 2500H
MVI D, 00H	;store count of 0s
MVI C, 08H

LOOP: RRC
	JC SKIP
    INR D
    
SKIP: DCR C
	JNZ LOOP
    
MOV A,D
STA 2511H	;store 0s count
MVI A, 08H
SUB D
STA 2610H	;store 1s count
hlt