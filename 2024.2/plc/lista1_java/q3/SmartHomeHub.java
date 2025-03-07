import java.util.ArrayList;
import java.util.List;

public class SmartHomeHub {
    //similarmente ao q1 e ao q2, optei por tornar a lista de dispositivos final por boa prática
    // e também porque meu vscode reclamou.
    final private List<SmartDevice> devices;

    public SmartHomeHub() {
        this.devices = new ArrayList<>();
    }

    public void addDevice(SmartDevice device) {
        devices.add(device);
    }

    public void turnAllOn() {
        for (SmartDevice device : devices) {
            device.turnOn();
        }
    }

    public void turnAllOff() {
        for (SmartDevice device : devices) {
            device.turnOff();
        }
    }

    public void showStatus() {
        for (SmartDevice device : devices) {
            System.out.println(device.getStatus());
        }
    }
} 