Você deve escrever duas funções em C. Ambas devem receber como parâmetros um vetor V de inteiros e o tamanho do vetor, e retornar um valor do tipo double. A primeira função, denominada "media()" deve retornar a média aritmética dos valores do vetor. Ex: se V = [9,8,6,4], o resultado deve ser 6.75. A segunda função, denominada "desvio_padrao()" deve calcular o desvio padrão do vetor. Para o mesmo exemplo, o desvio padrão calculado deve ser 1.92. 

Detalhes sobre a implementação:

    O tamanho do vetor V deverá ser fornecido na linha de comando (utilize os argumentos da função main() para isso);
    O vetor V deve ser alocado dinamicamente no código (utilize as funções malloc() e free())
    O vetor V deve ser inicializado com valores aleatórios (pesquise as funções srand() e rand() pra isso)
    Assuma a fórmula de desvio padrão populacional para cálculo do desvio padrão (pesquise as funções sqrt() e pow() da biblioteca math.h para uso no cálculo). Para isso, não esqueça de adicionar a opção -lm no momento da compilação.
    As funções "media()" e "desvio_padrao()" devem ser chamadas dentro da função main(). A média e desvio padrão calculados, assim como o conteúdo do vetor V, devem ser impressos na tela ao final da execução.
