import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Cafeteria cafeteria = new Cafeteria();

        // Criando produtos
        Bebida cafe = new Bebida(1, "Café", 5.50, 10, 200);
        Bebida suco = new Bebida(2, "Suco de Laranja", 8.00, 5, 300);
        List<String> ingredientesBolo = Arrays.asList("Farinha", "Ovos", "Leite", "Chocolate");
        Comida bolo = new Comida(3, "Bolo de Chocolate", 15.00, 3, ingredientesBolo);

        // Adicionando produtos à cafeteria
        cafeteria.adicionarProduto(cafe);
        cafeteria.adicionarProduto(suco);
        cafeteria.adicionarProduto(bolo);

        // Teste 1: Venda válida
        try {
            cafeteria.realizarVenda("Café", 2);
        } catch (ProdutoNaoEncontradoException | QuantidadeInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
        }

        // Teste 2: Produto inexistente
        try {
            cafeteria.realizarVenda("Chá", 1);
        } catch (ProdutoNaoEncontradoException | QuantidadeInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
        }

        // Teste 3: Quantidade inválida
        try {
            cafeteria.realizarVenda("Suco de Laranja", 0);
        } catch (ProdutoNaoEncontradoException | QuantidadeInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
        }

        // Teste 4: Estoque insuficiente
        try {
            cafeteria.realizarVenda("Bolo de Chocolate", 5);
        } catch (ProdutoNaoEncontradoException | QuantidadeInvalidaException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}
