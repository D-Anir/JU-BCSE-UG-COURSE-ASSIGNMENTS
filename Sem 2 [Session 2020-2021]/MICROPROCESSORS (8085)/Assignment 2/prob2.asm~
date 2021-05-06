;find max, min from an array of numbers

LXI H,204FH
MOV D,M	;store number of elements

LXI H,2050H
MOV B,M	;store maximum
MOV C,M	;store minimum

MAX: MOV A,M
	CMP B
    JC MIN
    MOV B,A

MIN: CMP C
	JNC SKIP
    MOV C,A
    
SKIP: INX H
	DCR D
    JNZ MAX
    
LXI H,2200H
MOV M,B

MOV A,C
STA 2202H

HLT
