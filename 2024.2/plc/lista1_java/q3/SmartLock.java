public class SmartLock implements SmartDevice {
    private boolean on;

    public SmartLock() {
        this.on = false;
    }

    @Override
    public void turnOn() {
        this.on = true;
    }

    @Override
    public void turnOff() {
        this.on = false;
    }

    @Override
    public String getStatus() {
        return "Fechadura: " + (on ? "trancada" : "destrancada");
    }

    @Override
    public boolean isOn() {
        return on;
    }
} 