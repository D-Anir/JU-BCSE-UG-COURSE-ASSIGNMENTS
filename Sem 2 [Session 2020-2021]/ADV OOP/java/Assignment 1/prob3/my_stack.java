public class my_stack{  //stack implementation using array
        private int max;
        private char[] arr;  //need to make generic
        private int top;
    public my_stack(int s){ //constructor
        max = s;
        top = -1;
        arr = new char[max];
    }    
    public void push(char c){ //add data
        arr[++top] = c;
    }
    public char pop(){
        return arr[top--];
    }
    public char return_top(){ //returns top element
        return arr[top];
    }
    //check for underflow and overflow
    public boolean isEmpty(){
        return top == -1 ;
    }
    public boolean isFull(){
        return top == (max -1);
    }
}