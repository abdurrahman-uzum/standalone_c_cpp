
main.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
int main ( void )
{
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
		// see disassembly
	int a = 2;
   4:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [rbp-0x4],0x2
	int b = 3;
   b:	c7 45 f8 03 00 00 00 	mov    DWORD PTR [rbp-0x8],0x3
	int c = 0;
  12:	c7 45 f4 00 00 00 00 	mov    DWORD PTR [rbp-0xc],0x0

	_Bool result = 0;
  19:	c6 45 f3 00          	mov    BYTE PTR [rbp-0xd],0x0

	// equality
	result = a == a;
  1d:	c6 45 f3 01          	mov    BYTE PTR [rbp-0xd],0x1
	result = !( a != b );
  21:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  24:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
  27:	0f 94 c0             	sete   al
  2a:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al

	// inequality
	result = a != b;
  2d:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  30:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
  33:	0f 95 c0             	setne  al
  36:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al
	result = !( a == b );
  39:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  3c:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
  3f:	0f 95 c0             	setne  al
  42:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al

	// logical and
	result = ( a > b ) && ( b > c );
  45:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  48:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
  4b:	7e 0f                	jle    5c <main+0x5c>
  4d:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
  50:	3b 45 f4             	cmp    eax,DWORD PTR [rbp-0xc]
  53:	7e 07                	jle    5c <main+0x5c>
  55:	b8 01 00 00 00       	mov    eax,0x1
  5a:	eb 05                	jmp    61 <main+0x61>
  5c:	b8 00 00 00 00       	mov    eax,0x0
  61:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al
  64:	80 65 f3 01          	and    BYTE PTR [rbp-0xd],0x1

	// logical inclusive or
	result = ( a > b ) || ( b > c );
  68:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  6b:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
  6e:	7f 08                	jg     78 <main+0x78>
  70:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
  73:	3b 45 f4             	cmp    eax,DWORD PTR [rbp-0xc]
  76:	7e 07                	jle    7f <main+0x7f>
  78:	b8 01 00 00 00       	mov    eax,0x1
  7d:	eb 05                	jmp    84 <main+0x84>
  7f:	b8 00 00 00 00       	mov    eax,0x0
  84:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al
  87:	80 65 f3 01          	and    BYTE PTR [rbp-0xd],0x1

	// logical exclusive or (equivalent)
	result = ( a > b ) != ( b > c );
  8b:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  8e:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
  91:	0f 9f c2             	setg   dl
  94:	8b 45 f8             	mov    eax,DWORD PTR [rbp-0x8]
  97:	3b 45 f4             	cmp    eax,DWORD PTR [rbp-0xc]
  9a:	0f 9f c0             	setg   al
  9d:	31 d0                	xor    eax,edx
  9f:	0f b6 c0             	movzx  eax,al
  a2:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al
  a5:	80 65 f3 01          	and    BYTE PTR [rbp-0xd],0x1

	// bool normalized exclusive or (equivalent)
	result = !a != !c;
  a9:	83 7d fc 00          	cmp    DWORD PTR [rbp-0x4],0x0
  ad:	0f 94 c2             	sete   dl
  b0:	83 7d f4 00          	cmp    DWORD PTR [rbp-0xc],0x0
  b4:	0f 94 c0             	sete   al
  b7:	31 d0                	xor    eax,edx
  b9:	0f b6 c0             	movzx  eax,al
  bc:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al
  bf:	80 65 f3 01          	and    BYTE PTR [rbp-0xd],0x1
	result = (_Bool)a != (_Bool)c;
  c3:	83 7d fc 00          	cmp    DWORD PTR [rbp-0x4],0x0
  c7:	0f 95 c2             	setne  dl
  ca:	83 7d f4 00          	cmp    DWORD PTR [rbp-0xc],0x0
  ce:	0f 95 c0             	setne  al
  d1:	31 d0                	xor    eax,edx
  d3:	0f b6 c0             	movzx  eax,al
  d6:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al
  d9:	80 65 f3 01          	and    BYTE PTR [rbp-0xd],0x1

	result = a >= b;
  dd:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  e0:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
  e3:	0f 9d c0             	setge  al
  e6:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al
	result = !( a < b );
  e9:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  ec:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
  ef:	0f 9d c0             	setge  al
  f2:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al

	result = a < b;
  f5:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
  f8:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
  fb:	0f 9c c0             	setl   al
  fe:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al
	result = !( a >= b );
 101:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
 104:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
 107:	0f 9c c0             	setl   al
 10a:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al

	result = a <= b;
 10d:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
 110:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
 113:	0f 9e c0             	setle  al
 116:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al
	result = !( a > b );
 119:	8b 45 fc             	mov    eax,DWORD PTR [rbp-0x4]
 11c:	3b 45 f8             	cmp    eax,DWORD PTR [rbp-0x8]
 11f:	0f 9e c0             	setle  al
 122:	88 45 f3             	mov    BYTE PTR [rbp-0xd],al

	return 0;
 125:	b8 00 00 00 00       	mov    eax,0x0
 12a:	5d                   	pop    rbp
 12b:	c3                   	ret    
