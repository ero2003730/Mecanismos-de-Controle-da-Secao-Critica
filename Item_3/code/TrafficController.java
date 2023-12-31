import java.util.concurrent.Semaphore;

public class TrafficController {

    private Semaphore semaphore;

    public TrafficController() {

        /* Inicializa o semáforo com 1 
        permissão, o que permite apenas 
        uma thread de cada vez*/
        semaphore = new Semaphore(1);
    }

    public void enterLeft() {

        try {

            // Bloqueia se o semáforo não tiver permissão
            semaphore.acquire(); 

        } catch (InterruptedException e) {

            Thread.currentThread().interrupt();
        }
    }

    public void enterRight() {
        
        try {

            // Bloqueia se o semáforo não tiver permissão
            semaphore.acquire(); 

        } catch (InterruptedException e) {

            Thread.currentThread().interrupt();
        }
    }

    public void leaveLeft() {

        semaphore.release(); // Libera uma permissão
    }

    public void leaveRight() {

        semaphore.release(); // Libera uma permissão
    }
}