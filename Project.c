#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LETTERS 100
int main(){
    char line[MAX_LETTERS];
    char patient_name_in_info[MAX_LETTERS],name_in_file_info[MAX_LETTERS],name_booking[MAX_LETTERS],name_booking_view[MAX_LETTERS];
    int age,social_security_number,age_add,security_number_add;
    long long int social_security_number_discount;
    char illness[MAX_LETTERS],illness_add[MAX_LETTERS];
    char date[MAX_LETTERS],date_view[MAX_LETTERS],history[MAX_LETTERS];
    char name_add[MAX_LETTERS];
    float price;
    FILE*P_info=fopen("Patients_information.txt","a+");
    FILE*P_history=fopen("Patients_history.txt","r");
    FILE*P_booking=fopen("Appointment_Booking.txt","a");
    FILE*P_booking_read=fopen("Appointment_Booking.txt","r");
    if(P_info==NULL || P_history==NULL || P_booking==NULL || P_booking_read==NULL){
        printf("Error opening file.\n");
        return 1;
    }
    int choose=0;
    while(choose!=7){
    printf("1. View patient information\n2. Add a patient\n3. Add an appointment\n4. View a list of appointments\n5. Billing\n6. View the list of discounts\n7. Exit\n");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:
    printf("Enter the patient's name: ");
    scanf("%s",patient_name_in_info);
    while(fgets(line,sizeof(line),P_info)){
        if(sscanf(line,"%s %d %d %999[^\n]",name_in_file_info,&age,&social_security_number,illness)==4){
            if(strcmp(name_in_file_info,patient_name_in_info)==0){
            printf("The patient information:\nName: %s\nAge: %d\nSocial sicuruty number: %d\nIllness: %s\n",name_in_file_info,age,social_security_number,illness);
        }
        } 
    }
     while(fgets(line,sizeof(line),P_history)){
        char *history =strtok(line,",");
        if(history !=NULL && strcmp(history,patient_name_in_info)==0){
            if(history !=NULL){
               history=strtok(NULL,",");
               printf("The Patient's medical history: %s\n",history); 
            }
            }
    }
    break;
    case 2:
    printf("Enter the patient's name:\n");
    scanf("%s",name_add);
    printf("Enter the patient's age:\n");
    scanf("%d",&age_add);
    printf("Enter the patient's Social Security number:\n");
    scanf("%d",&security_number_add);
    printf("Enter the patient's illness:\n");
    getchar();
    fgets(illness_add,sizeof(illness_add),stdin);
    illness_add[strcspn(illness_add, "\n")] = '\0';
    fputs(name_add,P_info);
    fputs(" ",P_info);
    fprintf(P_info,"%d",age_add);
    fputs(" ",P_info);
    fprintf(P_info,"%d",security_number_add);
    fputs(" ",P_info);
    fputs(illness_add,P_info);
    fputs("\n",P_info);
    printf("The patient has been added successfully.\n");
    break;
    case 3:
    printf("Enter the patient name:\n");
       scanf("%s",name_booking);
       fputs(name_booking,P_booking);
       fputs(" ",P_booking);
    printf("Enter the appointment date yyyy/mm/dd.\n");
       scanf("%s",date);
       fputs(date,P_booking);
       fputs("\n",P_booking);
       printf("An appointment has been added successfully\n");
    break; 
    case 4:
    printf("The list of appointments:\n");
    while (fscanf(P_booking_read,"%s %s",name_booking_view,date_view)!=EOF)
    {
        printf("Patient name: %s | Appointment date: %s\n",name_booking_view,date_view);
    }
    break;
    case 5:
    printf("Enter the price: ");
    scanf("%f",&price);
    printf("Enter the patient's Social Security number: ");
    scanf("%lld",&social_security_number_discount);
    int first_three_digits=social_security_number_discount/10000000;
        switch (first_three_digits)
        {
        case 123:
        price *=0.30;
        printf("The price is: %.1f\n",price);
        break;
        case 753:
        price *=0.40;
        printf("The price is: %.1f\n",price);
        break;
        case 437:
        price *=0.50;
        printf("The price is: %.1f\n",price);
        break;
        case 675:
        price *=0.60;
        printf("The price is: %.1f\n",price);
        break;
        case 454:
        price *=0.70;
        printf("The price is: %.1f\n",price);
        break;
        default:
        price *=0.20;
        printf("The price is: %.1f\n",price);
        break;
        }
    break;
    case 6:
    printf("Cancer: 70%% off.\nDiabetes: 60%% off.\nArthritis: 50%% off.\nHypothyroidism: 40%% off.\nBlood clotting 30%% off.\nOther: 20%% off.\n");
    break;
    case 7:
    printf("Exiting...\n");
    break;
    default:
    printf("ERROR,Try again later.");
    break;
    }
    }
    fclose(P_info);
    fclose(P_history);
    fclose(P_booking);
    fclose(P_booking_read);
    return 0;
}