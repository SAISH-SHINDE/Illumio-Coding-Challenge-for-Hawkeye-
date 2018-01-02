#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstring>

using namespace std;

map<string,string> fipmap; // map to store the values of both first and second ip and port no. from NAT file. 
map<string, string> firstip;// map to store first ip address and first port from NAT file.
map<string, string> sipmap; // map to store the values of ip address and port no. from FLOW file. 

class NAT
{
private: ofstream outfile; // output file stream object to write into OUTPUT file.


public:

void NATip(string str)
{
    int n=str.find(',');
    string first_add = str.substr(0,n); // stores the value of first ip address and port in string first_add.
    int p= first_add.find(':'); // finds the position of the ':' to get the index for splitting ip add and port. 
    string fip=first_add.substr(0,p); // stores the 1st ip address in string fip.
    string port1=first_add.substr(p+1); // stores the 1st port no. in string port 1.
    int q= stoi(port1);
    if(q>=0&&q<=65535) // to check if the port no. is a valid.
    firstip.insert(std::pair<string, string>(fip, port1)); 
    else
    cout<<"port number is invalid"<<endl;
    string second_add= str.substr(n+1); // stores the value of second address and port in string second_add.
    fipmap.insert(std::pair<string, string>(first_add, second_add)); // stores the value of firstip and second ip in map fipmap.
}

void FLOWip(string str)
{
    int n=str.find(':');
    string flow_ip = str.substr(0,n); //stores the value of Flow ip address in string flow_ip
    if(flow_ip=="*") // to check if flow_ip does not start with a *
    cout<<"not a valid input for Flow address"<<endl;
    string flow_port= str.substr(n+1); // stores the value of port no. from FLOW file in string flow_port
    int q= stoi(flow_port);
    if(q>=0&&q<=65535) // to check if the port no. is a valid.
    sipmap.insert(std::pair<string, string>(flow_ip, flow_port)); // inserts the value of flow_ip and flow_port in sipmap
    else
    cout<<"port number is invalid"<<endl;
}

void result(map<string,string> &fst, map<string, string> &sip, map<string, string> &fip) // fst is firstip, sip is sipmap and fip is fipmap
 {
    map<string, string>:: iterator i,j,k;
    outfile.open("OUTPUT.txt");

    for(j=sip.begin(); j!=sip.end(); j++) // to get value from FLOW file one at time
    {   
        string temp=j->first; // stores ip address from flow file in a variable to check 
        string temp2=j->second; // stores port no. from flow file in a variable to check 
    
    for(i=fst.begin(),k=fip.begin(); i!=fst.end(); i++,k++) // simultaneously iterates through both firstip map and fipmap to find a match and print the result
     {
         if((i->first==temp)||(i->second==temp2))// checks if any flow ip/port no. matches with NAT ip/port in occurrence of "*"
            outfile<<j->first<<":"<<j->second<<"->"<<k->second<<endl; // prints in the OUTPUT file the NAT mapping if found a match
        else
            outfile<<"No NAT match for "<<j->first<<":"<<j->second<<endl;//prints "No match found message" in the OUTPUT file if fail to match. 
     }
    }
     outfile.close();
 }
};

int main ()
{  
   NAT a;
   string mainstr;
   string flow;
   ifstream infile;
   ifstream inpfile;
	
   infile.open("NAT.txt");
   if(infile.is_open())
   
    {
        while(!infile.eof()) // To get you all the lines.
     {
	    getline(infile,mainstr); // Saves the line in mainstr.
	    a.NATip(mainstr); // passes the string mainstr as argument to NATip function.
     }
     
    }
    infile.close();
    
    inpfile.open("FLOW.txt");
    if(inpfile.is_open())
    {
        while(!inpfile.eof()) // To get you all the lines in FLOW.txt.
      {
	     getline(inpfile,flow); // Saves the line in  string flow.
	     a.FLOWip(flow); // passes the string flow as argument to FLOWip function.
      }
	}
	
   inpfile.close();	
   a.result(firstip, sipmap, fipmap);
   return 0;
}
