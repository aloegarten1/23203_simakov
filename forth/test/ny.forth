: pow over 1 swap rot 
    do
        over *
    loop
    swap
    drop
 
;

: ny25 45 2 pow . cr ;
: ny19
 0 10 0 do
    i 3 pow
    +
loop 
. cr
; 

3 2 pow . cr  
5 2 pow . cr  
7 4 pow . cr  

ny25
ny19