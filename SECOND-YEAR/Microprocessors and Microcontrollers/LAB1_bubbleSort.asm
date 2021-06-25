.model small
.data
 arr dw 1520h, 1A00h, 0B100h, 0FF14h, 0012h
.code
 mov ax, @data
 mov ds, ax
 mov dx, 05
 dec dx
 OUTER: lea SI, arr
 mov cx, dx
 INNER: mov ax, [SI]
 cmp ax, [SI+2]
 ja NEXT
 xchg ax, [SI+2]
 xchg ax, [SI]
 NEXT: inc SI
 inc SI
 dec cx
 jnz INNER
 dec dx
 jnz OUTER
 mov ah, 4ch
 int 21h
end

