;<sum of two nibbles of a byte stored in a register>

LDA 2500H
MOV B,A
ANI 0FH
MOV D,A

MOV A,B
ANI F0H
RLC
RLC
RLC
RLC
ADD D
STA 2550H

;10110111
;00001111

;00000111

;10110111
;11110000

;10110000


hlt