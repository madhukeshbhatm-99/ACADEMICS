.model small
.data
 a dw 0010, 0100, 0200, 0300, 0700
 beg dw 0000
 en dw 0004
 key dw 0010
 msg1 db 'Key found$'
 msg2 db 'Key not found$'
.code
 mov ax, @data
 mov ds, ax
 mov bx, beg
 mov cx, en
 mov dx, key
 LOOP1: lea si, a
       mov ax, bx
       add ax, cx
       shr ax, 01
       add si, ax
       cmp [si], dx
       je EQUAL
       jbe BELOW
       dec ax
       mov cx, ax
       cmp bx, cx
       jbe LOOP1
       jmp EXIT
 BELOW: inc ax
        mov bx, ax
        cmp bx, cx
        jbe LOOP1
        jmp EXIT
 EQUAL: mov ah, 09h
        mov dx, offset msg1
        int 21h
        jmp FINISH
 EXIT: mov ah, 09h
       mov dx, offset msg2
       int 21h
 FINISH: mov ah, 4ch
         int 21h
end
