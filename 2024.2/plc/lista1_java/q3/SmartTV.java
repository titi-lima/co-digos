public class SmartTV implements SmartDevice {
    private boolean on;
    private int currentChannel;

    public SmartTV() {
        this.on = false;
        this.currentChannel = 1;
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
        return "TV: " + (on ? "ligada" : "desligada") + 
               ", canal: " + currentChannel;
    }

    @Override
    public boolean isOn() {
        return on;
    }

    public void changeChannel(int channel) {
        if (channel > 0) {
            this.currentChannel = channel;
        }
    }
} 