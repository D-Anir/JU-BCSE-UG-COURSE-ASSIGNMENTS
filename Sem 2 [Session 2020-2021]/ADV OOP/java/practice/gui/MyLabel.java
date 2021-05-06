import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class MyLabel {
    private JFrame myFrame;
    private JLabel header;
    private JLabel status;
    private JLabel lower;
    private JPanel control;

    public MyLabel(){
        initiate();
    }

    public void initiate(){
        myFrame = new JFrame("My First GUI model");
        myFrame.setSize(400, 400);
        myFrame.setLayout(new BorderLayout());

        myFrame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent windowEvent){
               System.exit(0);
            }        
        });


        header = new JLabel("", JLabel.CENTER);
        status = new JLabel("", JLabel.CENTER);
        status.setSize(300, 100);
        control = new JPanel();
        control.setLayout(new FlowLayout());

        lower = new JLabel("", JLabel.CENTER);
        

        myFrame.add(header, BorderLayout.SOUTH);
        myFrame.add(status, BorderLayout.NORTH);
        myFrame.add(lower, BorderLayout.CENTER);
        myFrame.add(control, BorderLayout.AFTER_LINE_ENDS);
        myFrame.setVisible(true);

    }

    public void showLabels(){
        header.setText("labels");
        status.setText("wassup i am a status");

        status.setOpaque(true);
        status.setBackground(Color.BLACK);
        status.setForeground(Color.orange);

        lower.setText("ok bye see ya later");

        myFrame.setVisible(true);
    }

    public static void main(String args[]){
        MyLabel lb = new MyLabel();
        lb.showLabels();
    }
}