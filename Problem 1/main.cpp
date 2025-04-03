#include <iostream>

using namespace std;

// Create Guest Class
class Guest
{
public:
    // Initialize Attributes
    string name;
    string contact;
    string iftar_date;
    Guest *nextGuest;
    // Initialize Default Constructor
    Guest()
    {
        name = "";
        contact = "";
        iftar_date = "";
        nextGuest = nullptr;
    }
    // Initialize Parameterize Constructor
    Guest(string Name , string Contact , string Iftar_date) :
    name(Name) , contact(Contact) , iftar_date(Iftar_date) , nextGuest(nullptr)
    {
    }
    // Deep Copy Constructor
    Guest (Guest &g)
    {
        name = g.name;
        contact = g.contact;
        iftar_date = g.iftar_date;
        nextGuest = nullptr;
    }
    // Display Guest Info Method
    void display_guest()
    {
        cout << "Guest:" << name << ", Contact:" << contact << ", Iftar Date: " << iftar_date <<endl;
    }
    // Send a Reminder For a Guest Method
    void sendReminder()
    {
        cout << "Reminder sent to " << name << ": Your Iftar invitation is on " << iftar_date << "!" <<endl;
    }
    // Update Invitation Method
    void update_invitation(string new_date)
    {
        // Assign The new Date To The old Date
        iftar_date = new_date;
        cout << "Updating invitation for " << name << "..." <<endl;
    }
};

// Create Iftar Manager Class
class IftarManager
{
private:
    // Initialize Attributes
    Guest *headGuest;
    int no_guests;
    // compare dates function return true if date1 is less than date2
    bool compareDates(string date1 , string date2)
    {
        if (stoi(date1.substr(0 , 4)) < stoi(date2.substr(0 , 4)))
            return true;
        if (stoi(date1.substr(5 , 2)) < stoi(date2.substr(5 , 2)))
            return true;
        if (stoi(date1.substr(8 , 2)) < stoi(date2.substr(8 , 2)))
            return true;
        return false;
    }
public:
    // Initialize Default Constructor
    IftarManager()
    {
        headGuest = nullptr;
        no_guests = 0;
    }
    // Add Guest Method
    void add_guest(Guest guest)
    {
        // Initialize a New Guest
        Guest *newGuest = new Guest(guest);
        // If there is no guests, assign new guest to the head guest
        if (!headGuest)
        {
            headGuest = newGuest;
        }
        else
        {
            // initialize temp guest
            Guest *tempGuest = headGuest;
            // while temp guest has next guest
            while (tempGuest->nextGuest)
            {
                // assign the next guest of the temp guest to temp guest
                tempGuest = tempGuest->nextGuest;
            }
            // assign new guest the next guest of the temp guest
            tempGuest->nextGuest = newGuest;
        }
        // increase number of guests by one
        no_guests++;
    }
    // remove guest method
    void remove_guest(string name)
    {
        // if there is noe head guest that means that there is no guests
        if (!headGuest)
        {
            cout << "Guest not found." <<endl;
        }
        else {
            // if head guest's name equal to wanted name
            // delete this guest and decrease number of guests by one
            if (headGuest->name == name)
            {
                Guest *deleteGuest = headGuest;
                headGuest = headGuest->nextGuest;
                cout << "Removing " << name << "..." <<endl;
                delete deleteGuest;
                no_guests--;
            }
            else
            {
                Guest *tempGuest = headGuest;
                // while temp guest has next guest and the name of the next guest not equal to the wanted name
                while (tempGuest->nextGuest && tempGuest->nextGuest->name != name)
                {
                    // assign the next guest of the temp guest to temp guest
                    tempGuest = tempGuest->nextGuest;
                }
                // if temp guest has next guest
                // delete this next guest and decrease number of guests by one
                if (tempGuest->nextGuest)
                {
                    Guest *deleteGuest = tempGuest->nextGuest;
                    tempGuest->nextGuest = tempGuest->nextGuest->nextGuest;
                    cout << "Removing " << name << "..." <<endl;
                    delete deleteGuest;
                    no_guests--;
                }
                // that means that the wanted guest not found
                else
                {
                    cout << "Guest not found." <<endl;
                }
            }
            cout <<endl;
        }
    }
    // display guest info method
    void display_all_guests()
    {
        // if there is a head guest
        if (headGuest)
        {
            // assign head guest to temp guest
            Guest *tempGuest = headGuest;
            // while temp guest has next guest
            while (tempGuest->nextGuest)
            {
                // display info of temp guest
                tempGuest->display_guest();
                // assign the next guest of the temp guest to temp guest
                tempGuest = tempGuest->nextGuest;
            }
            // display info of temp guest
            tempGuest->display_guest();
        }
        // that means that there is no guests
        else
        {
            cout << "There is no guests right now." <<endl;
        }
        cout <<endl;
    }
    // update guest invitation method
    void update_guest_invitation(string name , string new_date)
    {
        // if there is no head guest that means that there is no guests
        if (!headGuest)
        {
            cout << "Guest not found." <<endl;
        }
        else {
            // if head guest's name equals to wanted name
            // update the invitation of the head guest
            if (headGuest->name == name)
            {
                headGuest->update_invitation(new_date);
            }
            else
            {
                // assign head guest to temp guest
                Guest *tempGuest = headGuest;
                // while temp guest has next guest and the name of the next guest not equal to the wanted name
                while (tempGuest->nextGuest && tempGuest->nextGuest->name != name)
                {
                    // assign the next guest of the temp guest to temp guest
                    tempGuest = tempGuest->nextGuest;
                }
                // if temp guest has next guest
                if (tempGuest->nextGuest)
                {
                    // update the invitation of the next guest
                    tempGuest->nextGuest->update_invitation(new_date);
                }
                // that means that there is no guests
                else
                {
                    cout << "Guest not found." <<endl;
                }
            }
        }
        cout << endl;
    }
    // send a reminder method
    void send_reminder(string date)
    {
        cout << "Sending reminders..." <<endl;
        // if there is no head guest that means that there is no guests
        if (!headGuest)
        {
            cout << "Guest not found." <<endl;
        }
        else
        {
            // assign head guest to temp guest
            Guest *tempGuest = headGuest;
            // initialize boolean variable and make it false
            bool found = false;
            // while temp guest has next guest
            while (tempGuest->nextGuest)
            {
                // if iftar date of the temp guest equals to wanted date
                if (tempGuest->iftar_date == date)
                {
                    // send reminder to temp guest and make found true
                    tempGuest->sendReminder();
                    found = true;
                }
                // assign the next guest of the temp guest to temp guest
                tempGuest = tempGuest->nextGuest;
            }
            // if iftar date of the temp guest equals to wanted date
            if (tempGuest->iftar_date == date)
            {
                // send reminder to temp guest and make found true
                tempGuest->sendReminder();
                found = true;
            }
            cout << endl;
            // if found is true that means that there is at least one user has this date
            if (found)
            {
                cout << "May your Iftar gatherings be full of warmth and blessings!" <<endl;
            }
            // that means that there is no users with this date
            else
            {
                cout << "Guest not found." <<endl;
            }
        }
        cout << endl;
    }

