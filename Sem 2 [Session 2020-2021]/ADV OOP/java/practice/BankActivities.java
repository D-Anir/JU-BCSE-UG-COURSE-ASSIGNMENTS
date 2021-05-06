public class BankActivities {
    public static void main(String args[]){
        eight b1 = new eight();
        b1.getInfo();
        System.out.println(b1);
        b1.changeRate(5);
        System.out.println("\nInterest: " + b1.returnInterest());
    }
}
