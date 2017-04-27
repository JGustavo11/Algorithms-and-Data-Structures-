//Jose Hernandez
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// Function prototypes
void Garbage_Collect();  // Runs through the free list marking
void initFreeList();
void ins(string, int); // allow user to insert key
void del(string, int); // delete notes from free list
void menu();
void print();   



int H1 = -1, H2 = -1, freeHeader = 0;
string label[3] = { "Key ", "Next", "Mark" };
int listFREE[3][10];

void menu()
{
    int choice;
    string head;
    int key;
    char again;
    //do while the choice is not 5, if 5, quit 
    do
    {
        
        cout << "1. Print Memory" << endl;
        cout << "2. insert a new node" << endl;
        cout << "3. delete a node with key" << endl;
        cout << "4. Run Garbage Collect" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch (choice)
          {
            case 1:
            print();
            break;

            case 2:
            do
            {
                cout << "insert into H1 or H2?" << endl;
                cin >> head;
                cout << "Key value you wish to insert?" << endl;
                cin >> key;
                ins(head, key);
                cout << "Another insert? y for yes or n for no" << endl;
                cin >> again;
              } while (again == 'y' || again == 'Y');
            break;

            case 3:
            do
            {
              cout << "delete from H1 or H2?" << endl;
              cin >> head;
              cout << "Key value to delete?" << endl;
              cin >> key;
              del(head, key);
              cout << "Another delete? (Y/N)" << endl;
              cin >> again;
            } while (again == 'y' || again == 'Y');
            break;

            case 4:
            Garbage_Collect();
            break;
          }
      } while (choice != 5);
}

void initFreeList()
{
  int w = 1;
  for (int x = 0; x < 10; x++)
  {
    listFREE[2][x] = 0;
    if (w > 9)
    w = -1;
    listFREE[1][x] = w;
    w++;
  }
}


void print()
{
  for (int x = 0; x < 3; x++)
  {
    cout << label[x] << " ";
    for (int y = 0; y < 10; y++)
    {
      cout << "|" << setw(2) << listFREE[x][y] << " ";
    }
    cout << "|" << endl;
  }
}

void ins(string hdr_ptr, int key)
{
    int temporary = 0;
    int previousTemp = 0;
    int keyPos = 0;
    int x = 0;

    if(hdr_ptr == "H1" || hdr_ptr == "h1")
      {
        temporary = H1;
        if (H1 == -1)
        {
           
            while (listFREE[0][x] != NULL)
            {
              x++;
            }

            listFREE[0][x] = key;
            listFREE[1][x] = -1;
            H1 = x;
            freeHeader = x + 1;
        }
        else
        {
          
          while (listFREE[0][keyPos] != NULL)// Search for empty space
          {
            keyPos++;
          }
          // put in key 
            listFREE[0][keyPos] = key;
            listFREE[1][keyPos] = -1;
            freeHeader = keyPos + 1;
            while (listFREE[0][temporary] < key && listFREE[1][temporary] != -1)
            {
              // temp gets next
              previousTemp = temporary;
              temporary = listFREE[1][temporary];
            }
            if (listFREE[0][temporary] > key)
            {
              if (H1 == temporary)
                H1 = keyPos;
              else
                listFREE[1][previousTemp] = keyPos;
                listFREE[1][keyPos] = temporary;

                else
                {
                  // if we hit next -1, place into some empty space in freelist
                  listFREE[1][temporary] = keyPos;
                }
              }
          }
          else if (hdr_ptr == "H2" || hdr_ptr == "h2")
          {
            temporary = H2;
            if (H2 == -1)
            {
              // insert key into freelist 
              while (listFREE[0][x] != NULL)
              {
                x++;
              }
              listFREE[0][x] = key;
              listFREE[1][x] = -1;
              H2 = x;
              freeHeader = x + 1;
            }
            else
            {
              // Search for empty place
              while (listFREE[0][keyPos] != NULL)
              {
                keyPos++;
              }
              // Place key into listFREE
              listFREE[0][keyPos] = key;
              listFREE[1][keyPos] = -1;
              freeHeader = keyPos + 1;
              while (listFREE[0][temporary] < key && listFREE[1][temporary] != -1)
              {
                // temporary gets next
                previousTemp = temporary;
                temporary = listFREE[1][temporary];
              }
              if (listFREE[0][temporary] > key)
              {
                if (H2 == temporary)
                  H2 = keyPos;
                else
                listFREE[1][previousTemp] = keyPos;
                listFREE[1][keyPos] = temporary;
              }
              else
              {
                // if we hit next -1, place into some empty space in freelist
                listFREE[1][temporary] = keyPos;
              }
            }
          }
          else
          cout << "Error wrong type" << endl;
}


void del(string hdr_ptr, int key)
{
  int tempPrev = -1;
  if (hdr_ptr == "H1" || hdr_ptr == "h1")
  {
    int next = H1;
    
    while (listFREE[0][next] != key)// Search for the key to delete within the header list
    {
      tempPrev = next;
      next = listFREE[1][next];
    }
    // Header points to next key
    if (H1 == next)
      H1 = listFREE[1][next];
    else
      listFREE[1][tempPrev] = listFREE[1][next];
    }
    else if (hdr_ptr == "H2" || hdr_ptr == "h2")
    {
      int next = H2;
      // Search for the key to delete within the header list
      while (listFREE[0][next] != key)
      {
        tempPrev = next;
        next = listFREE[1][next];
      }
      // Header points to next key
      // else have previous key point to next next key
      if (H2 == next)
      H2 = listFREE[1][next];
      else
      listFREE[1][tempPrev] = listFREE[1][next];
    }
    else
      cout << "Wrong header" << endl;
}


void Garbage_Collect()
{
  int tempH1 = H1;
  int tempH2 = H2;
  int tempFree = freeHeader;
  while (listFREE[2][tempH1] != 1 && tempH1 != -1)
  {
    listFREE[2][tempH1] = 1;
    if (listFREE[1][tempH1] != -1)
      tempH1 = listFREE[1][tempH1];
  }

  while (listFREE[2][tempH2] != 1 && tempH2 != -1)
  {
    listFREE[2][tempH2] = 1;
    if (listFREE[1][tempH2] != -1)
    tempH2 = listFREE[1][tempH2];
  }

  while (listFREE[2][tempFree] != 1)
  {
    listFREE[2][tempFree] = 1;

    // Check for end of list
    if (listFREE[1][tempFree] != -1)
    tempFree = listFREE[1][tempFree];
  }
  for (int i = 0; i < 10; i++)
  {
    if (listFREE[2][i] == 0)
    {
      listFREE[1][i] = freeHeader;
      freeHeader = i;
    }
  }
}

int main()
{
  initFreeList();
  menu();
  system("pause");
  return 0;
}
