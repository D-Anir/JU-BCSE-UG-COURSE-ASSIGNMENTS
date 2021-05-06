import java.util.*;
import java.lang.*;

public class Hospital {
    
    // menu 1
    static int menu(){
        System.out.println("\n**HOSPITAL RECEPTION MENU**");
        System.out.println("1. Add Doctor.");
        System.out.println("2. Add Patient.");
        System.out.println("3. Check Patient Details.");
        System.out.println("4. Show All Patients under a Doctor.");
        System.out.println("5. Show All Doctors.");
        System.out.println("6. Exit.");
        System.out.println("Enter Your choice: ");
        int choice;
        Scanner sc = new Scanner(System.in);
        choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }
    public static void main(String args[]){
        ArrayList<Doctor> doc_list = new ArrayList<Doctor>();   // list of doctors in the hospital
        int noOfPatients = 0;
        int choice = 0;
        int tempInt = -1;
        String tempString = "";
        Scanner sc = new Scanner(System.in);
        while(choice != 6){
            choice = menu();
            switch(choice){
                case 1:
                    Doctor doc = new Doctor();
                    doc.getData();
                    doc.generateDocID(doc.returnName(), doc_list.size() + 1);
                    doc_list.add(doc);
                    System.out.println("Auto-generated Doctor ID: " + doc.returnID());
                    break;
                case 2:
                    Patient pat = new Patient();
                    if(doc_list.isEmpty()){
                        System.out.println("No Doctors Available! Kindly Contact the Management!");
                        break;
                    }
                    // assign the patient to a random doctor
                    // (might change this feature later, to add doctor specification)
                    tempInt = (int)(Math.random()*(doc_list.size()));
                    pat.getData();
                    tempString = pat.returnName();
                    noOfPatients++;
                    System.out.println("Auto-generated Patient ID: " + doc_list.get(tempInt).addPatient(tempString, pat, noOfPatients));
                    doc_list.set(tempInt, doc_list.get(tempInt));
                    System.out.println("The patient has been assigned to Dr. " + doc_list.get(tempInt).returnName() + ".");
                    break;
                case 3:
                    System.out.println("Enter Patient ID:");
                    tempString = sc.nextLine();
                    int flag = 0;
                    for(Doctor d : doc_list){
                        if(d.doesPatientExists(tempString) == true){
                            flag = 1;
                            d.showSinglePatientData(tempString);
                            System.out.println("Assigned Doctor:\n");
                            d.showDoctorData();
                            break;
                        }
                    }
                    if(flag == 0){
                        System.out.println("Patient ID does not exists!");
                        break;
                    }
                    break;
                case 4:
                    if(doc_list.isEmpty()){
                        System.out.println("No Doctors Available! Kindly Contact the Management!");
                        break;
                    }
                    System.out.println("Enter Doctor ID: ");
                    tempString = sc.nextLine();
                    flag = 0;
                    for(Doctor d : doc_list ){
                        if(tempString.equals(d.returnID())){
                            flag = 1;
                            d.showAllPatients();
                        }
                    }
                    if(flag == 0){
                        System.out.println("Doctor ID does not exists!");
                        break;
                    }
                    break;
                case 5:
                    if(doc_list.isEmpty()){
                        System.out.println("No Doctors Available! Kindly Contact the Management!");
                        break;
                    }
                    for(Doctor d : doc_list){
                        d.showDoctorData();
                        System.out.println();
                    }
                    break;
                case 6:
                    break;
                default:
                    System.out.println("Invalid Choice!");
            }
        }
    }
}
