/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaArrayTwo;

import java.util.Scanner;

/**
 *
 * @author Harsh Kumar
 */
//Personalized LinkedList to store orders
class HarshLinkedList{
    
    //Points to the first element of the Cart
    Node head=null;
    
    //Final float value for GST
    static final float GST = 15f; 
    
    //Adding a book to the cart
    void Add(Book element){
        Node toAdd = new Node(element);
        if(head==null){
            head=toAdd;
        }
        else{
            Node temp = head;
            while(temp.next!=null){
                temp = temp.next;
            }
            temp.next=toAdd;
        }
    }
    
    //checking the number of books in the cart
    int size(){
        int i=0;
        if(head==null){
            i=0;
        }
        else{
            Node temp = head;
            while(temp!=null){
                i++;
                temp=temp.next;
            }
        }
        return i;
    }
    
    //Deleting a book from the cart by index
    void deletion(int index){
        if(head==null){
            System.out.println("No element present");
        }
        else{
            if(index > size()){
                System.out.println("Total elements in cart is "+size());
                System.out.println("index out of bound");
            }
            else{
                int i=1;
                Node temp = head;
                if(index==1){
                    head = temp.next;
                    System.out.println("Book "+index+" removed");
                }
                else if(index==size()){
                    System.out.println("Book "+size()+" removed");
                    while(temp.next.next!=null){
                        temp=temp.next;
                    }
                    temp.next=null;
                }
                else{
                    while(i++<index-1){
                        temp=temp.next;
                    }
                    temp.next=(temp.next).next;
                System.out.println("Book "+index+" removed");
                }
            }
        }
    }
    
    //Showing all the books in the cart
    void showAll(){
        Node temp = head;
        int i=0;
        System.out.println("------------------------ CART --------------------");
        while(temp!=null){
            System.out.println("Book Index : "+ (++i));
            System.out.println(temp.object.getBook());
            temp = temp.next;
        }
        System.out.println("------------------------ CART --------------------");
    }
    
    //Getting the total value of the books
    float getTotalOfBooks(){
        float total=0;
        Node temp = head;
        while(temp!=null){
            total += temp.object.getPrice();
            temp = temp.next;
        }
        return total;
    }
    
    //Returns GST value of total of all books in the cart
    float getTaxation(){
        float total = getTotalOfBooks();
        return total*(GST/100);
    }
    
    //Node class for single entity of the book
    class Node{
        Book object;
        Node next;
        Node(Book obj){
            object=obj;
            next=null;
        }
    }
}

class Book{
    /*
    Data fields of Book:
    title,section,language,author,price,year of publication, unique book ID
    */
    private String titleOfBook,sectionOfBook,languageOfBook,authorOfBook;
    private float priceOfBook;
    private int yearOfPublication,BookId;
    
    //Book() constructor to initalize value of the book to given parameters
    Book(String a,String b,String c,String d,float e,int f,int g){
        this.titleOfBook=a;
        this.sectionOfBook=b;
        this.languageOfBook=c;
        this.authorOfBook=d;
        this.priceOfBook=e;
        this.yearOfPublication=f;
        this.BookId=g;
    }
    
    //Returns all the detials of a certan book
    protected String getBook(){
        return "Book Id : "+this.BookId+
                "\nTitle : "+this.titleOfBook+
                "\t\tSection : "+this.sectionOfBook+
                "\t\tLanguage : "+this.languageOfBook+
                "\nAuthor : "+this.authorOfBook+
                "\t\t\t\tPrice : "+this.priceOfBook+
                "\t\t\tYear : "+this.yearOfPublication;
    }
    
    //return title of the book
    protected String getTitle(){return this.titleOfBook;}
    
    //return section of the book
    protected String getSection(){return this.sectionOfBook;}
    
    //return language of the book
    protected String getLanguage(){return this.languageOfBook;}
    
    //return author of the book
    protected String getAuthor(){return this.authorOfBook;}
    
    //return price of the book
    protected float getPrice(){return this.priceOfBook;}
    
    //return year of the book
    protected int getyear(){return this.yearOfPublication;}
    
