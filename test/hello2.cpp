#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ncurses.h>
using namespace std;

#define BIT_SMART 0x1
#define TELE 0x2
#define TUN 0x4
#define ERAT 0x8

#define PICKUP 0x10
#define DESTROY 0x20
#define UNIQ 0x40
#define BOSS 0x80


class monster_desc
{
public:
	string name;
	string desc;
	vector<int> color;
	int speed[3];
	int abil;
	int hp[3];
	int dam[3];
	char symb;
	int rrty;
};

string getColorString(int i);
string intToAbil(int abil);
string getColorString(int i);
int finddice(int* ar, string s);
int getColorint(string t);
int get_abilities(string abil);

int main(int argc, char* argv[])
{

	ifstream f("monster_desc.txt");
	int j;
	string p,t,x;
        getline(f,p);
	//j = f.get();
        //cout<<(char)j<<endl;
        t.append(p);
        cout<<"let's see:" << t << endl;

        if (t.compare("RLG327 MONSTER DESCRIPTION 1\r")==0) cout<<"WE HAVE A MATCH"<<endl;
        else cout<<"WE DON'T HAVE A MATCH"<<endl;

        x.append(p, 0, p.length()-1);

        if (x.compare("RLG327 MONSTER DESCRIPTION 1")==0) cout<<"WE HAVE A MATCH"<<endl;
        else cout<<"WE DON'T HAVE A MATCH"<<endl;


	t = "";

	vector <monster_desc> monsters;


        while(getline(f, x))
        {
                if (x.compare("BEGIN MONSTER\r")==0)
                {
			monster_desc m;
			m.desc = "";

                        cout<<"\n\n---------Preparing to load the Monster---------\n\n";
                        while (1)
                        {
                                getline(f, x);

				if (x.compare("END\r")==0) break;

				stringstream stream(x);
				if (x.compare("\r")!=0)
				{
					while(1)
					{
					stream>>t;
					if (stream.eof()) break;

					if (t.compare("SPEED")==0)
					{
						cout<<"speed detected\n";
						stream>>t;
						//int ar[3];
						finddice(m.speed, t);
						//cout<<m.speed[0]<<"+"<< m.speed[1]<<"d"<<m.speed[2] <<endl;

					}
					else if (t.compare("DAM")==0)
					{
						cout<<"damage detected\n";
						stream>>t;
						finddice(m.dam, t);
						//cout<<m.dam[0]<<"+"<< m.dam[1]<<"d"<<m.dam[2] <<endl;

					}
					else if (t.compare("HP")==0)
					{
						cout<<"hitpoints detected\n";
						stream>>t;
						finddice(m.hp, t);
						//cout<<m.hp[0]<<"+"<< m.hp[1]<<"d"<<m.hp[2] <<endl;
					}
					else if (t.compare("RRTY")==0)
					{
						cout<<"rarity detected\n";
						stream>>t;
						m.rrty = stoi(t);
						//cout<<m.rrty<<endl;
					}
					else if (t.compare("SYMB")==0)
					{
						cout<<"symbol detected\n";
						stream>>t;
						m.symb = t[0];
						//cout<<m.symb<<endl;
					}
					else if (t.compare("COLOR")==0)
					{
						cout<<"color detected\n";
						stream>>t;
						while (!stream.eof())
						{
							m.color.push_back(getColorint(t));
							stream>>t;
						}

					}
					else if (t.compare("ABIL")==0)
					{
						cout<<"abilities detected\n";
						m.abil = 0;
						stream>>t;
						while (!stream.eof())
						{
							m.abil += get_abilities(t);
							stream>>t;
						}

					}
					else if (t.compare("NAME")==0)
					{
						cout<<"name detected\n";
						stream>>t;
						m.name.append(t);
						stream>>t;
						while (!stream.eof())
						{
							m.name.append(" ");
							m.name.append(t);
							stream>>t;
						}
						//cout<<m.color<<endl;
					}
					else if (t.compare("DESC")==0)
					{
						cout<<"description detected\n";
						int count = 0;
						getline(f, x);
						while(x.compare(".\r")!=0)
						{
							//count++;
							//if (count==3) break;
							//cout<<"entering the desc"<<endl;
							//getline(f, x);
							//cout<<x<<endl;
							x = x.substr(0, x.length()-1);
							m.desc.append(x);
							m.desc.append("\n");
							getline(f, x);
						}
						//cout<<m.desc;
					}
					else break;
					//cout<<t<<endl;
					}
				}
                                //cout<<x<<endl;
                        }
                        cout<<"\n\n------------Ending the load-------\n\n";
			monsters.push_back(m);
                }
        }
	cout<<"STARTNG TO LOAD THE VECTOR AND PRINTING THE ELEMENTS....\n";

	monster_desc m;
	for (int count = 0; count < monsters.size(); count++)
	{
		m = monsters[count];
		cout<<"Printing monster "<<count<<endl;
		cout<<m.name<<endl;
		cout<<m.desc;
		cout<<m.symb<<endl;
		cout<<intToAbil(m.abil)<<endl;
		for (int k = 0; k < m.color.size(); k++)
		{
			cout<<getColorString(m.color[k])<<" ";
		}
		cout<<endl;
		cout<<m.hp[0]<<"+"<< m.hp[1]<<"d"<<m.hp[2] <<endl;
		cout<<m.speed[0]<<"+"<< m.speed[1]<<"d"<<m.speed[2] <<endl;
		cout<<m.dam[0]<<"+"<< m.dam[1]<<"d"<<m.dam[2] <<endl;
		cout<<m.rrty<<endl;
		cout<<"ending print monster "<<count<<"\n\n";
	}

	cout<<"testing int consts in ncurses lib: "<<COLOR_BLUE<<endl;

	return 0;

}

