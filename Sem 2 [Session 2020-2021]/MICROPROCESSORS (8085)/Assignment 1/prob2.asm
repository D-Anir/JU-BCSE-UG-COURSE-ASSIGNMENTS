;<add N consecutive numbers and store in registers>

LXI H, 2200H  ;store value of N
MOV C, M

LXI H, 2500H  ;store staring address
XRA A
MOV E,A

LOOP:ADD M
    JNC SKIP
    INR E

SKIP:DCR C
    INX H
    JNZ LOOP	

LXI H, 2300H
MOV M,A
INX H
MOV M,E

hlt