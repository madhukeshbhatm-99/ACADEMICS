.model small
.code

 mov cl, 00h
 mov ah, 00
 mov al, 03h
 int 10h

 mov bh, 00
 mov dh, 12
 mov dl, 40
 mov ah, 02h
 int 10h

 mov ah, 01h
 int 21h

 mov bl, al
 mov cl, 04
 and al, 0f0h
 shr al, cl
 add al, 30h

 mov ah, 02h
 mov dl, al
 int 21h

 and bl, 0fh
 cmp bl, 09h
 jbe a2

 mov dl, 0fh
 mov cl, 47h
 loop1: dec cl
        cmp bl, dl
        je chg
        dec dl
        jmp loop1
        chg: mov bl, cl
             jmp next

 a2: add bl, 30h

 next: mov ah, 02h
       mov dl, bl
       int 21h

 mov ah, 4ch
 int 21h
end
