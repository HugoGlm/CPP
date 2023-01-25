#include "BookingMenu.h"
#include "../../Window.h"
#include "../../../Booking/Manager/BookingManager.h"
#include "../../Control/Calendar/CalendarControl.h"
#include "../../Control/Button/ButtonControl.h"
#include "../../../Utils/DataBase/DataBase.h"
#include "../../../Booking/Client/Client.h"
#include "../../../Utils/Rect/Rect.h"
#include "../../../Booking/Booking.h"

#pragma region constructor
BookingMenu::BookingMenu(Window* _owner) : super(_owner, BOOKINGMENU) { }
#pragma endregion

#pragma region methods
void BookingMenu::ReturnMainMenu()
{
	owner->SetCurrentMenu(MAINMENU);
}
void BookingMenu::SaveBooking()
{
	try
	{
		const int _numberOfPeople = std::stoi(numberOfPeople->CurrentTextStr());
		const Client _client = Client(firstName->CurrentTextStr(), lastName->CurrentTextStr());
		Booking* _booking = new Booking(calendar->ArrivedDate(), calendar->DepartureDate(), _client, _numberOfPeople);
		BookingManager::Instance()->RegisterBooking(_booking);
		messageControl->SetText(TEXT("Successful booking !"));
	}
	catch (const std::exception& e)
	{
		messageControl->SetText(TEXT("Error on create booking !"));
	}
}
#pragma endregion

#pragma region override
void BookingMenu::Initialize()
{
	super::Initialize();

	messageControl = CreateLabel(Rect(owner->Width() / 2, 50, 200, 20), TEXT(""));

	firstName = CreateTextField(Rect(10, 50, 255, 20), L"first name...");
	lastName = CreateTextField(Rect(10, 80, 255, 20), L"last name...");
	numberOfPeople = CreateTextField(Rect(10, 110, 255, 20), L"number of people");

	ButtonControl* _saveControl = CreateButton(Rect(60, 360, 150, 20), L"Save Booking");
	_saveControl->OnClick.SetDynamic(this, &BookingMenu::SaveBooking);

	ButtonControl* _returnControl = CreateButton(Rect(5, 5, 100, 20), TEXT("Return"));
	_returnControl->OnClick.SetDynamic(this, &BookingMenu::ReturnMainMenu);

	calendar = CreateCalendar(Rect(10, 140, 150, 150));
	calendar->SetMaxSelected(15);

	isInitialized = true;
	Close();
}
#pragma endregion
