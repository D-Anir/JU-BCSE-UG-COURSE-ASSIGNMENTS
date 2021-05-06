import java.util.Scanner;

// store patient information
public class Patient{
        private String patient_id;
        private String name;
        private int age;
        private String address;
        private String contact_no;
        private Doctor doctor;
        private float blood_pressure;
        private int temparature;      //in kelvin
        private boolean hasADoctor;
    
    // constructor
    public Patient(){
        doctor = null;
        hasADoctor = false;
    }

    // get data from the user
    public void getData(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Patient Name: ");
        name = sc.nextLine();
        name = name.substring(0, 1).toUpperCase() + name.substring(1);
        System.out.println("Enter Patient Age: ");
        age = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter Patient Address: ");
        address = sc.nextLine();
        System.out.println("Enter Paatient Contact No.: ");
        contact_no = sc.nextLine();
        System.out.println("Enter Patient Blood Pressure:");
        blood_pressure = sc.nextFloat();
        sc.nextLine();
        System.out.println("Enter Patient Temparature:");
        temparature = sc.nextInt();
        sc.nextLine();
    }

    // display
    public void showData(){
        System.out.println("\nPatient ID: " + patient_id);
        System.out.println("Patient Name: " + name);
        System.out.println("Temparature: " + temparature);
        System.out.println("Blood Pressure: " + blood_pressure);
    }

    // assign a doctor with the patient
    public void assignDoctor(Doctor d){
        doctor = d;
        hasADoctor = true;
    }

    // check if the patient is already assigned a doctor
    public boolean isDoctorAssigned(){
        return hasADoctor;
    }

    // generate the patient code automatically in a specific format
    public void generatePatientID(String name, int number){
        patient_id = "PAT_" + name.substring(0, 3).toUpperCase() + "_00" + String.valueOf(number);
    }

    // accessor function to return ID
    public String returnID(){
        return patient_id;
    }

    // accessor function to return name
    public String returnName(){
        return name;
    }

}