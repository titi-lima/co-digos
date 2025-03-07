public class Main {
    public static void main(String[] args) {
        Queue<Pessoa> fila = new Queue<>();

        // Adding people to the queue
        fila.push(new Crianca("Child 1", 5));
        fila.push(new Adulto("Adult 1", 30));
        fila.push(new Crianca("Child 2", 6));
        fila.push(new Adulto("Adult 2", 20));
        fila.push(new Crianca("Child 3", 8));

        System.out.println("Ordem da fila (mais velhos primeiro):");
        while (!fila.isEmpty()) {
            Pessoa pessoa = fila.pop();
            System.out.println(pessoa);
        }
    }
} 