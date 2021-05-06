;search a number in a list and store index, FF otherwise

LXI H, 204FH
MOV C,M		;store count
MVI D, 01H  ;store index (1-BASED INDEX)

LDA 204EH
MOV B,A
DCR C

REPEAT: INX H
		MOV A,M
        CMP B
        JNZ NEXT
        ;if zero flag set, then no. found
        MOV A,D
        STA 204DH
        HLT
        
NEXT:	MVI A, FFH
		STA 204DH
        INR D
        DCR C
        JNZ REPEAT

HLT
        
        
		

	
		