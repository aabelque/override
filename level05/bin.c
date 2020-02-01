int	main()
{
	char	buf[100]; // esp+0x28
	int	x; // esp+0x8c

	x = 0;
	fgets(buf, 100, stdin);
	x = 0;

	
   <+65>:    jmp    0x80484d3 <main+143>

   <+67>:    lea    eax,[esp+0x28]
   <+71>:    add    eax,DWORD PTR [esp+0x8c]
   <+78>:    movzx  eax,BYTE PTR [eax]
   <+81>:    cmp    al,0x40
   <+83>:    jle    0x80484cb <main+135>
   <+85>:    lea    eax,[esp+0x28]
   <+89>:    add    eax,DWORD PTR [esp+0x8c]
   <+96>:    movzx  eax,BYTE PTR [eax]
   <+99>:    cmp    al,0x5a
   <+101>:   jg     0x80484cb <main+135>
   <+103>:   lea    eax,[esp+0x28]
   <+107>:   add    eax,DWORD PTR [esp+0x8c]
   <+114>:   movzx  eax,BYTE PTR [eax]
   <+117>:   mov    edx,eax
   <+119>:   xor    edx,0x20
   <+122>:   lea    eax,[esp+0x28]
   <+126>:   add    eax,DWORD PTR [esp+0x8c]
   <+133>:   mov    BYTE PTR [eax],dl
   <+135>:   add    DWORD PTR [esp+0x8c],0x1

   <+143>:   mov    ebx,DWORD PTR [esp+0x8c]
   <+150>:   lea    eax,[esp+0x28]
   <+154>:   mov    DWORD PTR [esp+0x1c],0xffffffff
   <+162>:   mov    edx,eax
   <+164>:   mov    eax,0x0
   <+169>:   mov    ecx,DWORD PTR [esp+0x1c]
   <+173>:   mov    edi,edx
   <+175>:   repnz scas al,BYTE PTR es:[edi]
   <+177>:   mov    eax,ecx
   <+179>:   not    eax
   <+181>:   sub    eax,0x1
   <+184>:   cmp    ebx,eax
   <+186>:   jb     0x8048487 <main+67>

   <+188>:   lea    eax,[esp+0x28]
   <+192>:   mov    DWORD PTR [esp],eax
   <+195>:   call   0x8048340 <printf@plt>

   <+200>:   mov    DWORD PTR [esp],0x0
   <+207>:   call   0x8048370 <exit@plt>
}
