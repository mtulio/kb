//binario e octal

void numeroNatural::binario(unsigned long N))const { 
     int bin, /* numero dado convertido para base 2 */ aux, /* auxiliar */ dig, /* guardara cada um dos digitos binarios */ pot; /* potencia de 10 */ /* inicializacoes */ 
     aux = N; 
     bin = 0; 
     pot = 1; 
     while (aux > 0) { 
           dig = aux % 2; /* proximo digito binario menos significativo */ 
           aux = aux / 2; /* remove esse digito do que resta */ 
           bin = bin + dig * pot; /* adiciona o digito como o mais significativo */ 
           pot = pot * 10; 
           } 
           return(bin); 
}
void numeroNatural::octodecimal(unsigned long N))const 
{ 
     int oct, /* numero dado convertido para base 2 */ aux, /* auxiliar */ dig, /* guardara cada um dos digitos binarios */ pot; /* potencia de 10 */ /* inicializacoes */ 
     aux = N; 
     oct = 0; 
     pot = 1; 
     while (aux > 0) { 
           dig = aux % 8; /* proximo digito binario menos significativo */ 
           aux = aux / 8; /* remove esse digito do que resta */ 
           oct = oct + dig * pot; /* adiciona o digito como o mais significativo */ 
           pot = pot * 10; 
     } 
     return(oct); 
     } 
