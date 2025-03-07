public abstract class Monstro {
    protected double vida;
    protected String estado;
    protected double poderDeAtaque;
    protected int nivel;
    protected int turnosDecorridos;

    public Monstro(int nivel) {
        this.nivel = nivel;
        this.estado = "normal";
        this.turnosDecorridos = 0;
    }

    public boolean aindaVive() {
        return vida > 0;
    }

    public abstract void mordida(Dummy alvo);
    public abstract void arranhao(Dummy alvo);
    public abstract void investida(Dummy alvo);

    public void sangra() {
        this.estado = "sangramento";
    }

    public void aterroriza() {
        this.estado = "aterrorizante";
    }

    public void envenena() {
        this.estado = "venenoso";
    }

    public void incrementaTurno() {
        this.turnosDecorridos++;
    }

    public int getTurnosDecorridos() {
        return turnosDecorridos;
    }

    public double getVida() {
        return vida;
    }

    public void setVida(double vida) {
        this.vida = vida;
    }

    public String getEstado() {
        return estado;
    }

    public void setEstado(String estado) {
        this.estado = estado;
    }

    public double getPoderDeAtaque() {
        return poderDeAtaque;
    }

    public void setPoderDeAtaque(double poderDeAtaque) {
        this.poderDeAtaque = poderDeAtaque;
    }

    public int getNivel() {
        return nivel;
    }
} 