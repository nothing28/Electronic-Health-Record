#include <iostream>
#include "./HeaderFiles/Login.h"
#include "./HeaderFiles/Display.h"

using namespace std;

//Doctor struct
struct DoctorInfo
{
    std::string doctor_password;
    std::string patient_list[3];
};

//Patient struct
struct PatientInfo
{
    //Basic information
    std::string patient_name;
    std::string patient_password;
    int age;
    std::string gender;
    //Medical information
    std::string current_medications[3];
    std::string prev_diseases[3];
    std::string allergies[3];
    bool medical_insurance;
};

//Displays the EHR of the given Patient
void DisplayEHR(PatientInfo pat)
{
    Display d;
    //Basic Information
    cout << "*** Basic Information ***" << endl;
    cout << "# Patient Name : " << pat.patient_name << endl;
    cout << "# Age : " << pat.age << endl;
    cout << "# Gender : " << pat.gender << endl;

    //Medical Information
    cout << "*** Medical Information ***" << endl;
    cout << "# Current Medications : ";
    d.DisplayMedicalInfo(pat.current_medications);
    cout << "# Previous Diseases : ";
    d.DisplayMedicalInfo(pat.prev_diseases);
    cout << "# Allergies : ";
    d.DisplayMedicalInfo(pat.allergies);

    //medical insurance status
    cout << "Medical insurance : " << ((pat.medical_insurance) ? "Yes" : "No") << endl;

    cout << "Have a nice day :-) \n"
         << endl;
}

class Patient
{
public:
    Patient()
    {
        //Welcomes the Patient.
        cout << "Welcome Patient!" << endl
             << "We hope you are doing fine." << endl;
        cout << endl;
    }
    void PatientLogin(PatientInfo pat)
    {
        //Lets the Patient log into the system.
        //Displays the EHR if the Patient enters the correct password.
        Login l;
        if (l.LoginFunctionality(pat.patient_password))
        {
            DisplayEHR(pat);
        }
    }
};

class Doctor
{
private:
    bool is_doctor = false;
    int edit_option;
    string edited;

public:
    Doctor()
    {
        //Welcomes the Doctor.
        cout << "Welcome Doctor!" << endl
             << "We hope you are doing fine." << endl;
    }

    void DoctorLogin(DoctorInfo doc)
    {
        //Lets the Doctor log into the system.
        //Displays the list of the patients if Doctor enters the correct password.
        Login l;
        if (l.LoginFunctionality(doc.doctor_password))
        {
            is_doctor = true;
            Display d;
            d.DisplayPatients(doc.patient_list);
        }
    }

    void DoctorEHRView(PatientInfo pat)
    {
        //Lets the Doctor view the EHR of the Patient he/she wants to see.
        //(Only if they are logged in, otherwise tells them to login).
        if (is_doctor)
        {
            DisplayEHR(pat);
        }
        else
        {
            cout << "Login as a doctor to view the EHR of all patients" << endl;
            cout << endl;
        }
    }

