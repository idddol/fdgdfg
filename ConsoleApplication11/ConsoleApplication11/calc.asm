.686P
.MODEL FLAT, C

.DATA

.CODE

calcSumm PROC C a:Byte, b: Byte
Xor     eax,eax
add     al, a
add     al, b
jnc     m1      ;���� ��� ��������, �� ������� �� m1
adc     ah,0    ;� ax ����� � ������ ��������
m1:
ret
calcSumm ENDP


End
