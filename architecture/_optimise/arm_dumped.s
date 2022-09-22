
main.o:     file format elf32-littlearm


Disassembly of section .text.foo:

00000000 <foo>:
int  foo ( int b )
{
   0:	4602      	mov	r2, r0
    int a = 0;

    for ( int i = 0; i < b; i++ )
   2:	2300      	movs	r3, #0
    int a = 0;
   4:	4618      	mov	r0, r3
    for ( int i = 0; i < b; i++ )
   6:	e001      	b.n	c <foo+0xc>
    {
        a++;
   8:	3001      	adds	r0, #1
    for ( int i = 0; i < b; i++ )
   a:	3301      	adds	r3, #1
   c:	4293      	cmp	r3, r2
   e:	dbfb      	blt.n	8 <foo+0x8>
    }

    return a;
  10:	4770      	bx	lr
