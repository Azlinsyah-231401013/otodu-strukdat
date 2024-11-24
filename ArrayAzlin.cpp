#include <iostream>
#include <string>
using namespace std;

struct Schedule {
    string subject;
    string timeSlot;
};

const int MAX_SCHEDULES = 10;
Schedule schedules[MAX_SCHEDULES];
int scheduleCount = 0;

void displayTimeSlots() {
    cout << "\nPilih jam ajar:\n";
    cout << "1. 13.00 - 14.00\n";
    cout << "2. 14.00 - 15.00\n";
    cout << "3. 16.00 - 17.00\n";
    cout << "Masukkan pilihan (1/2/3): ";
}

string getTimeSlot(int choice) {
    switch (choice) {
    case 1:
        return "13.00 - 14.00";
    case 2:
        return "14.00 - 15.00";
    case 3:
        return "16.00 - 17.00";
    default:
        return "Invalid";
    }
}

void addSchedule() {
    if (scheduleCount >= MAX_SCHEDULES) {
        cout << "\nJadwal penuh, tidak dapat menambahkan lebih banyak.\n";
        return;
    }

    string subject;
    int timeChoice;


    cout << "\n-- Tambah Jadwal Belajar --\n";
    cout << "Apa yang ingin dipelajari? ";
    cin.ignore(); // Clear input buffer
    getline(cin, subject);

    displayTimeSlots();
    cin >> timeChoice;

    string selectedTime = getTimeSlot(timeChoice);
    if (selectedTime == "Invalid") {
        cout << "\nPilihan waktu tidak valid. Jadwal tidak ditambahkan.\n";
        return;
    }

    schedules[scheduleCount].subject = subject;
    schedules[scheduleCount].timeSlot = selectedTime;
    scheduleCount++;

    cout << "\nJadwal berhasil ditambahkan:\n";
    cout << "- Materi: " << subject << "\n";
    cout << "- Waktu: " << selectedTime << "\n";
}

void viewSchedules() {
    if (scheduleCount == 0) {
        cout << "\nBelum ada jadwal yang ditambahkan.\n";
        return;
    }

    cout << "\n-- Jadwal Belajar --\n";
    for (int i = 0; i < scheduleCount; i++) {
        cout << i + 1 << ". Materi: " << schedules[i].subject
             << ", Waktu: " << schedules[i].timeSlot << "\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== MENU OTODU =====\n";
        cout << "1. Tambah Jadwal\n";
        cout << "2. Lihat Jadwal\n";
        cout << "3. Keluar\n";
        cout << "Masukkan pilihan (1/2/3): ";
        cin >> choice;

        switch (choice) {
        case 1:
            addSchedule();
            break;
        case 2:
            viewSchedules();
            break;
        case 3:
            cout << "\nTerima kasih telah menggunakan program ini!\n";
            break;
        default:
            cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 3);

    return 0;
}
