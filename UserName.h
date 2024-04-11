#ifndef USER
#define USER
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>

class UserName {
private:
    char NameUser[20];
    char PhoneUser[11];
    char MailUser[15];
    char ID[10];
    char Shift[2];
    char Day[10];

public:
  
    void setName(char name[]) {
        strncpy(NameUser, name, sizeof(NameUser) - 1);
        NameUser[sizeof(NameUser) - 1] = '\0'; // Đảm bảo kết thúc chuỗi
    }
    void setPhone(char phone[]) {
        strncpy(PhoneUser, phone, sizeof(PhoneUser) - 1);
        PhoneUser[sizeof(PhoneUser) - 1] = '\0';
    }
    void setMail(char mail[]) {
        strncpy(MailUser, mail, sizeof(MailUser) - 1);
        MailUser[sizeof(MailUser) - 1] = '\0';
    }
    void setID(char id[]) {
        strncpy(ID, id, sizeof(ID) - 1);
        ID[sizeof(ID) - 1] = '\0';
    }
    void setShift(char shift[]) {
        strncpy(Shift, shift, sizeof(Shift) - 1);
        Shift[sizeof(Shift) - 1] = '\0';
    }
    void setDay(char day[]) {
        strncpy(Day, day, sizeof(Day) - 1);
        Day[sizeof(Day) - 1] = '\0';
    }
    char* getNameUser() {
        return NameUser;
    }

    char* getPhoneUser() {
        return PhoneUser;
    }

    char* getMailUser() {
        return MailUser;
    }

    char* getID() {
        return ID;
    }

    char* getShift() {
        return Shift;
    }
    char* getDay() {
        return Day;
    }

   
};

#endif