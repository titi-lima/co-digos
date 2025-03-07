public class Dragao extends Monstro implements Colorido {
    private Cores cor;
    final private double vidaBase;
    final private double poderDeAtaqueBase;

    public Dragao(int nivel) {
        super(nivel);
        this.vidaBase = 9999 + nivel/2.0;
        this.poderDeAtaqueBase = 999 * Math.sqrt(nivel);
        this.vida = vidaBase;
        this.poderDeAtaque = poderDeAtaqueBase;
    }

    @Override
    public void mordida(Dummy alvo) {
        alvo.setEstado("sangrando");
        this.estado = "atacando";
    }

    @Override
    public void arranhao(Dummy alvo) {
        alvo.setVida(alvo.getVida() - (50 * nivel));
        this.estado = "atacando";
    }

    @Override
    public void investida(Dummy alvo) {
        this.poderDeAtaque = Math.min(poderDeAtaqueBase * 1.5, poderDeAtaqueBase * (1 + (0.1 * 5)));
        this.estado = "atacando";
    }

    @Override
    public void azulado() {
        this.cor = Cores.AZUL;
        this.vida = vidaBase * 1.25;
    }

    @Override
    public void esverdeado() {
        this.cor = Cores.VERDE;
        this.poderDeAtaque = poderDeAtaqueBase * 1.2;
    }

    @Override
    public void amarelado() {
        this.cor = Cores.AMARELO;
    }

    @Override
    public void roxo() {
        this.cor = Cores.ROXO;
        this.vida = vidaBase * 1.5;
        this.poderDeAtaque = poderDeAtaqueBase * 1.5;
    }

    public boolean isAmarelo() {
        return cor == Cores.AMARELO;
    }
} 