import java.util.Scanner;

class MyException extends Exception {
    MyException(String e) {
        super(e);
    }
}

class Product {
    private int weight;

    Product(int weight) {
        this.weight = weight;
    }

    public int getWeight() {
        return weight;
    }

    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.print("Enter the product weight to check products validity: ");
        Product obj = new Product(inp.nextInt());
        try {
            obj.productCheck(obj.weight);
        } catch (Exception e) {
            System.out.println(e);
        }
        inp.close();
    }

    void productCheck(int weight) throws MyException {
        if (weight < 100) {
            throw new MyException("Product is Invalid");
        } else {
            System.out.println(weight);
        }
    }
}