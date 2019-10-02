#include <windows.h>
#include <iostream>
using namespace std;

int main(void) {
      char buffer[MAX_PATH], drive;

      *buffer = 0;
      GetCurrentDirectory(MAX_PATH, buffer);
      drive = *buffer;
      string typeName;
      switch(GetDriveType(NULL)) {
            case DRIVE_UNKNOWN:
                typeName = "DRIVE_UNKNOWN"; 
                break;
            case DRIVE_NO_ROOT_DIR:
                typeName = "DRIVE_UNKNOWN"; 
                break;
            case DRIVE_REMOTE:
                typeName = "DRIVE_REMOTE"; 
                break;
            case DRIVE_REMOVABLE:
                typeName = "DRIVE_REMOVABLE"; 
                break;
            case DRIVE_FIXED:
                typeName = "DRIVE_FIXED"; 
                break;
      }
      cout << "You are using the " << drive << ": drive." << endl;
      cout << "Driver Type " << typeName << endl;
      return 0;
}
/*

void decnumtobin(DWORD deci)

{

      DWORD input = deci;

      DWORD i;

      DWORD count = 0;

      DWORD binary[128];

     

      do

      {

            // Modulus 2 to get 1 or a 0

            i = input%2;

            // Load elements into the binary array

            binary[count] = i;

            // Divide input by 2 for binary decrement

            input = input/2;

            // Count the binary digits

            count++;

      }while (input > 0);

     

      // Reverse and output binary digits

      wprintf(L"The bitmask of the logical drives in binary: ");

      do

      {

            wprintf(L"%d", binary[count - 1]);

            count--;

      } while (count > 0);

      wprintf(L"\n");

}

 

int main()

{

      // Must give initial value and then let the

      // while loop iterates

      // There is weird thing here, we need to provide a space

      // at the beginning...what wrong here?

      WCHAR szDrive[] = L" A";

      // Get the logical drive mask

      DWORD uDriveMask = GetLogicalDrives();

 

      // Display the drive mask    

      wprintf(L"The bitmask of the logical drives in hex: 0X%.8X\n", uDriveMask);

      wprintf(L"The bitmask of the logical drives in decimal: %.8d\n", uDriveMask);

      decnumtobin(uDriveMask);

      wprintf(L"Initial dummy drive string: %s\n", szDrive);

     

      // Verify the returned drive mask

      if(uDriveMask == 0)

            wprintf(L"GetLogicalDrives() failed with error code: %d\n", GetLastError());

      else

      {

            wprintf(L"This machine has the following logical drives:\n");

            while(uDriveMask)      

            {

                  // use the bitwise AND, 1–available (1 & 1), 0-not available

                  // the binary representation is in reverse lol

                  if(uDriveMask & 1)

                  {

                        // Just print out the available drives

                        wprintf(L"Bitwise AND result = %u, drive %s\n", (uDriveMask & 1), szDrive);

                  }

                  // increment for next...

                  szDrive[1]++;

                  // shift the bitmask binary right

                  uDriveMask >>= 1;

            }

            wprintf(L"\n");

      }

      return 0;

}
*/