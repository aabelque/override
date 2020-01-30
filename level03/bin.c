void	decrypt(int x)
{
   <+0>:     push   ebp
   <+1>:     mov    ebp,esp
   <+3>:     push   edi
   <+4>:     push   esi
   <+5>:     sub    esp,0x40
   <+8>:     mov    eax,gs:0x14
   <+14>:    mov    DWORD PTR [ebp-0xc],eax
   <+17>:    xor    eax,eax
   <+19>:    mov    DWORD PTR [ebp-0x1d],0x757c7d51
   <+26>:    mov    DWORD PTR [ebp-0x19],0x67667360
   <+33>:    mov    DWORD PTR [ebp-0x15],0x7b66737e
   <+40>:    mov    DWORD PTR [ebp-0x11],0x33617c7d
   <+47>:    mov    BYTE PTR [ebp-0xd],0x0
   <+51>:    push   eax
   <+52>:    xor    eax,eax
   <+54>:    je     0x804869b <decrypt+59>
   <+56>:    add    esp,0x4
   <+59>:    pop    eax
   <+60>:    lea    eax,[ebp-0x1d]
   <+63>:    mov    DWORD PTR [ebp-0x2c],0xffffffff
   <+70>:    mov    edx,eax
   <+72>:    mov    eax,0x0
   <+77>:    mov    ecx,DWORD PTR [ebp-0x2c]
   <+80>:    mov    edi,edx
   <+82>:    repnz scas al,BYTE PTR es:[edi]
   <+84>:    mov    eax,ecx
   <+86>:    not    eax
   <+88>:    sub    eax,0x1
   <+91>:    mov    DWORD PTR [ebp-0x24],eax

   int i = 0;
   while (i < ebp-0x24) {
   	<+103>:   lea    eax,[ebp-0x1d]
   	<+106>:   add    eax,DWORD PTR [ebp-0x28]
   	<+109>:   movzx  eax,BYTE PTR [eax]
   	<+112>:   mov    edx,eax
   	<+114>:   mov    eax,DWORD PTR [ebp+0x8]
   	<+117>:   xor    eax,edx
   	<+119>:   mov    edx,eax
   	<+121>:   lea    eax,[ebp-0x1d]
   	<+124>:   add    eax,DWORD PTR [ebp-0x28]
   	<+127>:   mov    BYTE PTR [eax],dl
   	<+129>:   add    DWORD PTR [ebp-0x28],0x1
   	i++;
   }

   <+141>:   lea    eax,[ebp-0x1d]
   <+144>:   mov    edx,eax
   <+146>:   mov    eax,0x80489c3
   <+151>:   mov    ecx,0x11
   <+156>:   mov    esi,edx
   <+158>:   mov    edi,eax
   <+160>:   repz cmps BYTE PTR ds:[esi],BYTE PTR es:[edi]
   <+162>:   seta   dl
   <+165>:   setb   al
   <+168>:   mov    ecx,edx
   <+170>:   sub    cl,al
   <+172>:   mov    eax,ecx
   <+174>:   movsx  eax,al

   if (test eax, eax equal) {
	   system("/bin/sh");
   } else {
	   puts("\nInvalid Password");
   }
   return;
}

