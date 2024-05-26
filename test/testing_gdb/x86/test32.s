
test.o:     file format elf32-i386


Disassembly of section .text:

00000000 <main>:
int main ( void )
{
   0:	55                   	push   ebp
   1:	89 e5                	mov    ebp,esp
   3:	e8 fc ff ff ff       	call   4 <main+0x4>
   8:	05 01 00 00 00       	add    eax,0x1
    return 0;
   d:	b8 00 00 00 00       	mov    eax,0x0
  12:	5d                   	pop    ebp
  13:	c3                   	ret    

Disassembly of section .text.__x86.get_pc_thunk.ax:

00000000 <__x86.get_pc_thunk.ax>:
   0:	8b 04 24             	mov    eax,DWORD PTR [esp]
   3:	c3                   	ret    
