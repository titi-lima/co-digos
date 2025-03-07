import java.util.ArrayList;
import java.util.List;

public class Cafeteria {
    //similarmente ao q1, optei por tornar a lista de produtos final por boa prática
    // e também porque meu vscode reclamou
    final private List<Produto> produtos;

    public Cafeteria() {
        this.produtos = new ArrayList<>();
    }

    public void adicionarProduto(Produto produto) {
        produtos.add(produto);
    }

    public Produto buscarProdutoPorNome(String nome) throws ProdutoNaoEncontradoException {
        return produtos.stream()
                .filter(p -> p.getNome().equals(nome))
                .findFirst()
                .orElseThrow(() -> new ProdutoNaoEncontradoException("Produto não encontrado: " + nome));
    }

    public void realizarVenda(String nomeProduto, int quantidade) throws ProdutoNaoEncontradoException, QuantidadeInvalidaException {
        if (quantidade <= 0) {
            throw new QuantidadeInvalidaException("Quantidade inválida: " + quantidade);
        }

        Produto produto = buscarProdutoPorNome(nomeProduto);
        
        if (produto.getEstoque() < quantidade) {
            throw new QuantidadeInvalidaException("Estoque insuficiente para a quantidade solicitada");
        }

        produto.setEstoque(produto.getEstoque() - quantidade);
        double valorTotal = produto.getPreco() * quantidade;
        
        System.out.printf("Venda realizada: %s - Quantidade: %d - Valor total: R$%.2f%n",
                produto.getNome(), quantidade, valorTotal);
    }
} 