    // sort guest list method using selection sort
    void sort_guest_list() {
        // if there is no head guest or there is no next guest for the head guest that means thet the
        // number of guests is less than two so, it is already sorted
        if (!headGuest || !headGuest->nextGuest)
            return;
        // assign head guest to cur
        Guest *cur = headGuest;
        while (cur) {
            // assign cur to min guest and next guest of the cur to nextG
            Guest *minGuest = cur , *nextG = cur->nextGuest;
            // while nextG not null
            while (nextG) {
                // if iftar date of nextG is less than iftar date of min guest
                if (compareDates(nextG->iftar_date , minGuest->iftar_date)) {
                    // assign nextG to min guest
                    minGuest = nextG;
                }
                // assign the next guest of nextG to nextG
                nextG = nextG->nextGuest;
            }
            // if min guest not equal cur then swap all data between them
            if (minGuest != cur) {
                swap(minGuest->name, cur->name);
                swap(minGuest->contact, cur->contact);
                swap(minGuest->iftar_date, cur->iftar_date);
            }
            // assign next guest of the cur to cur
            cur = cur->nextGuest;
        }
    }
    // initialize destructor
    ~IftarManager() {
        // assign head guest to temp guest
        Guest *tempGuest = headGuest;
        // while temp guest not null
        while (tempGuest) {
            // assign the next guest of the temp guest to nextG , delete temp guest and assign nextG to temp guest
            Guest *nextG = tempGuest->nextGuest;
            delete tempGuest;
            tempGuest = nextG;
        }
        // make head guest null
        headGuest = nullptr;
    }

};

int main() {
// Create Iftar Manager
    IftarManager manager = IftarManager();
// Add guests
    Guest guest1 = Guest("Aisha", "aisha@example.com", "2025-03-15");
    Guest guest2 = Guest("Omar", "omar@example.com", "2025-03-18");
    Guest guest3 = Guest("Zainab", "zainab@example.com", "2025-03-20");
    manager.add_guest(guest1);
    manager.add_guest(guest2);
    manager.add_guest(guest3);
// Display guest list
    manager.display_all_guests();
// Update invitation date for Omar
    manager.update_guest_invitation("Omar", "2025-03-15");
// Display updated guest lis
    manager.display_all_guests();
// Send reminders
    manager.send_reminder("2025-03-15");
    // sort guests
    manager.update_guest_invitation("Omar", "2025-03-9");
    manager.update_guest_invitation("Zainab", "2025-03-7");
    manager.sort_guest_list();
    manager.display_all_guests();
    // remove guest
    manager.remove_guest("Omar");
    manager.display_all_guests();
    return 0;
}
