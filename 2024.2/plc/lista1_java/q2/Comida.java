import java.util.List;

public class Comida extends Produto {
    private List<String> ingredientes;

    public Comida(int id, String nome, double preco, int estoque, List<String> ingredientes) {
        super(id, nome, preco, estoque);
        this.ingredientes = ingredientes;
    }

    public List<String> getIngredientes() {
        return ingredientes;
    }

    public void setIngredientes(List<String> ingredientes) {
        this.ingredientes = ingredientes;
    }

    @Override
    public String toString() {
        return super.toString() + ", ingredientes=" + ingredientes;
    }
} 