#include "BookingViewDataMenu.h"
#include "../../../Booking/Manager/BookingManager.h"
#include "../../Control/Calendar/CalendarControl.h"
#include "../BookingViewMenu/BookingViewMenu.h"
#include "../../../Utils/DataBase/DataBase.h"
#include "../../Control/Label/LabelControl.h"
#include "../../../Booking/Client/Client.h"
#include "../../../Booking/Booking.h"
#include "../../Window.h"

#pragma region constructor
BookingViewDataMenu::BookingViewDataMenu(Window* _owner) : super(_owner, BOOKINGVIEWDATAMENU){ }
#pragma endregion

#pragma region methods
void BookingViewDataMenu::Delete()
{
	BookingManager::Instance()->DeleteBooking(BookingViewMenu::CurrentBooking);
	ReturnToBookingView();
}
void BookingViewDataMenu::ReturnToBookingView()
{
	owner->SetCurrentMenu(BOOKINGVIEWMENU);
}
#pragma endregion

#pragma region override
void BookingViewDataMenu::Initialize()
{
	super::Initialize();
	ButtonControl* _returnControl = CreateButton(Rect(5, 5, 100, 20), TEXT("Return"));
	_returnControl->OnClick.SetDynamic(this, &BookingViewDataMenu::ReturnToBookingView);

	firstName = CreateLabel(Rect(10, 60, 250, 20), L"");
	lastName = CreateLabel(Rect(10, 90, 250, 20), L"");
	numberOfPeople = CreateLabel(Rect(10, 120, 250, 20), L"");
	calendar = CreateCalendar(Rect(10, 160, 250, 20));
	calendar->SetMaxSelected(15);

	ButtonControl* _deleteControl = CreateButton(Rect(5, 360, 100, 20), TEXT("Delete"));
	_deleteControl->OnClick.SetDynamic(this, &BookingViewDataMenu::Delete);

	isInitialized = true;
	Close();
}
void BookingViewDataMenu::Open()
{
	const Booking* _current = BookingViewMenu::CurrentBooking;
	if (_current == nullptr)
	{
		ReturnToBookingView();
		return;
	}
	const Client _client = _current->GetClient();
	firstName->SetText("First Name: " + _client.FirstName());
	lastName->SetText("Last Name: " + _client.LastName());
	numberOfPeople->SetText("Number Of People: " + std::to_string(_current->NumberOfPeople()));
	calendar->SetValue(_current->ArrivedDate(), _current->DepartureDate());
	titleControl->SetText("Booking of: " + _client.FirstName() + " " + _client.LastName());
	super::Open();
}
#pragma endregion
