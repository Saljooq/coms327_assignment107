#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class monster_desc
{
public:
	string name;
	string desc;
	string color;
	int speed[3];
	string abil;
	int hp[3];
	int dam[3];
	char symb;
	int rrty;
};



int finddice(int* ar, string s);

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
						int ar[3];
						finddice(ar, t);
						cout<<ar[0]<<endl;
						cout<<ar[1]<<endl;
						cout<<ar[2]<<endl;
					}
					else
					cout<<t<<endl;
					}
				}
                                //cout<<x<<endl;
                        }
                        cout<<"\n\n------------Ending the load-------\n\n";
			monsters.push_back(m);
                }
        }


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
