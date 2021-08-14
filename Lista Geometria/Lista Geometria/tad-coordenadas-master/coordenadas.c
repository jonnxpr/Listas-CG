#include "coordenadas.h"
#include <math.h>
#include <stdio.h>

/// multiplica um vetor por um escalar
/// este é um exemplo entregue pronto pra você ;)
vetor multiplicaPorEscalar(vetor v, escalar alpha)
{
    vetor resultado =
    {
        v.x * alpha,
        v.y * alpha,
        v.z * alpha,
        v.w * alpha
    };
    return resultado;
}

vetor somaVetorComVetor(vetor v, vetor u)
{
    //TODO: implementar
    v.x = v.x + u.x;
    v.y = v.y + u.y;
    v.z = v.z + u.z;
    v.w = v.w + u.w;

    vetor resultado = v;
    return resultado;
}

vetor diferencaVetorComVetor(vetor v, vetor u)
{
    //TODO: implementar
    v.x = v.x - u.x;
    v.y = v.y - u.y;
    v.z = v.z - u.z;
    v.w = v.w - u.w;

    vetor resultado = v;
    return resultado;
}

vetor diferencaEntrePontos(ponto p, ponto q)
{
    //TODO: implementar
    vetor resultado = {p.x - q.x, p.y - q.y, p.z - q.z, p.w - q.w};
    return resultado;
}

ponto somaPontoComVetor(ponto p, vetor v)
{
    //TODO: implementar
    p.x = p.x + v.x;
    p.y = p.y + v.y;
    p.z = p.z + v.z;
    p.w = p.w + v.w;

    ponto resultado = p;
    return resultado;
}

escalar normaDoVetor(vetor v)
{
    //TODO: implementar

    escalar resultado = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
    return resultado;
}

vetor normalizado(vetor v)
{
    //TODO: implementar
    vetor resultado = {v.x/normaDoVetor(v), v.y/normaDoVetor(v), v.z/normaDoVetor(v), v.w/normaDoVetor(v)};
    return resultado;
}

escalar distanciaEntrePontos(ponto p, ponto q)
{
    //TODO: implementar
    escalar resultado = sqrt(pow(q.x - p.x, 2) + pow(q.y - p.y, 2) + pow(q.z - p.z, 2));
    return resultado;
}

escalar produtoEscalar(vetor v, vetor u)
{
    //TODO: implementar
    escalar resultado = v.x*u.x + v.y*u.y + v.z*u.z + v.w*u.w;
    return resultado;
}

vetor produtoVetorial(vetor v, vetor u)
{
    //TODO: implementar
    // Produto vetorial só faz sentido em 3D
    // Ignorar a componente "w" de "v" e "u"
    // Como o resultado é um vetor, o "w" dele deve ser 0
    double aux1, aux2, aux3;

    aux1 = v.y*u.z - v.z*u.y;
    aux2 = u.x*v.z - u.z*v.x;
    aux3 = v.x*u.y - v.y*u.x;

    v.x = aux1;
    v.y = aux2;
    v.z = aux3;
    vetor resultado = v;
    return resultado;
}

///
/// Referências: http://localhost:8080/classes/geometry/#30
escalar anguloEntreVetores(vetor v, vetor u)
{
    //TODO: implementar
    escalar resultado = acos(produtoEscalar(v, u)/(normaDoVetor(v)*normaDoVetor(u)));
    return resultado;
}

///
/// Referências: http://localhost:8080/classes/geometry/#22
ponto combinacaoAfim2Pontos(ponto p, ponto q, escalar alpha)
{
    //TODO: implementar
    p.x = (1 - alpha)*p.x + alpha*q.x;
    p.y = (1 - alpha)*p.y + alpha*q.y;
    p.z = (1 - alpha)*p.z + alpha*q.z;
    p.w = (1 - alpha)*p.w + alpha*q.w;

    ponto resultado = p;
    return resultado;
}

/// Imprime um vetor ou ponto no terminal
/// Uso:
///   vetor r = somaVetorComVetor(a, b);
///   imprime("vetor r", r);
void imprime(struct coordenadas c, char* nome)
{
    printf("%s = { %.2f, %.2f, %.2f, %.2f }\n", nome, c.x, c.y, c.z, c.w);
}
