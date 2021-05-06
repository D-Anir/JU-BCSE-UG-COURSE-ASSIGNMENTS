;nth fibonacci

LXI H, 0000H ;initializing HL register
LDA 2060H	;loading N
CALL FIB	;calling function
SHLD 2050H	;storing Nh fibonacci
HLT


FIB: PUSH D
	PUSH PSW
    CPI 00H
    JNZ NEXT
    LXI H,0000H
    POP PSW
    POP D
    RET
    
NEXT: CPI 01H
	JNZ CONTINUE
    LXI H, 0001H
    POP PSW
    POP D
    RET
        
CONTINUE: DCR A
		CALL FIB
        XCHG
        DCR A
        CALL FIB
        DAD D
        POP PSW
        POP D
        RET
        
HLT