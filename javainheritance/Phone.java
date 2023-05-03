public class Phone extends Gadgets{
    /* child attributes and defaults */
    private int RAMinGB;
    private int storageInGB;
    private float batteryLifeInHrs;

    public Phone(){}
    /* fully set constructor */
    public Phone(int RAMinGB, int storageInGB, float batteryLifeInHrs,
                String name, String brand, String color, float price, int qty){

        super(name, brand, color, price, qty);
        this.RAMinGB = RAMinGB;
        this.storageInGB = storageInGB;
        this.batteryLifeInHrs = batteryLifeInHrs;
    }

    /* setters */
    public void setRAM(int r){
        RAMinGB = r;
    }
    public void setStorage(int s){
        storageInGB = s;
    }
    public void setBattery(float b){
        batteryLifeInHrs = b;
    }

    /* getters */
    public int getRAM(){
        return RAMinGB;
    }
    public int getStorage(){
        return storageInGB;
    }
    public float getBattery(){
        return batteryLifeInHrs;
    }
    
    public void displayPhone(){
        System.out.printf("Name: %-12sBrand: %s\t\tColor: %s\n"+
                          "Price: $%-10.2fQty: %d\n"+
                          "RAM (GB): %-8dStorage (GB): %d\tBattery Life (Hrs): %.2f\n\n",
                          name, brand, color, price, qty, RAMinGB,
                          storageInGB, batteryLifeInHrs);
    }
}
