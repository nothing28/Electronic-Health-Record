This text document contains all the detailed information supporting the Requirements.doc

Note : In the Doctor Functionality class diagram where the doctor uses the DoctorEHRView() , we have written that the EHR is displayed in the same way the patient does ie. using DisplayEHR() and then further using class Display.

So please read in the following order : 
1 ) Requirements 
2 ) Patient Functionality
3 ) Doctor Functionality

Also if you require any further details about any class then it is listed below.

#class Login
variables:
input_chances : int : private : number of chances a user should get to login.
input_password : string : private : stores the password inputted by the user in every chance the user gets.

functions: 
LoginFunctionality : public
=> return type : bool
=> parameters : string : stores the correct password that the user should input to login.
=> Gives the user 'input_chances(5)' chances to login or kicks the user out of the system.



#class Display
variables : none

functions : 
DisplayMedicalInfo : public
=> return type : void
=> parameters : string [3] : the array of medical information to be displyed.
=> Displays the medical information in the EHR

DisplayPatients : public
=> return type : void
=> parameters : string [3] : the array of patients to be displayed.
=> Displays the list of Patients for the corresponding Doctor.



#class Patient
variables : none

functions: 
Patient : constructor : public
=> parameters : none
=> Welcomes/Greets the Patient.

PatientLogin : public
=> return type : void
=> parameters : PatientInfo
=> Lets the Patient log in.If the Patient logs in successfully then displays their EHR or kicks them out of the system.



#class Doctor
variables : 
is_doctor : bool : private : Checks if the user is a doctor or not.
edit_option : int : private : inputs the option number the Doctor wants to edit while editing an EHR.
edited : string : private : stores the new edited value of the corresponding value while editing an EHR.

functions : 
Doctor : constructor : public
=> parameters : none
=> Welcomes/Greets the Doctor.

DoctorLogin : public
=> return type : void
=> parameters : DoctorInfo
=> Lets the Doctor log in.If the Doctor logs in successfully then displays the list of their patients or kicks them out of the system.

DoctorEHRView : public
=> return type : void
=> parameters : DoctorInfo
=> Lets the Doctor view the EHR of a particular Patient.

DoctorEHREdit : public
=> return type : void
=> parameters : DoctorInfo
=> Lets the Doctor edit the EHR of a particular Patient.






