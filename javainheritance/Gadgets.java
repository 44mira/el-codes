public class Gadgets {
    /* parent attributes and defaults */
    protected String name, brand, color;
    protected float price;
    protected int qty;    

    public Gadgets(){}          /* empty constructor, use defaults */
    public Gadgets(String name, String brand, String color, float price){
        /* Assigns the 4 parameters only */
        this.name = name;
        this.brand = brand;
        this.color = color;
        this.price = price;
    }
    public Gadgets(String name, String brand, String color, float price, int qty){
        /* Calls the overloaded Constructor to assign the first 4 attributes */
        this(name, brand, color, price);
        this.qty = qty;
    }

    public void setName(String name){
        this.name = name;
    }
    public void setBrand(String brand){
        this.brand = brand;
    }
    public void setColor(String color){
        this.color = color;
    }
    public void setPrice(float price){
        this.price = price;
    }
    public void setQty(int qty){
        this.qty = qty;
    }

    public String getName(){
        return name;
    }
    public String getBrand(){
        return brand;
    }
    public String getColor(){
        return color;
    }
    public float getPrice(){
        return price;
    }
    public int getQty(){
        return qty;
    }
        

}
