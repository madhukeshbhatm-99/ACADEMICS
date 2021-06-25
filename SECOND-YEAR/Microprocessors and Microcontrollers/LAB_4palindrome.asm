.model small
.data
 str1 db 'malayalam'
 len dw $-str1
 str2 db 9 dup('$')
 msg1 db 'Entered string is a palindrome$'
 msg2 db 'Entered string is not a palindrome$'
.code
 mov ax, @data
 mov ds, ax
 mov es, ax
 lea si, str1
 mov bx, len
 add si, bx
 dec bx
 std
 lea di, str2
 mov cx, len
 add di, cx
 loop1: movsb
        add di, 02
        loop loop1
 cld
 lea si, str1
 lea di, str2
 mov cx, len
 loop2: cmpsb
        jne loop3
        loop loop2
 mov dx, offset msg1
 mov ah, 09h
 int 21h
 jmp exit
 loop3: mov dx, offset msg2
        mov ah, 09h
        int 21h
 exit: mov ah, 4ch
       int 21h
end     