int finddice(int* ar, string s)
{
	int i,j,k;
	i = 0;
	j = 0;

	string temp;

	for (k = 0; k < 3; k++)
	{
	while (s[i]<='9' && s[i]>='0') i++;
	temp = s.substr( j, i-j);
	j = stoi(temp);
	ar[k] = j;
	j = ++i;
	}

	return 0;



}
string getColorString(int i)
{
	if (i == 0) return "BLACK";
	else if (i == 1) return "RED";
	else if (i == 2) return "GREEN";
	else if (i == 3) return "YELLOW";
	else if (i == 4) return "BLUE";
	else if (i == 5) return "MAGENTA";
	else if (i == 6) return "CYAN";
	else return "WHITE";
}
int getColorint(string t)
{
	int col;
	if (t.compare("BLACK")==0) col = 0;
	else if (t.compare("RED")==0) col = 1;
	else if (t.compare("GREEN")==0) col = 2;
	else if (t.compare("YELLOW")==0) col = 3;
	else if (t.compare("BLUE")==0) col = 4;
	else if (t.compare("MAGENTA")==0) col = 5;
	else if (t.compare("CYAN")==0) col = 6;
	else if (t.compare("WHITE")==0) col = 7;
	else col = -1;
	return col;
}
int get_abilities(string abil)
{
	if (abil.compare("SMART")==0) return 0x1;
	else if (abil.compare("TELE")==0) return 0x2;
	else if (abil.compare("TUN")==0) return 0x4;
	else if (abil.compare("ERAT")==0) return 0x8;
	else if (abil.compare("PICKUP")==0) return 0x10;
	else if (abil.compare("DESTROY")==0) return 0x20;
	else if (abil.compare("UNIQ")==0) return 0x40;
	else if (abil.compare("BOSS")==0) return 0x80;
	else return 0;
}
string intToAbil(int abil)
{
	string abilities = "";
	if (abil & 0x1) abilities.append("SMART ");
	if (abil & 0x2) abilities.append("TELE ");
	if (abil & 0x4) abilities.append("TUN ");
	if (abil & 0x8) abilities.append("ERAT ");
	if (abil & 0x10) abilities.append("PICKUP ");
	if (abil & 0x20) abilities.append("DESTROY ");
	if (abil & 0x40) abilities.append("UNIQ ");
	if (abil & 0x80) abilities.append("BOSS ");

	return abilities;
}



// #define COLOR_BLACK	0
// #define COLOR_RED	1
// #define COLOR_GREEN	2
// #define COLOR_YELLOW	3
// #define COLOR_BLUE	4
// #define COLOR_MAGENTA	5
// #define COLOR_CYAN	6
// #define COLOR_WHITE	7
