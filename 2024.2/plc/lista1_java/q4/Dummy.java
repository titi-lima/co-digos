public class Dummy {
    private String estado;
    private double vida;

    public Dummy() {
        this.estado = "normal";
        this.vida = Double.MAX_VALUE;
    }

    public String getEstado() {
        return estado;
    }

    public void setEstado(String estado) {
        this.estado = estado;
    }

    public double getVida() {
        return vida;
    }

    public void setVida(double vida) {
        this.vida = vida;
    }

    public void reset() {
        this.estado = "normal";
        this.vida = Double.MAX_VALUE;
    }
} 