public abstract class Pessoa implements Comparable<Pessoa> {
    // embora a especificação não pedisse, optei por tornar as variáveis idade e nome final
    // primeiro porque acho uma boa prática, e segundo porque meu vscode reclamou
    final private int idade;
    final private String nome;

    public Pessoa(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    // é abstrato porque cada tipo de pessoa tem um tipo de bilhete diferente
    public abstract Ticket getTicketType();

    public String getName() {
        return nome;
    }

    public int getAge() {
        return idade;
    }

    @Override
    public int compareTo(Pessoa person) {
        return Integer.compare(this.idade, person.idade);
    }

    // método toString para imprimir a pessoa e seu bilhete
    @Override
    public String toString() {
        return nome + ": " + idade + "[" + getTicketType() + "]";
    }
} 