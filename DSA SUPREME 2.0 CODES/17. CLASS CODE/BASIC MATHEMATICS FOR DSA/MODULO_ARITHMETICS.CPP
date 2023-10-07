// CONCEPT 01: MODULO ARITHMETIC 

What is Modulo Arithmatic?
Generally, to avoid the overflow while storing integer we do modulo with a large number.


Range: (a % b) -> [0 to b-1]

How modulo is used: 
A few distributive properties of modulo are as follows: 
 
4. ( a + b) % M = ( ( a % M ) + ( b % M ) ) % M
5. ( a * b) % M = ( ( a % M ) * ( b % M ) ) % M
6. ( a – b) % M = ( ( a % M ) – ( b % M ) ) % M

So, modulo is distributive over +, * and – but not over /.
NOTE: The result of ( a % b ) will always be less than b.

In the case of computer programs, due to the size of variable limitations, 
we perform modulo M at each intermediate stage so that range overflow never occurs.