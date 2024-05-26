
./test.o:     file format elf32-avr


Disassembly of section .text:

00000000 <main>:
int main ( void )
{
   0:	cf 93       	push	r28
   2:	df 93       	push	r29
   4:	cd b7       	in	r28, 0x3d	; 61
   6:	de b7       	in	r29, 0x3e	; 62
    return 0;
   8:	80 e0       	ldi	r24, 0x00	; 0
   a:	90 e0       	ldi	r25, 0x00	; 0
   c:	df 91       	pop	r29
   e:	cf 91       	pop	r28
  10:	08 95       	ret
