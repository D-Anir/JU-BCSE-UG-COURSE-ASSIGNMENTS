;count and store even/odd numbers from a list

LDA 204FH
MOV C,A		;store total count of numbers
MVI B,00H

LXI H,2050H	;store starting address of list
LXI D,2200H	;store the odd number list

START1: MOV A,M
	ANI 01H
    JZ EVEN
    ;else odd
    MOV A,M
    STAX D
    INX D
    INR B
    
EVEN: INX H
	DCR C
	JNZ START1
    
LDA 204FH
MOV C,A		;store total count of numbers

LXI H,2050H	;store starting address of list
LXI D,2100H	;store the even number list

START2: MOV A,M
	ANI 01H
    JNZ ODD
    ;else even
    MOV A,M
    STAX D
    INX D    
    
ODD: INX H
	DCR C
	JNZ START2

MOV A,B
STA 2301H	;ODD COUNT
LDA 204FH
SUB B
STA 2300H	;EVEN COUNT

HLT