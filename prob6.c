#include "chess.h"
#include "figures.h"

void display() {
    char **cuadroNegro = reverse(whiteSquare);
    char **cuadroBlanco = whiteSquare;
    char **unionCuadrados = join(cuadroNegro, cuadroBlanco);
    char **filaCuadrosParaFichas = up(repeatH(unionCuadrados, 4),repeatH(reverse(unionCuadrados),4));

    char **torreCaballoAlfilIzquierdo = join(join(rook, knight), bishop);
    char **reyYreyna = join(queen, king);
    char **torreCaballoAlfilDerecho = join(join(bishop, knight), rook);
    char **filaFichasPrincipales = join(join(torreCaballoAlfilIzquierdo, reyYreyna), torreCaballoAlfilDerecho);
    
    char **filaFichasUnidasBlancasConPeones = superImpose(up(filaFichasPrincipales, repeatH(pawn, 8)), filaCuadrosParaFichas);
    char **fichasBlancasMitadTablero = up(filaFichasUnidasBlancasConPeones, repeatV(filaCuadrosParaFichas, 2));

    char **filasFichasNegras = up(repeatH(pawn, 8), filaFichasPrincipales);
    char **filaFichasUnidasNegras = superImpose(reverse(filasFichasNegras), filaCuadrosParaFichas);

    char **tableroUnido = up(fichasBlancasMitadTablero, filaFichasUnidasNegras);

    interpreter(tableroUnido);
}