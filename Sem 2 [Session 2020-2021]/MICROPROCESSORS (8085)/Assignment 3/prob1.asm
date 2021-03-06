;to check LSB and MSB of each byte in a list of bytes

LDA 2500H
MOV C,A		;load N to Accumulator

LXI H, 2501H	;load starting address
LXI D, 2600H	;load destination address

START: MOV A,M
	ANI 01H
    JNZ STORE	;D0 is 1
    MOV A,M
    ANI 80H
    JNZ STORE	;D7 is 1
    INX H		;neither D0 nor D7 is 1
    DCR C
    JNZ START
    HLT
    
STORE: MOV A,M
	STAX D		;store at desired location
    INX D
    INX H
    DCR C
    JNZ START
    HLT
    