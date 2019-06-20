#include <iostream>			// For input/output
#include <ctime>			// For current datetime

// Standard namespace
using namespace std;

int main(){
	
	// Calender time of the system in number of seconds since January 1, 1970
	time_t now = time(0);
	
	// Pointer to the string format of date 
	char* dt = ctime(&now);
	
	// Output date and time 
	cout << "The local time and date is: " << dt << endl;
	
	// Arrays of days of the week
	string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	// Array of months
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August",
	"September", "October", "November", "December"};
	
	// Pointer to tm structure of localtime
	tm* ltm = localtime(&now);
	
	// Use tm_year to return the number of years since 1900
	int year = 1900 + ltm->tm_year;	
	// Use tm_month as index in months array to get the current month
	string month = months[ltm->tm_mon];
	// Use tm_wday as index in days array to get the current day of the week
	string day = days[ltm->tm_wday];
	// Use tm_mday to get the current date 
	int date = ltm->tm_mday;
	
	// Character array to store the number of hours
	char hours[3];
	// If the number of hours is less than 10 format the string to include a zero before it
	if(ltm->tm_hour < 10){
		sprintf(hours, "0%d", ltm->tm_hour);
	}
	else{
		sprintf(hours, "%d", ltm->tm_hour);
	}
	
	// Character array to store the number of minutes
	char mins[3];
	// If the number of minutes is less than 10 format the string to include a zero before it
	if(ltm->tm_min < 10){
		sprintf(mins, "0%d", ltm->tm_min);
	}
	else{
		sprintf(mins, "%d", ltm->tm_min);
	}
	
	// Character array to store the number of seconds
	char secs[3];
	// If the number of seconds is less than 10 format the string to include a zero before it
	if(ltm->tm_sec < 10){
		sprintf(secs, "0%d", ltm->tm_sec);
	}
	else{
		sprintf(secs, "%d", ltm->tm_sec);
	}

	// Output the year, month, date and weekday
	cout << "Year: " << year << endl;
	cout << "Month: " <<  month << endl;
	cout << "Date: " <<  date << endl;
	cout << "Day: " <<  day << endl;
	
	// Depending on the hour change the greeting and display the time
	if(ltm->tm_hour < 12){
		cout << "Good morning, the time is: " << hours << ":" << mins << ":" << secs <<  endl;
	}
	else if(ltm->tm_hour < 18){
		cout << "Good afternoon, the time is: " << hours << ":" << mins << ":" << secs << endl;
	}
	else{
		cout << "Good evening, the time is: " << hours << ":" << mins << ":" << secs <<  endl;
	}

	// End program
	return 0;
}