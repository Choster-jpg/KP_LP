.586							; система команд (процессор Pentium)
.model flat, stdcall			; модель памяти, соглашение о вызовах
includelib kernel32.lib			; компановщику: компоновать с kernel32
includelib libucrt.lib			; для UCRT - universal C Run-Time library

ExitProcess PROTO: DWORD		; прототип функции для завершения процесса Windows

;-----------Standart functions-----------
includelib D:\Нада\ЯП\KP\StandartLibrary\Debug\StandartLibrary.lib
concat1 PROTO : DWORD, : DWORD
concat2 PROTO : DWORD, : DWORD, : DWORD
print PROTO : DWORD
printint PROTO : DWORD
isvisokosni PROTO : DWORD
printcurrentdate PROTO
;----------------------------------------

.stack 4096

;---------------Literals---------------
.const

L10	sdword	6	 ; integer literal
L12	sdword	12	 ; integer literal
L13	sdword	3	 ; integer literal
L14	sdword	12	 ; integer literal
L15	sdword	3	 ; integer literal
L16	sdword	12	 ; integer literal
L17	sdword	3	 ; integer literal
L28	sdword	0	 ; integer literal
L29	sdword	2	 ; integer literal
L30	sdword	1	 ; integer literal
L31	byte	"minimalnii element massiva", 0
L32	sdword	0	 ; integer literal
;--------------------------------------------


;----------------Variables-------------------
.data

x	sdword	0	 ; integer variable
y	sdword	0	 ; integer variable
z	sdword	0	 ; integer variable
k	sdword	0	 ; integer variable
m	sdword	0	 ; integer variable
sa	byte	255 dup(0)	 ; string variable
sb	byte	255 dup(0)	 ; string variable
sc	byte	255 dup(0)	 ; string variable
lf	sdword	0	 ; logic variable
rlt	sdword	0	 ; logic variable
hello	byte	255 dup(0)	 ; string variable
sadc	sdword	0	 ; integer variable
IntegerArray sdword 12, 3, 12, 3, 12, 3
IntegerArray sdword tmp1 byte 255 dup(0)
;--------------------------------------------

;----------------Functions-------------------

.code

main PROC

push L28
pop k
while_start: 
mov eax, L29
cmp eax, k
mov esi, k
mov eax, IntegerArray[4*esi]
cmp eax, m
jae condition_end
mov esi, k
push IntegerArray[4*esi]
pop m
condition_end: 
push k
push L30
pop eax
pop ebx
add eax, ebx
push eax
pop k
jmp while_start
while_end: 
push offset L31
call print
push m
call printint
mov eax, L32
	ret
invoke ExitProcess, 0
main ENDP
end main
;----------------------------------------------
