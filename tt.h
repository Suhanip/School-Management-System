#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include<fstream>
#include <map>

using namespace std;
class attendance{
    public:
  int mathat;
  int chemat;
  int phyat;
  int cseat;


      int show()
      {
        cout<<mathat<<setw(16)<<chemat<<setw(16)<<phyat<<setw(16)<<cseat<<endl;
      }

};

struct batch{
  map <int, string> batch;
} b [3];

int allotment(){
  attendance at;
  /*
  maths teacher can teach cse as well
  chem teacher can teach PHY as well
  phy teacher can teach CHEM as well
  cse teacher can teach maths as well
*/
  map <int, string> subject;
  subject.insert(pair<int,string>(0,"MATH"));
  subject.insert(pair<int,string>(1,"CHEM"));
  subject.insert(pair<int,string>(2,"PHY"));
  subject.insert(pair<int,string>(3,"CSE"));

  map <int, string>::iterator it0, it1, it2, temp;
  //predefine schedule of batch 0,1,2 on each day, schedule for a particular batch remain same on each day only changes in absence of teacher

  b [0].batch.insert (pair<int, string> (0, "MATH"));
  b [0].batch.insert (pair<int, string> (1, "CHEM"));
  b [0].batch.insert (pair<int, string> (2, "PHY"));
  b [0].batch.insert (pair<int, string> (3, "CSE"));

  b [1].batch.insert (pair<int, string> (0, "CSE"));
  b [1].batch.insert (pair<int, string> (1, "PHY"));
  b [1].batch.insert (pair<int, string> (2, "CHEM"));
  b [1].batch.insert (pair<int, string> (3, "MATH"));

  b [2].batch.insert (pair<int, string> (0, "CHEM"));
  b [2].batch.insert (pair<int, string> (1, "MATH"));
  b [2].batch.insert (pair<int, string> (2, "CSE"));
  b [2].batch.insert (pair<int, string> (3, "PHY"));

int a [4], i;
  cout << "give attendance for 4 teachers,for present enter 1 and for absent 0" << endl;
  for (int i = 0; i < 4; i++)
  {
    cout<<subject[i]<<" TEACHER : "<<endl;
    cin>>a[i];

  }


  fstream file;
  file.open("attend.dat",ios::in|ios::out|ios::app|ios::binary);
  at.mathat=a[0];
  at.chemat=a[1];
  at.phyat=a[2];
  at.cseat=a[3];
  file.write((char *) &at, sizeof(at));
  file.close();

  int br, j;
  int s, v;
  //manager has choice to select two batches who will have class on a particular day
cout << "allot classes to batches, choose from batch 0,batch 1,batch 2" << endl;
cin >> s >> v;
int count=0;
int check=1;
int stop=1;
int l = min (s,v);
int u = max (s,v);
  for(i = min (s,v); i <= max (s,v); i = max (s,v))
  {
      br = 0;
      if (l == i)
              it1 = b [max (s,v)].batch.begin ();

      else
              it1 = b [min (s, v)].batch.begin ();
      temp = b [i].batch.end ();
      temp--;
    for (j = 0, it0 = b[i].batch.begin (); it0 != b[i].batch.end () && j < 4; j++, ++it0) {

                            string s1 = temp->second;
                            string s2 = it1->second;
                if (a[j] || ((a[3-j] && s1 != s2)&&(stop==1)))//((3-(it0->first))!=(it1->first)))
                          cout << "Batch" << i << " period " << j << "is" << it0->second << endl;


                else if(a[3-j]&&stop>1)
                              cout << "Batch" << i << " period " << j << "is" << it0->second << endl;
                else
                    {  if (br <= 1)
                      {
                        cout << "Batch" << i << " period " << j << "is free" << endl;
                        br++;
                      }
                      else
                        cout << "Batch" << i << " period " << j << "is lab" << endl;
                      }
                    stop++;
              ++it1;
              temp--;
    }
    if (i == max (s,v))
        break;
}

  }
int show_attendance()
{
  int a=0;
  int b=0;
  int c=0;
  int d=0;
  fstream file;
  attendance at;
  file.open("attend.dat",ios::in|ios::binary);
  file.seekg(0);
  //cout<<"0";
  cout<<"\n";
  cout<<"maths"<<setw(15)<<"chem"<<setw(15)<<"phy"<<setw(15)<<"cse"<<endl;
  while(file.read((char*)&at,sizeof(at))){

    at.show();
    a=a+at.mathat;
    b=b+at.chemat;
    c=c+at.phyat;
    d=d+at.cseat;

  }
  cout<<setw(40)<<"THE MOST COMMITED TEACHER IS WITH HIGHEST NUMBER OF CLASSES"<<endl;
  cout<<a<<setw(16)<<b<<setw(16)<<c<<setw(16)<<d<<endl;
  file.close();

}
