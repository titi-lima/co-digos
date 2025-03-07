public class Rato extends Monstro implements Colorido {
    private Cores cor;
    final private double poderDeAtaqueBase;
    final private double vidaBase;
    private boolean primeiroAtaque;

    public Rato(int nivel) {
        super(nivel);
        this.vidaBase = 1000 + nivel;
        this.poderDeAtaqueBase = 100 + (nivel * nivel);
        this.vida = vidaBase;
        this.poderDeAtaque = poderDeAtaqueBase;
        this.primeiroAtaque = true;
    }

    @Override
    public void mordida(Dummy alvo) {
        alvo.setEstado("envenenado");
        this.estado = "atacando";
    }

    @Override
    public void arranhao(Dummy alvo) {
        alvo.setVida(alvo.getVida() - (10 * nivel));
        this.estado = "atacando";
    }

    @Override
    public void investida(Dummy alvo) {
        this.poderDeAtaque = poderDeAtaqueBase * 2;
        this.estado = "atacando";
    }

    @Override
    public void azulado() {
        this.cor = Cores.AZUL;
        this.estado = "venenoso";
    }

    @Override
    public void esverdeado() {
        this.cor = Cores.VERDE;
        this.primeiroAtaque = true;
    }

    @Override
    public void amarelado() {
        this.cor = Cores.AMARELO;
        this.estado = "aterrorizante";
    }

    @Override
    public void roxo() {
        this.cor = Cores.ROXO;
    }

    public boolean isPrimeiroAtaque() {
        return primeiroAtaque;
    }

    public void setPrimeiroAtaque(boolean primeiroAtaque) {
        this.primeiroAtaque = primeiroAtaque;
    }

    public boolean isRoxo() {
        return this.cor == Cores.ROXO;
    }
} 