    //return book ID of the book
    protected int getBookId(){return this.BookId;}
    
}

class BookController{
    //Printing available sections in the store
    void availableSection(){
        for(int i=1;i<=5;i++){
            System.out.println("Section-"+i);
        }
    }
    
    //Printing available Language
    void availableLanguage(){System.out.println("Java\tC++\tC\tPython\t\tR");}
    
    //Printing available Authors
    void availableAuthor(){
        for(int i=1;i<=10;i++){
            System.out.println("Author-"+i);
        }
    }
    
    //Printing available Year
    void availableYear(){
        for(int i=0;i<20;i++) System.out.println((2000+i));
    }
    
    //Populating the array of book
    //Creating and locating books in the store
    void Populate(Book array[],int n){
        for(int i=0;i<n;i++){
            String Title="";
            String section = "Section-"+((int)(Math.random()*5)+1);
            String Language="";
            int randomLanguage = ((int)(Math.random()*5)+1);
            switch(randomLanguage){
                case 1:
                    Language = "Java";
                    Title="  Java Programming";
                    break;
                case 2:
                    Language = "C++";
                    Title="   C++ Programming";
                    break;
                case 3:
                    Language = "C";
                    Title="     C Programming";
                    break;
                case 4:
                    Language = "Python";
                    Title="Python Programming";
                    break;
                case 5:
                    Language = "R";
                    Title="     R Programming";
                    break;
            }
            String Author = "Author-"+((int)(Math.random()*10)+1);
            float Price = 300+((int)(Math.random()*50))*25;
            int Year = 2000+(int)(Math.random()*20);
            Title += " Title-"+((int)(Math.random()*25)+1);
            array[i] = new Book(Title,section,Language,Author,Price,Year,(i+1));
        }
    }
    
    //Prints all books available in the shop
    void showAllBooks(Book array[],int n){
        for(int i=0;i<n;i++) System.out.println(array[i].getBook()+"\n");
    } 
    
    //Prints all books available in the shop section wise
    void showAllBooksBySection(Book array[],int n){
        for(int i=1;i<=5;i++){
            System.out.println("Section-"+i+" has : ");
            for(int j=0;j<120;j++){
                if(array[j].getSection().equals("Section-"+i)){
                    System.out.println(array[j].getBook());
                }
            }
            System.out.println("\n");
        }
    }
    
    //Prints all books available in the shop language wise
    void showAllBooksByLanguage(Book array[],int n){
        String languages[] = {"Java","C++","C","Python","R"};
        for(int i=0;i<5;i++){
            System.out.println(languages[i]+" has : ");
            for(int j=0;j<120;j++){
                if(array[j].getLanguage().equals(languages[i])){
                    System.out.println(array[j].getBook());
                }
            }
            System.out.println("\n");
        }
    }
    
    //Prints all books available in the shop Author wise
    void showAllBooksByAuthor(Book array[],int n){
        for(int i=1;i<=10;i++){
            System.out.println("Author-"+i);
            for(int j=0;j<120;j++){
                if(array[j].getAuthor().equals("Author-"+i)){
                    System.out.println(array[j].getBook());
                }
            }
            System.out.println("\n");
        }
    }
    
    //Prints all books available in the shop below or equal to certain price
    void showAllBooksBelowPrice(Book array[],int n,float price){
        for(int i=0;i<120;i++){
            if(array[i].getPrice()<=price){
                System.out.println(array[i].getBook());
            }
        }
    }
    
    //Prints all books available in the shop by a year of publication
    void showAllBooksByYearOfPublication(Book array[],int n){
        for(int i=0;i<20;i++){
            System.out.println("Year "+(2000+i)+" : ");
            for(int j=0;j<n;j++){
                if(array[j].getyear() == (2000+i)){
                    System.out.println(array[j].getBook());
                }
            }
            System.out.println("\n");
        }
    }
    
    //finds and prints books available in the shop By taking section from user
    void findBooksBySection(Book array[],int n,String s){
        boolean isFound = false;
        for(int i=0;i<n;i++){
            if(array[i].getSection().equals(s)){
                System.out.println(array[i].getBook());
                isFound = true;
            }
        }
        if(!isFound){
            System.out.println(s+" not found ! ");
        }
    }
    
