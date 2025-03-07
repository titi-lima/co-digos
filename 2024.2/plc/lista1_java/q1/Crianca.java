public class Crianca extends Pessoa {
    public Crianca(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public Ticket getTicketType() {
        return Ticket.CRIANCA;
    }
} 