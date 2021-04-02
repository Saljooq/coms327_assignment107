Name: Saljooq Altaf
Net ID: saltaf


Assignment 1.07


Same program as was submitted for 1.06 but with seven new methods as shown below:

1/ int print_monster_desc() - This method prints all the description of the
monsters in the monsters vector
2/ int parseMonstersDesc() - This is used to read into the monster_desc.txt and
initialize the monsters description class instances, they will be pushed to the monsters vector
3/ string getColorString(int i) - This is used to get the string color depending
on the int as per the ncurses library
4/ string intToAbil(int abil) - This takes the ability bit-vector and tells all the
abilities in string by conversion - via bit-wise-operations
5/ int finddice(int* ar, string s) - This converts the string into 3 int set*
6/ int getColorint(string t) - This is used to the exact int of the color
depending on the string as per the ncurses library
7/ int get_abilities(string abil) - This should get us the bit from the bitvector of the abilities
and determine which ability it corresponds to and converts those to string


And one new class of monster description with all the characteristics for initializing
monsters later on. The dice-decided variables are an array of 3 ints.

The total changes to main are in line 527-529, the three lines are reproduced below:

parseMonstersDesc();
print_monster_desc();
return 0;

NOTE:
monster_desc.txt sample on piazza ended with '\r' on every line. However, same file
saved in the ~/.rlg321/ directory did not end with '\r'. My current implementation does not
take into account ending with '\r', However, an adjustment with 4-5 lines of code can fix this,
since I have already written the code for that situation.
Let me know via saltaf@iastate.edu if there's any issue with parsing the file.
