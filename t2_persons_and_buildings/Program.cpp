// Program.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PersonsAndBuildings.h"
#include "Utils.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << " <database file>" << endl;
		return 1;
	}

	CPersonsAndBuildings personsAndBuildings(argv[1]);

	unsigned answer;
	do
	{
		cout << "Choose an action: " << endl;
		cout << "1. Print university list" << endl;
		cout << "2. Rename university" << endl;
		cout << "3. Remove university" << endl;
		cout << "4. Print university student list" << endl;
		cout << "5. Add university" << endl;
		cout << "6. Print student list" << endl;
		cout << "7. Edit student" << endl;
		cout << "8. Remove student" << endl;
		cout << "9. Add student" << endl;
		cout << "10. Print company list" << endl;
		cout << "11. Rename company" << endl;
		cout << "12. Remove company" << endl;
		cout << "13. Print company worker list" << endl;
		cout << "14. Add company" << endl;
		cout << "15. Print worker list" << endl;
		cout << "16. Edit worker" << endl;
		cout << "17. Remove worker" << endl;
		cout << "18. Add worker" << endl;
		cout << "19. Exit" << endl;

		try
		{
			answer = ReadUnsignedFromStreamLine();

			switch (answer)
			{
			case 1:
				personsAndBuildings.PrintUniversityList();
				break;

			case 2:
				personsAndBuildings.RenameUniversity();
				break;

			case 3:
				personsAndBuildings.RemoveUniversity();
				break;

			case 4:
				personsAndBuildings.PrintUniversityStudentList();
				break;

			case 5:
				personsAndBuildings.AddUniversity();
				break;

			case 6:
				personsAndBuildings.PrintStudentList();
				break;

			case 7:
				personsAndBuildings.EditStudent();
				break;

			case 8:
				personsAndBuildings.RemoveStudent();
				break;

			case 9:
				personsAndBuildings.AddStudent();
				break;

			case 10:
				personsAndBuildings.PrintCompanyList();
				break;

			case 11:
				personsAndBuildings.RenameCompany();
				break;

			case 12:
				personsAndBuildings.RemoveCompany();
				break;

			case 13:
				personsAndBuildings.PrintCompanyWorkerList();
				break;

			case 14:
				personsAndBuildings.AddCompany();
				break;

			case 15:
				personsAndBuildings.PrintWorkerList();
				break;

			case 16:
				personsAndBuildings.EditWorker();
				break;

			case 17:
				personsAndBuildings.RemoveWorker();
				break;

			case 18:
				personsAndBuildings.AddWorker();
				break;

			default:
				if (answer != 19)
				{
					cout << "Wrong action" << endl;
				}
			}
		}
		catch (exception const& e)
		{
			answer = 0;
			cout << e.what() << endl;
		}
	}
	while (answer != 19);

	personsAndBuildings.WriteUnsavedData();
	return 0;
}