    //finds and prints books available in the shop By taking language from user
    void findBookByLanguage(Book array[],int n,String s){
        boolean isFound = false;
        for(int i=0;i<n;i++){
            if(array[i].getLanguage().equals(s)){
                System.out.println(array[i].getBook());
                isFound=true;
            }
        }
        if(!isFound){
            System.out.println(s+" Language not found ! ");
        }
    }
    
    //finds and prints books available in the shop By taking author from user
    void findBookByAuthor(Book array[],int n,String s){
        boolean isFound = false;
        for(int i=0;i<n;i++){
            if(array[i].getAuthor().equals(s)){
                System.out.println(array[i].getBook());
                isFound=true;
            }
        }
        if(!isFound){
            System.out.println(s+" not found ! ");
        }
    }
    
    //finds and prints books available in the shop By taking Year from user
    void findBookByYear(Book array[],int n,int y){
        boolean isFound = false;
        for(int i=0;i<120;i++){
            if(array[i].getyear() == y){
                System.out.println(array[i].getBook());
                isFound=true;
            }
        }
        if(!isFound){
            System.out.println(y+" Year not found ! ");
        }
    }
    
    //finds and prints books available in the shop By taking Book ID from user
    void findBookById(Book array[],int n,int Id){
        for(int i=0;i<n;i++){
            if(array[i].getBookId() == Id){
                System.out.println(array[i].getBook());
            }
        }
    }
    
    //returns object of the book by taking book id
    protected Book getBookById(Book array[],int n,int BookId){
    Book toReturn=null;
        for(int i=0;i<n;i++){
            if(array[i].getBookId()==BookId){
                toReturn = array[i];
                break;
            }
        }
        if(toReturn == null){
            System.out.println("Book Not Found!");
            return null;
        }
        return toReturn;
    }
}

