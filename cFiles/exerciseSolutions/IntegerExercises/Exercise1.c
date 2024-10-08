#include <stdio.h>

main(){
    int a, b, c, d, e;

    printf("%d\n", a); // 0
    printf("%d\n", b); // 16
    printf("%d\n", c); // 0
    printf("%d\n", d); // 6951904
    printf("%d\n", e); // 0
}

/*  What is Undefined Behaviour?

    Mysteriously, the uninitialised variables hold some random values. 
    On my machine, they contain: 0, 16, 0, 6951904, 0.
    However, these values will be different on different machines! They will be different on your machine at a different time assuming you use it regularly. 

    This is called Undefined Behaviour. 
    One of the key themes of C is that it's a small language and it does not handle many things for you, including setting uninitialised variables to some default value (like 0).
    Because of this, the "random" values we're getting are what was stored in memory *before* we gave that memory to the variables. 
    Since we have no idea what this memory was, we have no idea what values we're going to get.

    Hence, these values are a result of Undefined Behaviour; it's unpredictable and dangerous. 

    In C, we have to be careful to avoid Undefined Behaviour occurring, and we'll see many examples in the course. 
*/
