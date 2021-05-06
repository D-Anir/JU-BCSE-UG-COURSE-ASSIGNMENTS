import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class MyCheckBox {
    private JFrame myFrame;
    private JLabel header;
    private JLabel status;
    private JLabel lower;
    private JPanel control;

    public MyCheckBox(){
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
        

        myFrame.add(header, BorderLayout.NORTH);
        myFrame.add(status, BorderLayout.SOUTH);
        // myFrame.add(lower, BorderLayout.CENTER);
        myFrame.add(control);
        myFrame.setVisible(true);

    }

    public void showCheckBoxes(){
        header.setText("check boxes");

        JCheckBox first = new JCheckBox("Biriyani");
        JCheckBox second = new JCheckBox("Firni");
        JCheckBox third = new JCheckBox("Gulab Jamun");

        first.setMnemonic(KeyEvent.VK_C);
        second.setMnemonic(KeyEvent.VK_M);
        third.setMnemonic(KeyEvent.VK_P);

        first.addItemListener(new MyItemListener());
        second.addItemListener(new MyItemListener());
        third.addItemListener(new MyItemListener());

        // JButton submitButton = new JButton("Submit Responses");

        // submitButton.addActionListener(new MyActionListener());

        control.add(first);
        control.add(second);
        control.add(third);
        myFrame.setVisible(true);
    }

    public static void main(String args[]){
        MyCheckBox lb = new MyCheckBox();
        lb.showCheckBoxes();
    }

    private class MyItemListener implements ItemListener{
        public void itemStateChanged(ItemEvent e){
            status.setText( ((JCheckBox)e.getItem()).getText() + " Checkbox: " 
               + (e.getStateChange()==1?"checked":"unchecked"));
        }
    }

}