public class BookStore {
    public static void main(String[] args){
        //Scanner object to take user input
        Scanner sc = new Scanner(System.in);
        /*
        total number of books are fixed as 120;
        array of 120 books are created;
        object of BookController class is created to do operations on books;
        obj of HarshLinkedList is created to create a cart for adding, removing, getting total etc;
        */
        int totalNumberOfBooks = 120;
        Book array[] = new Book[totalNumberOfBooks];
        BookController object = new BookController();
        HarshLinkedList obj = new HarshLinkedList();
        
        //populating the array of books
        object.Populate(array, totalNumberOfBooks);
        boolean run=true;
        while(run){
        //Taking user input and printing the menus
        System.out.println("\n---------------------- Main Menu -------------------------------");
        System.out.println
        ("1.All books category-wise\t2.All books author-wise\t\t"+
                "3.All books lower than certain price");
        System.out.println
        ("4.All books year-wise\t\t5.All books section-wise\t6.Do custom search");
        System.out.println
        ("7.Show your cart\t\t8.Exit");
        System.out.print("Enter choice : ");
        String choice = sc.nextLine();
        switch(choice){
            //Prints all books language wise
            case "1":
                object.showAllBooksByLanguage(array, totalNumberOfBooks);
                break;
            case "2":
            //Prints all books author wise
                object.showAllBooksByAuthor(array, totalNumberOfBooks);
                break;
            case "3":
            //Prints all books below or equal to certain price
                System.out.print("Enter Price : ");
                float price = sc.nextFloat();
                sc.nextLine();
                object.showAllBooksBelowPrice(array, totalNumberOfBooks, price);
                break;
            case "4":
            //Prints all books year wise
                object.showAllBooksByYearOfPublication(array, totalNumberOfBooks);
                break;
            case "5":
            //Prints all books section wise
                object.showAllBooksBySection(array, totalNumberOfBooks);
                break;
            case "6":
                //Performing a custom search on the list of the books
                boolean runTwo = true;
                while(runTwo){
                    //Printing menu and taking user input
                    System.out.println("\n--------------------  Custom Search -----------------------------");
                System.out.println("\t1.Find by Language\t2.Find by Author\t3.Find by Year of publication");
                System.out.println("\t4.Find by Section\t5.Find by Price \t6.Exit");
                System.out.print("Enter choice : ");
                String choiceTwo = sc.nextLine();
                switch(choiceTwo){
                    case "1":
                        //Taking Language from user and printing books by language
                        object.availableLanguage();
                        System.out.print("\nEnter Language : ");
                        String findLanguage = sc.nextLine();
                        object.findBookByLanguage(array, totalNumberOfBooks,findLanguage);
                        break;
                    case "2":
                        //Taking Author from user and printing books by author
                        object.availableAuthor();
                        System.out.print("\nEnter Author : ");
                        String findAuthor = sc.nextLine();
                        object.findBookByAuthor(array, totalNumberOfBooks, findAuthor);
                        break;
                    case "3":
                        //Taking Year from user and printing books by year
                        object.availableYear();
                        System.out.print("\nEnter Year of publication : ");
                        int findYear = sc.nextInt();
                        sc.nextLine();
                        object.findBookByYear(array, totalNumberOfBooks, findYear);
                        break;
                    case "4":
                        //Taking Section from user and printing books by section
                        object.availableSection();
                        System.out.print("\nEnter Section : ");
                        String findSection = sc.nextLine();
                        object.findBooksBySection(array,totalNumberOfBooks, findSection);
                        break;
                    case "5":
                        //Taking price from user and printing books below or equal to price
                        System.out.print("\nEnter Price (moderate price is 1000):");
                        int findPrice = sc.nextInt();
                        sc.nextLine();
                        object.showAllBooksBelowPrice(array, totalNumberOfBooks, findPrice);
                        break;
                        //exits custom search menu
                    case "6":
                        runTwo = false;
                        break;
                        //if input is not in range
                    default:
                        System.out.println("Wrong input");
                        break;
                }
                }
                break;
            case "7":
                    //Opening a cart to store books
                boolean runThree= true;
                while(runThree){
                //Printing menus and taking user input    
                System.out.println("\n--------------------  Your Cart  -----------------------------");
                System.out.println("\t\t1.See cart\t2.Add Book\t3.Remove Book\t4.Get Total\t5.Exit");
                System.out.print("Enter choice : ");
                String choiceThree = sc.nextLine();
                switch(choiceThree){
                    case "1":
                        //Prints all the books inside the cart
                        obj.showAll();
                        break;
                    case "2":
                        //Adds a book to the cart using unique book id
                        System.out.print("Enter Unique Book ID : ");
                        int getBookId = sc.nextInt();
                        sc.nextLine();
                        Book toAdd = object.getBookById(array,totalNumberOfBooks,getBookId);
                        obj.Add(toAdd);
                        System.out.println("New Book Added!");
                        break;
                    case "3":
                        //removes a book from the cart using index from user
                        System.out.print("Enter Book index to remove : ");
                        int index = sc.nextInt();
                        sc.nextLine();
                        obj.deletion(index);
                        break;
                    case "4":
                        //prints all the books available with total amount to pay with taxation
                        obj.showAll();
                        if(obj.size()<=0){
                            System.out.println("No Book In Cart");
                        }
                        else{
                            float totalAmount = obj.getTotalOfBooks();
                            float totalTaxation = obj.getTaxation();
                            System.out.println("\t\t-------------------BILL TOTAL--------------------");
                            System.out.printf("\t\tTotal Amount : \t\t\t %.2f",totalAmount);
                            System.out.printf("\n\t\tTotal Tax (15 per) : \t\t %.2f",totalTaxation);
                            System.out.printf("\n\t\tTotal Payable Amount : \t\t%.2f",(totalAmount+totalTaxation));
                            System.out.println("\n\t\t-----------------------------------------------");
                        }
                        break;
                        //Exits the cart menu
                    case "5":
                        runThree=false;
                        break;
                        //If wrong input entered
                    default:
                        System.out.println("Wrong input");
                        break;
                }
                }
                break;
                //exits the main menu
            case "8":
                run=false;
                break;
                //if wrong input is entered
            default:
                System.out.println("Wrong input");
                break;
        }
        }
    }
}
