public class Lobo extends Monstro implements Colorido {
    private Cores cor;
    final private double poderDeAtaqueBase;
    final private double vidaBase;

    public Lobo(int nivel) {
        super(nivel);
        this.vidaBase = 5000 + (nivel * nivel);
        this.poderDeAtaqueBase = 500 + nivel;
        this.vida = vidaBase;
        this.poderDeAtaque = poderDeAtaqueBase;
    }

    @Override
    public void mordida(Dummy alvo) {
        alvo.setEstado("aterrorizado");
        this.estado = "atacando";
    }

    @Override
    public void arranhao(Dummy alvo) {
        alvo.setVida(alvo.getVida() * 0.8);
        this.estado = "atacando";
    }

    @Override
    public void investida(Dummy alvo) {
        this.poderDeAtaque = Math.min(poderDeAtaqueBase * 2.0, poderDeAtaqueBase * (1 + (0.1 * 10)));
        this.estado = "atacando";
    }

    @Override
    public void azulado() {
        this.cor = Cores.AZUL;
    }

    @Override
    public void esverdeado() {
        this.cor = Cores.VERDE;
    }

    @Override
    public void amarelado() {
        this.cor = Cores.AMARELO;
    }

    @Override
    public void roxo() {
        this.cor = Cores.ROXO;
    }

    public boolean isAzul() {
        return this.cor == Cores.AZUL;
    }

    public boolean isVerde() {
        return this.cor == Cores.VERDE;
    }

    public boolean isAmarelo() {
        return this.cor == Cores.AMARELO;
    }

    public boolean isRoxo() {
        return this.cor == Cores.ROXO;
    }
} 