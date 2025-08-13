<h1 align=center>
  Projeto de ED I: ERP
</h1>
<div>
  <h4>
    No projeto final de Estruturas de Dados I foi proposto a construção de um ERP no termianal,
    ou seja, tinhas que ter um "négocio" e manipular os dados com ações de adição, remoção e atualização
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
  utilizadas, deixando o código mais organizado e legível. O código fonte segue a mesma ordem das funções da biblioteca, o que também
  ajuda a localiza-lás de maneira fácil por se tratar de um código grande.
</h4>
<h2>
  Código
</h2>
<div display=flex>
  <img align=right width=150 src="https://media.tenor.com/tuQ0GK0BvbwAAAAi/racks-bills.gif">
  <h4 align=left>
    O código começa executando a <i>main</i>, onde são carregadas listas dinâmicas dos 3 elementos principais do négocio
    (clientes, produtos e vendas) a partir de funções chamadas <i>carregarElemento</i>. Essas funções, localizadas mais ao
    fim do código, realizam a leitura dos arquivos .txt que armazenam os respectivos dados
  </h4>
</div>

