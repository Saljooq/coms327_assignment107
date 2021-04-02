Name: Saljooq Altaf
Net ID: saltaf


Assignment 1.06


This was the same base program I have been working on from 1.01-1.05, with only a few changes that are stated below.

There were three major changes involved in porting the program to c++. One, all the structs became classes, with all the variables inside public.
Second, the malloc's were preceded by their type.
Third, the char* were changed to string. This involved using c_str() method where the argument needed to be char*, like fopen(...) etc.
There were no printf's that would've needed to be changed to cout.

To add the three new features to our game, three new methods had to be created.
The three features were
1/ limited 5x5 vision
2/ toggle key with 'f' where the whole dungeon should become visible
3/ teleport key 'g' using which our pc should be able to go anywhere

Three new methods to implement the above features were added and are elaborated below. Also, one new variable 'visible' was declared outside of main and is initialized to zero.

Additionally, a remembered array of chars, initialized to spaces is used. When we go to a new dungeon, this gets reintialized. It only gets updated with whatever is around pc.


1/ print_dungeon_limited(PC* pc) - this method is almost identical to print_dungeon used earlier, but it checked if visible was 1.
If visible was 1 then print as usual, else, it created spaces in place of the whole dungeon (from the remembered array), with only 5x5 around pc with the actual dungeon/monster.
The addition of pc argument ensures we know location of pc (since 5x5 illumination will be around that) instead of going through the array every time.

2/ teleport_controller(PC* pc, int& x, int& y) - pressing 'g' will take us to this controller, where pressing the same keys we use to move the pc are used to change '*' around.
We will remain in this mode till we press 'g' again. This will take pc directly to where '*' is. If there is a rock there, it will be tunneled, unless it is immutable.
If there is a monster there, then it will be killed. This whole process of teleporting - with multiple direction keys and two 'g' will count as one turn.
{movement is slightly different here than for regular pc, for instance pressing 9 will take keep moving the * to the right or/and top even if
we come across only one immutable wall, and will only stop until we're at the corner, movement becomes more fluid and easier with this,
since moving to a corner can be done if we keep pressing one key, I took more liberty since this is for debugging}

3/ print_teleport(PC* pc, int* x, int* y) - This is used by teleport controller and simply takes x and y as coordinates for '*' as its argument along with pc.
It simply places '*' at the very end - meaning it doesn't change the structure in any way on its own.
