public class Adulto extends Pessoa {
    public Adulto(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public Ticket getTicketType() {
        return Ticket.ADULTO;
    }
} 