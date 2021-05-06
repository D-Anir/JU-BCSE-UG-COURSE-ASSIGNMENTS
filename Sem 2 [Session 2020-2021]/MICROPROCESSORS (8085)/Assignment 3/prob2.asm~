;to check LSB and MSB of each byte in a list of bytes

LDA 21FFH
MOV C,A		;load N to Accumulator

LXI H, 2200H	;load starting address

MVI B, 00H
MVI E, 00H

START: MOV A,M
	ANI 01H
    JNZ PROCEED	;D0 is 1
    INX H		;D0 is not 1
    DCR C
    JNZ START
    JMP FINAL
 
PROCEED: MOV A,M
		ANI 80H
        JNZ STORE	;D7 is 1
        INX H		;D7 is not 1
   		DCR C
    	JNZ START
        JMP FINAL

STORE: MOV A,M	;add the number
    ADD B
    JNC SKIP
    INR E

SKIP: MOV B,A
    INX H
    DCR C
    JNZ START
    
FINAL: LXI H, 2500H
	MOV M,B
	INX H
	MOV M,E
	HLT
    