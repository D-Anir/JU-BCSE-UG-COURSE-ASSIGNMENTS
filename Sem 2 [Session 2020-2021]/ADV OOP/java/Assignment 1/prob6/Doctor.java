import java.util.*;

// store doctor data
public class Doctor {
        private String doc_id;
        private String name;
        private String address;
        private String contact_no;
        private ArrayList<Patient> patient_list = new ArrayList<Patient>();

    public Doctor(){

    }

    // get doctor data from the user
    public void getData(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Doctor Name: ");
        name = sc.nextLine();
        name = name.substring(0, 1).toUpperCase() + name.substring(1);
        System.out.println("Enter Doctor Address: ");
        address = sc.nextLine();
        System.out.println("Enter Doctor Contact No.: ");
        contact_no = sc.nextLine();
    }

    // automatically generate Doctor ID
    public void generateDocID(String name, int number){
        doc_id = "DR_" + name.substring(0,3).toUpperCase() + "_00" + String.valueOf(number);
    }

    // assign patient to a particular doctor
    public String addPatient(String name, Patient p, int n){
        patient_list.add(p);
        patient_list.get(patient_list.size() - 1).assignDoctor(this);
        patient_list.get(patient_list.size() - 1).generatePatientID(name, n);
        return  patient_list.get(patient_list.size() - 1).returnID();
    }
    
    // check if patient is assigned to a particular doctor
    public boolean doesPatientExists(String ID){
        for(Patient p : patient_list){
            if(ID.equals(p.returnID())){
                return true;
            }
        }
        return false;
    }

    // show data of a single patient, along with doctor assigned
    public void showSinglePatientData(String ID){
        for(Patient p : patient_list){
            if(ID.equals(p.returnID())){
                p.showData();
            }
        }
    }

    // display doctor info, along with assigned patients
    public void showDoctorData(){
        System.out.println("DoctorID: " + doc_id);
        System.out.println("Name: Dr. " + name);
        System.out.println("Contact No.: " + contact_no);
    }

    // show all patients under a particular doctor
    public void showAllPatients(){
        if(patient_list.isEmpty()){
            System.out.println("No Patients assigned yet!");
            return;
        }
        for(Patient p : patient_list){
            p.showData();
        }
    }

    // accessor function to return name
    public String returnName(){
        return name;
    }

    // accessor function to return ID
    public String returnID(){
        return doc_id;
    }

}