    void DoctorEHREdit(PatientInfo pat)
    {
        Display d;
        //Enables the doctor to edit the EHR of the corresponding Patient.
        //Also displays the updated EHR.
        //(Only if they are logged in, otherwise tells them to login).
        if (is_doctor)
        {
            cout << "Editing the EHR of " << pat.patient_name << "." << endl;
            cout << "Enter 0 to edit the current medications" << endl
                 << "Enter 1 to edit the previous diseases" << endl
                 << "Enter 2 to edit the allergies" << endl
                 << "Enter 3 to edit the status of the medical insurance" << endl
                 << "Enter your choice = ";
            cin >> edit_option;
            switch (edit_option)
            {
            //Editing the current medications
            case 0:
                cout << "# Current Medications : ";
                d.DisplayMedicalInfo(pat.current_medications);
                cout << endl;
                cout << "Enter the 1st medicine = ";
                cin >> edited;
                pat.current_medications[0] = edited;
                cout << "Enter the 2nd medicine = ";
                cin >> edited;
                pat.current_medications[1] = edited;
                cout << "Enter the 3rd medicine = ";
                cin >> edited;
                pat.current_medications[2] = edited;
                cout << endl
                     << "The new edited EHR is : " << endl;
                DisplayEHR(pat);
                break;
            case 1:
                cout << "# Current Previous Diseases : ";
                d.DisplayMedicalInfo(pat.prev_diseases);
                cout << endl;
                cout << "Enter the 1st disease = ";
                cin >> edited;
                pat.prev_diseases[0] = edited;
                cout << "Enter the 2nd disease = ";
                cin >> edited;
                pat.prev_diseases[1] = edited;
                cout << "Enter the 3rd disease = ";
                cin >> edited;
                pat.prev_diseases[2] = edited;
                cout << endl
                     << "The new edited EHR is : " << endl;
                DisplayEHR(pat);
                break;
            case 2:
                cout << "# Current Allergies : ";
                d.DisplayMedicalInfo(pat.allergies);
                cout << endl;
                cout << "Enter the 1st allergy = ";
                cin >> edited;
                pat.allergies[0] = edited;
                cout << "Enter the 2nd allergy = ";
                cin >> edited;
                pat.allergies[1] = edited;
                cout << "Enter the 3rd allergy = ";
                cin >> edited;
                pat.allergies[2] = edited;
                cout << endl
                     << "The new edited EHR is : " << endl;
                DisplayEHR(pat);
                break;
            case 3:
                pat.medical_insurance = ~pat.medical_insurance;
                cout << "Medical insurance status has been changed\n"
                     << endl;
                cout << "The updated EHR is :" << endl;
                DisplayEHR(pat);
                break;

            default:
                cout << "Enter a valid number" << endl;
                break;
            }
        }
        else
        {
            cout << "Login as a doctor to view the EHR of all patients" << endl;
            cout << endl;
        }
    }
};

int main()
{
    //Declaring doctors
    DoctorInfo doctor1 = {"YO1", {"Patient1", "Patient2", "Patient3"}};
    DoctorInfo doctor2 = {"YO2", {"Patient4", "Patient5", "Patient6"}};
    DoctorInfo doctor3 = {"YO3", {"Patient7", "Patient8", "Patient9"}};

    //Declaring patients
    PatientInfo Pat1 = {"Patient1", "yo1", 23, "male", {"med1", "med2", "med3"}, {"dis1", "dis2", "dis3"}, {"all1", "all2", "all3"}, false};
    PatientInfo Pat2 = {"Patient2", "yo2", 27, "female", {"med4", "med5", "med6"}, {"dis4", "dis5", "dis6"}, {"all4", "all5", "all6"}, false};
    PatientInfo Pat3 = {"Patient3", "yo3", 13, "male", {"med7", "med8", "med9"}, {"dis7", "dis8", "dis9"}, {"all7", "all8", "all9"}, false};
    PatientInfo Pat4 = {"Patient4", "yo4", 12, "female", {"med10", "med11", "med12"}, {"dis10", "dis11", "dis12"}, {"all10", "all11", "all12"}, false};
    PatientInfo Pat5 = {"Patient5", "yo5", 45, "male", {"med13", "med14", "med15"}, {"dis13", "dis14", "dis15"}, {"all13", "all14", "all15"}, false};
    PatientInfo Pat6 = {"Patient6", "yo6", 47, "female", {"med16", "med17", "med18"}, {"dis16", "dis17", "dis18"}, {"all16", "all17", "all18"}, true};
    PatientInfo Pat7 = {"Patient7", "yo7", 67, "male", {"med19", "med20", "med21"}, {"dis19", "dis20", "dis21"}, {"all19", "all20", "all21"}, true};
    PatientInfo Pat8 = {"Patient8", "yo8", 71, "female", {"med22", "med23", "med24"}, {"dis22", "dis23", "dis24"}, {"all22", "all23", "all24"}, true};
    PatientInfo Pat9 = {"Patient9", "yo9", 93, "male", {"med25", "med26", "med27"}, {"dis25", "dis26", "dis27"}, {"all25", "all26", "all27"}, true};

    // //Patient functionality
    // Patient p;
    // p.PatientLogin(Pat1);

    //Doctor functionality
    Doctor d;
    d.DoctorLogin(doctor1); //Doctor logs in.

    d.DoctorEHRView(Pat1); //Views the EHR of Patient1.
    d.DoctorEHRView(Pat2); //Views the EHR of Patient2
    d.DoctorEHRView(Pat3); //Views the EHR of Patient3

    d.DoctorEHREdit(Pat1); //Decides to edit the EHR of Patient1.
    d.DoctorEHREdit(Pat3); //Decides to edit the EHR of Patient3
}