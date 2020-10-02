/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaArray;

/**
 *
 * @author Harsh Kumar
 * 
 * Problem : 
 * Store has random number of items. Each item has a price, product description and location.
 * Store keeper needs to know the cost of all items at a certain store location 
 * and total cost of all items in store.
 * Upload a file explaining your approach and a flow chart. Write what will be the assumptions, 
 * How will be item names, cost location be decided. What all will be output asked in question.
 * What other output can be provided without any further clarification from Store keeper
 * Now we have completed the theory of this program. 
 * We have discussed the output desired and additional that can be provided. 
 * Create a program to meet all these requirements. The random items in store should not be less than 120. 
 * From the submissions you will be randomly chosen during any lab or lecture session to show your program 
 * and make modifications in class as requested by me at that time. 
 * If you are unable to make the required program modification no marks will be given
 * Program should have outputs:
D1:	he wants to get the price of all the items at a certain position.
D2:	Total cost of all the products in-store.
A1:	He can group all the products by description.
A2:	he can use the program as an inventory list.
A3:	He can see how many items of a certain description are remaining in the store
A4:	He can see where an item is in the store by just searching it by name and getting the location.
A5:	Comparison from highest to lowest total cost per location
 */
import java.util.*;
//class Item defines single item.
class Item{
    /*
      itemName - name,itemLocation - section
      itemPrice - price
    */
    private String name,section;
    private float price;
    //Item() constructor initializes the element fields to empty or 0
    Item(){
        name="";
        section="";
        price=0;
    }
    Item(String a,String b,float c){
        name = a;
        section = b;
        price = c;
    }
    /*
    setFields() functions is used to populate the array values.
    here random number is taken from 1 to 5 and then fields of the items are assigned
    */
    void setFields(int i){
        int randomNumber = (int) (Math.random()*5)+1;
        switch (randomNumber) {
            case 1:
                this.section = "Sports";
                this.name = "sports-Item"+((int)(Math.random()*10)+1);
                this.price = (float) ((int)(Math.random()*20)*5)+200;
                break;
            case 2:
                this.section = "Grocery";
                this.name = "groceryItem"+((int)(Math.random()*10)+1);
                this.price = (float) ((int)(Math.random()*20)*5)+50;
                break;
            case 3:
                this.section = "Tools";
                this.name = "tool-Item"+((int)(Math.random()*10)+1);
                this.price = (float) ((int)(Math.random()*20)*5)+100;
                break;
            case 4:
                this.section = "Clothes";
                this.name="cloth-item"+((int)(Math.random()*10)+1);
                this.price= (float) ((int)(Math.random()*20)*5)+150;
                break;
            case 5:
                this.section = "Shoes";
                this.name="Foot-Wear"+((int)(Math.random()*10)+1);
                this.price= (float) ((int)(Math.random()*20)*5)+150;
                break;
            default:
                break;
        }
    }
    /*
    get() function below are used to return all the fields of the Items
    which are section,name and price.
    */
    protected String getName(){ return this.name;}
    protected String getSection(){ return this.section;}
    protected float getPrice(){ return this.price;}
}
/*
ItemController class controls all the functionality of the shop, it's a bridge between
The program user and the Items in the store
*/
class ItemController{
     int numberOfItems=0;
    //Printing all the Sections
    void printingAllTheSection(){
        System.out.println("Available Section:\nSports\nGrocery\nTools\nClothes\nShoes\n");
    }
    //getPriceFromSection() function returns total price of a section
    float getPriceBySection(String section,Item arr[],int n){
        float price=0;
        numberOfItems=0;
        for(int i=0;i<n;i++){
            if(arr[i].getSection().equals(section)){
                price+=arr[i].getPrice();
                numberOfItems++;
            }
        }
        if(price<=0) System.out.println("This section doesn't exists");
        return price;
    }
    //getTotalPrice() function return the total price of all items
    float getTotalPrice(Item arr[],int n){
        float price=0;
        for(int i=0;i<n;i++){
            price+=arr[i].getPrice();
        }
        if(price<=0) System.out.println("No items are present");
        return price;
    }
    //getNamePriceBySection() prints all the item name, price of user given section
    void getNamePriceBySection(String section,Item arr[],int n){
        boolean isItemFound=false;
        for(int i=0;i<n;i++){
            if(arr[i].getSection().equals(section)){
                isItemFound=true;
                break;
            }
        }       
        if(!isItemFound) System.out.println("Section not found");
        else{
        int len = getTotalNumberOfItemsBySection(section,arr,n),objectNum=0;
        Item array[] = new Item[len];
        for(int i=0;i<n;i++){
            if(arr[i].getSection().equals(section)){
                array[objectNum++] = arr[i];
            }
        }
        for(int i=0;i<len;i++){
            for(int j=0;j<len-1;j++){
                if(array[j].getPrice()>array[j+1].getPrice()){
                    Item temp = array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }
        }
        System.out.println("Item\t\t\tPrice");
        for(int i=0;i<len;i++){
            System.out.println(""+array[i].getName()+"\t\t"+array[i].getPrice());
        }
        }
        
        
    }
    //printAllItems() function prints all the Items present in the store
    void printAllItems(Item arr[],int n){
        System.out.println("Section\t\t\tItem\t\t\t\tPrice");
        for(int i=0;i<n;i++){
            System.out.println(arr[i].getSection()+"\t\t\t"+arr[i].getName()+"\t\t\t"+arr[i].getPrice());
        }
    }
    /*
    getTotalNumberOfItemsBySection() function returns the total number of items of a particular section
    section is user given
    */
    int getTotalNumberOfItemsBySection(String section,Item arr[],int n){
        int count=0,i=0;
        while(i<n){
            if(arr[i++].getSection().equals(section)){
                count++;
            }
        }
        return count;
    }
    //Showing the format of Item-Name for different sections
    void showItemNameBySection(){
        System.out.println("Section \t\t ItemName format(Number 1-10)");
        System.out.println("Sports \t\t\t sports-Item<number>\nGrocery \t\t groceryItem<number>\nTools \t\t\t tool-Item<number>");
        System.out.println("Clothes \t\t cloth-item<number>\nShoes \t\t\t Foot-Wear<number>");
    }
    /*
    getItemByName() function takes string of item name from the user
    then checks the store items if any item name matches  
    It return Section and price if item is found, else returns item not found
    */
    String getItemByName(String itemName,Item arr[],int n){
        String itemLocation="",itemPrice="",retString="";
        boolean isFound=false;
        for(int i=0;i<n;i++){
            if(arr[i].getName().equals(itemName)){
                itemLocation=arr[i].getSection();
                itemPrice = ""+arr[i].getPrice();
                isFound=true;
            }
        }
        if(!isFound) retString="item not found";
        else retString = "\t\tSection : "+itemLocation+"\t\tPrice : "+itemPrice;
        return retString;
    }
    /*
    getMostExpensiveItem() function is used to get the item which is most expensive
    from a particular section
    */
    Item getMostExpensiveItem(String section,Item arr[],int n) {
        Item ex;
        if(n==0){
            ex=new Item();
        }
        else{
        int index=0;
        float max=0;
        for(int i=0;i<n;i++){
            if(arr[i].getSection().equals(section)){
                if(max<arr[i].getPrice()){
                    max=arr[i].getPrice();
                    index=i;
                }
            }
        }
        ex = arr[index];
        }
        return ex;
    }
    /*
    getCheapestItem() function is used to get the item which is the cheapest item
    from a particular section
    */
    Item getCheapestItem(String section,Item arr[],int n) {
        Item ex;
        if(n==0){
            ex=new Item();
        }
        else{
        int index=0;
        float max=1000;
        for(int i=0;i<n;i++){
            if(arr[i].getSection().equals(section)){
                if(max>arr[i].getPrice()){
                    max=arr[i].getPrice();
                    index=i;
                }
            }
        }
        ex = arr[index];
        }
        return ex;
    }
}
/*
Main class executes main function and create a user driven menu
Multiple functionality is given to the user
*/
public class JavaArrayFive {
    public static void main(String[] args){
        //scanner object to take user input
        Scanner sc = new Scanner(System.in);
        int totalNumberOfItems = 120;
        /*
        Number of items are taken as user 120 and
        value of the item fields are set. location,name and price for each item is set
        */
        Item[] arr = new Item[totalNumberOfItems];
        for(int i=0;i<totalNumberOfItems;i++){
            arr[i] = new Item();
            arr[i].setFields(i);
        }
        /*
        ItemController object to perform all the required function
        on All the Items Created0
        */
        ItemController obj = new ItemController();
        boolean run=true;
        //loop executes until run becomes false
        while(run){
            /*
            Options are shown and user input is taken
            */
        System.out.println("---------------------------------------------------------------------------------------");
            System.out.println("0-Get The Total Item List (Warning : contains 120 items, use it when the whole list require)");
        System.out.println("1.Get price by section\t\t\t\t\t2.Get total price of items in the store");
        System.out.println("3.Get items of section in Asc order of price\t\t4.Get Number of remaining Items of a section");
        System.out.println("5.Get item location and price by name\t\t\t6.Most expensive and cheapest item of a section");
        System.out.println("7.Exit");
        System.out.print("Enter your choice : ");
        String choice = sc.next();
        System.out.println("----------------------------------------------------------------------------------------");
        sc.nextLine();
        //According to the user input the output is given to the user
        switch(choice){
            case "0":
                obj.printAllItems(arr,totalNumberOfItems);
                break;
            case "1":
                obj.printingAllTheSection();
                System.out.print("Enter section to get its total price : ");
                String sectionOne = sc.nextLine();
                float totalPriceBySection = obj.getPriceBySection(sectionOne, arr, totalNumberOfItems);
                System.out.printf("total price of %d units of section %s : %.3f\n",
                        obj.numberOfItems,sectionOne,totalPriceBySection);
                break;
            case "2":
                System.out.printf("Total price of 120 item : %.3f\n",obj.getTotalPrice(arr, totalNumberOfItems));
                break;
            case "3":
                obj.printingAllTheSection();
                System.out.print("Enter section to get all items name and price is ascending order of price : ");
                String sectionTwo = sc.nextLine();
                obj.getNamePriceBySection(sectionTwo, arr, totalNumberOfItems);
                break;
            case "4":
                obj.printingAllTheSection();
                System.out.print("Enter section to get total number of items : ");
                String sectionThree = sc.nextLine();
                System.out.println("Section : "+sectionThree+"\nNumber of items : "+
                    obj.getTotalNumberOfItemsBySection(sectionThree,arr,totalNumberOfItems));
                break;
            case "5":
                obj.showItemNameBySection();
                System.out.print("Enter item name to get the location and price : ");
                String itemNameToFind = sc.nextLine();
                System.out.println("Section : "+itemNameToFind+"\nNumber of items : "+
                    obj.getItemByName(itemNameToFind,arr,totalNumberOfItems));
                break;
            case "6":
                obj.printingAllTheSection();
                System.out.print("Enter section to find the most expensive and cheapest item : ");
                String sectionToFind = sc.nextLine();
                Item expensive = obj.getMostExpensiveItem(sectionToFind,arr,totalNumberOfItems);
                Item cheapest = obj.getCheapestItem(sectionToFind,arr,totalNumberOfItems);
                System.out.println("Section : "+sectionToFind);
                System.out.println
                    ("Most Expensive item\tName : "+expensive.getName()+"\tprice : "+expensive.getPrice());
                System.out.println("Cheapest item\t\tName : "+cheapest.getName()+"\tprice : "+cheapest.getPrice());     
                break;
            case "7":
                run=false;
                break;
            default:
                System.out.println("Wrong Input Entered");
        }
        System.out.print("Enter any key to continue : ");
        sc.nextLine().charAt(0);
        }
    }
}
