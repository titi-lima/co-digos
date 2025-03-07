import java.util.Random;

public class Game {
    private static Integer turno;

    public static void main(String[] args) {
        Dummy dummy = new Dummy();
        
        // Gerar monstro aleatório
        Monstro monstro = gerarMonstroAleatorio(5); // nível 5 para exemplo
        System.out.println("Monstro gerado: " + monstro.getClass().getSimpleName() + " Nível " + monstro.getNivel());
        System.out.println("Vida inicial: " + monstro.getVida());
        System.out.println("Poder de ataque inicial: " + monstro.getPoderDeAtaque());
        
        // Simular batalha
        for (turno = 1; turno <= 10; turno++) {
            System.out.println("\n=== Turno " + turno + " ===");
            System.out.println("Estado do Dummy: " + dummy.getEstado());
            System.out.println("Vida do Dummy: " + dummy.getVida());
            System.out.println("Vida do Monstro: " + monstro.getVida());
            System.out.println("Poder de ataque do Monstro: " + monstro.getPoderDeAtaque());
            
            if (!monstro.aindaVive()) {
                System.out.println("Monstro foi derrotado!");
                break;
            }
            
            // Monstro ataca
            System.out.println("\nMonstro ataca:");
            realizarAtaque(monstro, dummy);
            
            // Reduzir vida do monstro
            double vidaAnterior = monstro.getVida();
            monstro.setVida(monstro.getVida() * 0.9);
            System.out.println("Monstro perdeu " + (vidaAnterior - monstro.getVida()) + " de vida");
            
            if (!monstro.aindaVive()) {
                System.out.println("Monstro foi derrotado!");
                break;
            }
            
            // Reset do dummy para próximo turno
            dummy.reset();
            System.out.println("Dummy foi resetado para o próximo turno");
        }
    }
    
    private static Monstro gerarMonstroAleatorio(int nivel) {
        Random random = new Random();
        Monstro monstro;
        
        // Escolher tipo de monstro
        monstro = switch (random.nextInt(3)) {
            case 0 -> new Dragao(nivel);
            case 1 -> new Rato(nivel);
            default -> new Lobo(nivel);
        };
        
        // Adicionar cores aleatórias
        if (monstro instanceof Colorido colorido) {
            if (random.nextBoolean()) colorido.azulado();
            if (random.nextBoolean()) colorido.esverdeado();
            if (random.nextBoolean()) colorido.amarelado();
        }
        
        return monstro;
    }
    
    private static void realizarAtaque(Monstro monstro, Dummy dummy) {
        Random random = new Random();
        
        // Verificar múltiplos ataques por turno
        int numAtaques = 1;
        if (monstro instanceof Dragao && ((Dragao) monstro).isAmarelo()) {
            numAtaques = 2;
            System.out.println("Dragão Amarelo: realizando 2 ataques neste turno");
        } else if (monstro instanceof Rato && ((Rato) monstro).isRoxo()) {
            numAtaques = 3;
            System.out.println("Rato Roxo: realizando 3 ataques neste turno");
        }
        
        for (int i = 0; i < numAtaques; i++) {
            if (numAtaques > 1) {
                System.out.println("Ataque " + (i + 1) + " de " + numAtaques);
            }
            
            switch (random.nextInt(3)) {
                case 0 -> {
                    monstro.mordida(dummy);
                    System.out.println("Monstro usou Mordida");
                }
                case 1 -> {
                    monstro.arranhao(dummy);
                    System.out.println("Monstro usou Arranhão");
                }
                case 2 -> {
                    monstro.investida(dummy);
                    System.out.println("Monstro usou Investida");
                }
            }
            
            System.out.println("Estado do Dummy após o ataque: " + dummy.getEstado());
            System.out.println("Vida do Dummy após o ataque: " + dummy.getVida());
        }
    }
} 