import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class MyButton {
    private JFrame myFrame;
    private JLabel header;
    private JLabel status;
    private JLabel lower;
    private JPanel control;

    public MyButton(){
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

    public void showButtons(){
        header.setText("buttons");

        JButton okButton = new JButton("OK");
        JButton submitButton = new JButton("SUBMIT");
        JButton cancelButton = new JButton("CANCEL");
        cancelButton.setHorizontalAlignment(SwingConstants.CENTER);

        okButton.addActionListener(new MyActionListener());
        submitButton.addActionListener(new MyActionListener());
        cancelButton.addActionListener(new MyActionListener());

        control.add(okButton);
        control.add(submitButton);
        control.add(cancelButton);
        myFrame.setVisible(true);
    }

    public static void main(String args[]){
        MyButton lb = new MyButton();
        lb.showButtons();
    }

    private class MyActionListener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            String msg = e.getActionCommand();
            status.setText(msg + " Button clicked.");
        }
    }

}

