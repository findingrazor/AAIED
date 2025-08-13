<h1 align=center>
  Projeto de ED I: ERP
</h1>
<div>
  <h4>
    No projeto final de Estruturas de Dados I foi proposto a construção de um ERP no termianal,
    ou seja, tinhamos que ter um "négocio" e manipular os dados com ações de adição, remoção e atualização
    dos cadastros realizados. No meu projeto tinhámos uma loja de CDs, então poderiamos realizar estas
    ações com clientes, produtos e vendas, além de listar e pesquisar tais elementos.
  </h4>
</div>
<h2>
  Divisão de Arquivos
</h2>
<h4>
  Existem 3 tipos de arquivos diferentes nesse projeto: O código fonte (.c), a biblioteca que criei (.h) e os
  arquivos de armazenamento de dados (.txt). Decidi salvá-los em .txt pois era a maneira mais simples de realizar 
  esse armazenamento externo e essa parte não era o foco do projeto, mas sim seu funcionamento na realização das ações.
  Nos arquivos de texto já existem alguns cadastros que podem ser carregados assim que o código for executado, para que tudo 
  possa ser testado sem a necessidade de realizar cadastros antes. A biblioteca contém todos os protótipos das funções e structs
  utilizadas, deixando o código mais organizado e legível. O código fonte segue a mesma ordem das funções da biblioteca, o que     
  também ajuda a localiza-lás de maneira fácil por se tratar de um código grande.
</h4>
<h2>
  Código
</h2>
<div display=flex>
  <img align=right width=150 src="https://media.tenor.com/tuQ0GK0BvbwAAAAi/racks-bills.gif">
  <h4 align=left>
    O código começa executando a <i>main</i>, onde são carregadas listas dinâmicas dos 3 elementos principais do négocio
    (clientes, produtos e vendas) a partir de funções chamadas <i>carregarElemento</i>. Essas funções, localizadas mais ao
    fim do código, realizam a leitura dos arquivos .txt que armazenam os respectivos dados. A função recebe como parâmetro o 
    nome do arquivo e então, usando uma estrutura de repetição para ler as linhas e gravar seus dados na lista que será utilizada
    no sistema. Existem algumas condições que garantem a leitura correta dos dados. 
  </h4>
</div>
<br>
<h4>
  Após isso, a função <i>menu</i> é chamada, passando como parâmetro as listas dos 3 elementos por referência, já que a intenção
  é manipular os dados presentes nos cadastros. Essa função, de forma básica, só direciona para os módulos de cada elemento onde
  há as chamadas para as funções de adição, alteração e exclusão de cadastros. Para que as ações ocorram, são feitas manipulações
  de "nós" em listas dinamicas duplamente encadeadas e utilização de aritmética de ponteiros. Dentro dos módulos há também a opção 
  de listagem dos elementos cadastrados. Nessa função, uma condição é aplicada para realizar a listagem que é mostrada
  visualmente e já apresenta alterações feitas durante a execução do código.
</h4>
<br>
<h4>
   Fora destes módulos há mais 2 opções: Buscar e Relatórios. A opção Buscar permite uma pesquisa específica de algum cadastro de um 
   elemento por ID e no caso das vendas por ID e nome de clientes ou produtos. Já a opção de relatório traz um resumo do sistema mostrando
   a quantidade de clientes e produtos cadastrados, número de vendas, total lucrado, entre outros.  
</h4>
<br>
<div display=flex>
  <img align=right width=130 src="https://media.tenor.com/l6BNQyeZ1e8AAAAi/bits-8bits.gif">
  <h4 align=left>
    Por fim, saindo da <i>menu</i>, chegamos nas função de <i>salvarElemento</i> e <i>liberarLista</i>. As funções de salvar coletam as 
    informações das listas e as escrevem nos arquivos utilizados para carregar as mesmas no início do código, para que na próxima execução
    do código as alterações feitas anteriormente seja salvas propriamente. Já as funções de liberar utilizam o <i>free</i> para desalocar da
    memória as listas dinâmicas, para não causar um overflow na memória da máquina, tornando o código seguro para execução.
  </h4>
</div>
<h2>
  Documentos
</h2>
<h4>Aqui foi disponibilizado o enunciado do projeto, caso o pedido não ficou claro para quem se interesse.</h4>
<h2>
  Conclusão
</h2>
<h4>Foi um código muito grande que me levou dias para ser feito mas me rendeu muito aprendizado na linguagem C e nas estruturas, porque
precisei usá-las diversas vezes além de ter que pesquisar por fora algumas informações para deixar o proejto o mais completo e 
funcional possível. Coloquei aqui no GitHub para deixar documentado e utilizar como portifólio.</h4>

