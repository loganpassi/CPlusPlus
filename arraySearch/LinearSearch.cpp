//Logan Passi
//LinearSearch.cpp
//03/06/2017
//Function definition to perform the linear search
//for an integer array


int linearSearch(const int list[], int numElems, int value)
{
	int position = -1; //location of found element
	bool found = false; //flag representing search status
	//loop until found or end of array is reached
	for (int index = 0; index < numElems && !found; index++)
	{
		if (list[index] == value)
		{
			found = true;
			position = index;
		}
	}
	return position;
}