void	test(int a, int b)
{
   <+0>:     push   ebp
   <+1>:     mov    ebp,esp
   <+3>:     sub    esp,0x28

   <+6>:     mov    eax,DWORD PTR [ebp+0x8]
   <+9>:     mov    edx,DWORD PTR [ebp+0xc]
   <+12>:    mov    ecx,edx
   <+14>:    sub    ecx,eax
   <+16>:    mov    eax,ecx
   <+18>:    mov    DWORD PTR [ebp-0xc],eax
   <+21>:    cmp    DWORD PTR [ebp-0xc],0x15
   <+25>:    ja     0x804884a <test+259>

   <+31>:    mov    eax,DWORD PTR [ebp-0xc]
   <+34>:    shl    eax,0x2
   <+37>:    add    eax,0x80489f0
   <+42>:    mov    eax,DWORD PTR [eax]
   <+44>:    jmp    eax

   <+46>:    mov    eax,DWORD PTR [ebp-0xc]
   <+49>:    mov    DWORD PTR [esp],eax
   <+52>:    call   0x8048660 <decrypt>
   <+57>:    jmp    0x8048858 <test+273>

   <+62>:    mov    eax,DWORD PTR [ebp-0xc]
   <+65>:    mov    DWORD PTR [esp],eax
   <+68>:    call   0x8048660 <decrypt>
   <+73>:    jmp    0x8048858 <test+273>

   <+78>:    mov    eax,DWORD PTR [ebp-0xc]
   <+81>:    mov    DWORD PTR [esp],eax
   <+84>:    call   0x8048660 <decrypt>
   <+89>:    jmp    0x8048858 <test+273>

   <+94>:    mov    eax,DWORD PTR [ebp-0xc]
   <+97>:    mov    DWORD PTR [esp],eax
   <+100>:   call   0x8048660 <decrypt>
   <+105>:   jmp    0x8048858 <test+273>

   <+110>:   mov    eax,DWORD PTR [ebp-0xc]
   <+113>:   mov    DWORD PTR [esp],eax
   <+116>:   call   0x8048660 <decrypt>
   <+121>:   jmp    0x8048858 <test+273>

   <+126>:   mov    eax,DWORD PTR [ebp-0xc]
   <+129>:   mov    DWORD PTR [esp],eax
   <+132>:   call   0x8048660 <decrypt>
   <+137>:   jmp    0x8048858 <test+273>

   <+142>:   mov    eax,DWORD PTR [ebp-0xc]
   <+145>:   mov    DWORD PTR [esp],eax
   <+148>:   call   0x8048660 <decrypt>
   <+153>:   jmp    0x8048858 <test+273>

   <+155>:   mov    eax,DWORD PTR [ebp-0xc]
   <+158>:   mov    DWORD PTR [esp],eax
   <+161>:   call   0x8048660 <decrypt>
   <+166>:   jmp    0x8048858 <test+273>

   <+168>:   mov    eax,DWORD PTR [ebp-0xc]
   <+171>:   mov    DWORD PTR [esp],eax
   <+174>:   call   0x8048660 <decrypt>
   <+179>:   jmp    0x8048858 <test+273>

   <+181>:   mov    eax,DWORD PTR [ebp-0xc]
   <+184>:   mov    DWORD PTR [esp],eax
   <+187>:   call   0x8048660 <decrypt>
   <+192>:   jmp    0x8048858 <test+273>

   <+194>:   mov    eax,DWORD PTR [ebp-0xc]
   <+197>:   mov    DWORD PTR [esp],eax
   <+200>:   call   0x8048660 <decrypt>
   <+205>:   jmp    0x8048858 <test+273>

   <+207>:   mov    eax,DWORD PTR [ebp-0xc]
   <+210>:   mov    DWORD PTR [esp],eax
   <+213>:   call   0x8048660 <decrypt>
   <+218>:   jmp    0x8048858 <test+273>

   <+220>:   mov    eax,DWORD PTR [ebp-0xc]
   <+223>:   mov    DWORD PTR [esp],eax
   <+226>:   call   0x8048660 <decrypt>
   <+231>:   jmp    0x8048858 <test+273>

   <+233>:   mov    eax,DWORD PTR [ebp-0xc]
   <+236>:   mov    DWORD PTR [esp],eax
   <+239>:   call   0x8048660 <decrypt>
   <+244>:   jmp    0x8048858 <test+273>

   <+246>:   mov    eax,DWORD PTR [ebp-0xc]
   <+249>:   mov    DWORD PTR [esp],eax
   <+252>:   call   0x8048660 <decrypt>
   <+257>:   jmp    0x8048858 <test+273>

   <+259>:   call   0x8048520 <rand@plt>
   <+264>:   mov    DWORD PTR [esp],eax
   <+267>:   call   0x8048660 <decrypt>

	return;
}

int	main()
{
	int	x;

	srand(time(0));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");

	scanf("%d", &x);
	test(x, 0x1337d00d);
}
