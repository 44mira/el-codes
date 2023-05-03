/* 
 * Legolas Tyrael B. Lada  1-BSCS
 * 2022-04734
 * CMSC 28
 */
class Main{

    public static void main(String args[]){

        Phone iphone = new Phone();
        Phone samsung = new Phone(8, 64, 2.5f, "OPPO A37fw", "OPPO", "Pink", 100.0f, 1);

        iphone.setName("IPhone X");
        iphone.setBrand("Apple");
        iphone.setColor("Rose Gold");
        iphone.setPrice(399.99f);
        iphone.setQty(2);
        iphone.setRAM(12);
        iphone.setStorage(128);
        iphone.setBattery(2.3f);

        iphone.displayPhone();
        samsung.displayPhone();

    }

}