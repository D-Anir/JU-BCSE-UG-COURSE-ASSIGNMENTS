;sort in ascending / desccending order

START: MVI D, 00H	;flag for swapping
	LXI H, 204FH
    MOV B,M			;store count
    DCR B
    INX H
    
PREVIOUS: MOV A,M
		INX H
        CMP M
        ;JC NEXT	;ascending
        JNC NEXT	;descending
        MOV C,M	;swapping if carry is 0
        MOV M,A
        DCX H
        MOV M,C
        INX H
        INR D
        
NEXT: DCR B
	JNZ PREVIOUS
    
    MOV A,D
    CPI 00H
    JNZ START
HLT