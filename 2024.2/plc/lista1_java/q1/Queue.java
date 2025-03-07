import java.util.ArrayList;
import java.util.Collections;

/**
 * Classe que representa uma fila de pessoas.
 * @param <T> Tipo da pessoa na fila
 */
public class Queue<T extends Pessoa> {
    private ArrayList<T> pessoas;

    public Queue(int capacidade) {
        this.pessoas = new ArrayList<>(capacidade);
    }

    public Queue() {
        this(10);
    }

    public void push(T pessoa) {
        pessoas.add(pessoa);
        // tipo uma priority queue
        Collections.sort(pessoas, Collections.reverseOrder());
    }

    public T pop() {
        if (isEmpty()) {
            return null;
        }
        return pessoas.remove(0);
    }

    public boolean isEmpty() {
        return pessoas.isEmpty();
    }
} 