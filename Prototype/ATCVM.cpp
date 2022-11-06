#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstring>
#include <new>
#include <strstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

struct speed {
    std::string data;
    long int delay;
};

std::ostream& operator<<(std::ostream& out, const speed& s) {
    for (const auto& c : s.data) {
        out << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
    }
    return out;
}


class atcvm {
	int crore=0,tenlakh=0,lakh=0,tenthous=0,thous=0;
	public :
		void hashline();
		void greetings();
		void greetingsmessage();
		void instruct();
		void workingprogram();
		void crop_omr_sec() { 
			system("python src/omr_generator/full_crop.py");
		}
		void filter_omr() { 
			system("python src/purify/purify.py");
		}
		void cut_into_5() { 
			system("python src/omr_generator/lal1.py");
			system("python src/omr_generator/lal2.py");
			system("python src/omr_generator/lal3.py");
			system("python src/omr_generator/lal4.py");
			system("python src/omr_generator/lal5.py");
		}
		void merge_5() {
			system("python src/merge_img/merge1.py");
                        system("python src/merge_img/merge2.py");
                        system("python src/merge_img/merge3.py");
			system("python src/merge_img/merge4.py");
			system("python src/merge_img/merge5.py");
		}
		void set_funds_multiples(int cr,int tl ,int l,int tt,int t) {
			crore   = crore + cr;
			tenlakh =tenlakh + tl;
			lakh    =lakh + l;
			tenthous=tenthous + tt;
			thous   =thous + t;
		}
		void get_funds_multiples(int &cr,int &tl,int &l,int &tt,int &t) {
			cr =crore;
			tl =tenlakh;
			l  =lakh;
			tt =tenthous;
			t  =thous;

		}
		void crop_fingerprint() { 
			system("python src/fingerprint/rgt_fin.py");
			system("python src/fingerprint/lft_fin.py");
		}
		void compare_fins_database() {
			system("python src/comp_fins/rgt_fin.py");
			system("python src/comp_fins/lft_fin.py");
		}

};


class bank_database : public atcvm {
	char name[20];
	int acc_no;
	int128_t cur_bal=0;

	int128_t tip;
	public:
	void set(char *s,int num,int128_t bal) {
		strcpy(name,s);
		acc_no=num;
		cur_bal= bal;
	}

	void get(char *s,int &num,int128_t &bal) {
		strcpy(s,name);
		num=acc_no;
		bal=cur_bal;
	}
	void set_tip(long int funds) {
		tip = (int128_t)funds;

	}
	void get_tip(int128_t &funds) {
		funds = tip;

		cout<<funds;
	}

};

void atcvm::hashline() 
{
	for(int i=0;i<112;i++) {
		std::cout << speed{"#",15};
	}
	cout<<"\n";
}

void atcvm::greetings()
{
	std::cout<<speed{"\t***           ***  ************  ***           ***           \t***     ***  ***           ***\n",4};
	std::cout<<speed{"\t***           ***  ************  ***           ***           \t***    ***   ****         ****\n",4};
	std::cout<<speed{"\t***           ***  ***           ***           ***           \t***   **     *****       *****\n",4};
	std::cout<<speed{"\t***           ***  ***           ***           ***           \t***  ***     ******     ******\n",4};
	std::cout<<speed{"\t***    ***    ***  ***           ***           ***           \t*** ***      *** ***   *** ***\n",4};
	std::cout<<speed{"\t***   *****   ***  ************  ***           ***           \t******       ***  *** ***  ***\n",4};
	std::cout<<speed{"\t***  *** ***  ***  ************  ***           ***           \t******       ***   *****   ***\n",4};
	std::cout<<speed{"\t*** ***   *** ***  ***           ***           ***           \t*** ***      ***    ***    ***\n",4};
	std::cout<<speed{"\t******     ******  ***           ***           ***           \t***  ***     ***           ***\n",4};
	std::cout<<speed{"\t*****       *****  ***           ***           ***           \t***   ***    ***           ***\n",4};
	std::cout<<speed{"\t****         ****  ************  ************  ************  \t***    ***   ***           ***\n",4};
	std::cout<<speed{"\t***           ***  ************  ************  ************  \t***     ***  ***           ***\n",4};
}

void atcvm::greetingsmessage()
{
	std::cout<<speed{"\n\n\t\t\t\tTO MY AUTOMATED CHEQUE PROCESSING PROJECT\n\n\n",30};
}

void atcvm::instruct()
{
	atcvm access;

	std::cout<<speed{"\tTYPE ANY KEY TO CONTINUE\n",50};
        getchar();
	
        std::cout<<speed{"\tPLEASE UPLOAD YOUR CHEQUE\n\t\tAND CHOOSE YOUR DESIRED OPTION\n",50};
	while(true)
	{
	std::cout<<speed{"\t\t\t 1 DOCUMENT UPLOADED\n",50};
        std::cout<<speed{"\t\t\t 2 TERMINATE SESSION\n",50};

	char ch;
	cin>>ch;
	switch(ch)
	{
		case '1':
			access.workingprogram();
			break;
		case '2':
			exit(0);
		default :
			cout<<"\t\t\tPLEASE CHOOSE YOUR RIGHT OPTION\n";
			break;
	}
	}
}


void atcvm::workingprogram()
{
	atcvm access;

	std::cout<<speed{"\t\t\tPLEASE BE PATIENCE, TILL WE PROCESS YOUR REQUEST\n\n\n\n\n",50};

	access.crop_omr_sec();
	access.filter_omr();
	access.cut_into_5();
	access.merge_5();
	
	int cr=0,tl=0,l=0,tt=0,t=0;


        system("python src/funds/crore.py");
        system("python src/funds/tenlakh.py");
        system("python src/funds/lakh.py");
        system("python src/funds/tenthous.py");
        system("python src/funds/thous.py");


        ifstream in1("crore.txt");
        in1>>cr;
        in1.close();

        ifstream in2("tenlakh.txt");
        in2>>tl;
        in2.close();

        ifstream in3("lakh.txt");
        in3>>l;
        in3.close();

        ifstream in4("tenthous.txt");
        in4>>tt;
        in4.close();

        ifstream in5("thous.txt");
        in5>>t;
        in5.close();

        access.set_funds_multiples(cr, tl, l, tt, t);



        system("python src/funds/crore2.py");
        system("python src/funds/tenlakh2.py");
        system("python src/funds/lakh2.py");
        system("python src/funds/tenthous2.py");
        system("python src/funds/thous2.py");

        ifstream in6("crore.txt");
        in6>>cr;
        in6.close();

        ifstream in7("tenlakh.txt");
        in7>>tl;
        in7.close();

        ifstream in8("lakh.txt");
        in8>>l;
        in8.close();

        ifstream in9("tenthous.txt");
        in9>>tt;
        in9.close();

        ifstream in10("thous.txt");
        in10>>t;
        in10.close();

        access.set_funds_multiples(cr, tl, l, tt, t);



        system("python src/funds/crore3.py");
        system("python src/funds/tenlakh3.py");
        system("python src/funds/lakh3.py");
        system("python src/funds/tenthous3.py");
        system("python src/funds/thous3.py");

        ifstream in11("crore.txt");
        in11>>cr;
        in11.close();

        ifstream in12("tenlakh.txt");
        in12>>tl;
        in12.close();

        ifstream in13("lakh.txt");
        in13>>l;
        in13.close();

        ifstream in14("tenthous.txt");
        in14>>tt;
        in14.close();

        ifstream in15("thous.txt");
        in15>>t;
        in15.close();

        access.set_funds_multiples(cr, tl, l, tt, t);



        system("python src/funds/crore4.py");
        system("python src/funds/tenlakh4.py");
        system("python src/funds/lakh4.py");
        system("python src/funds/tenthous4.py");
        system("python src/funds/thous4.py");

        ifstream in16("crore.txt");
        in16>>cr;
        in16.close();

        ifstream in17("tenlakh.txt");
        in17>>tl;
        in17.close();

        ifstream in18("lakh.txt");
        in18>>l;
        in18.close();

        ifstream in19("tenthous.txt");
        in19>>tt;
        in19.close();

        ifstream in20("thous.txt");
        in20>>t;
        in20.close();

        access.set_funds_multiples(cr, tl, l, tt, t);



        system("python src/funds/crore5.py");
        system("python src/funds/tenlakh5.py");
        system("python src/funds/lakh5.py");
        system("python src/funds/tenthous5.py");
        system("python src/funds/thous5.py");

        ifstream in21("crore.txt");
        in21>>cr;
        in21.close();

        ifstream in22("tenlakh.txt");
        in22>>tl;
        in22.close();

        ifstream in23("lakh.txt");
        in23>>l;
        in23.close();

        ifstream in24("tenthous.txt");
        in24>>tt;
        in24.close();

        ifstream in25("thous.txt");
        in25>>t;
        in25.close();

        access.set_funds_multiples(cr,tl, l, tt, t);

        access.get_funds_multiples(cr,tl,l, tt,t);


        long int crore=0,tenlakh=0,lakh=0,tenthous=0,thous=0;
        long int funds=0;

                        crore    = 10000000;
                        tenlakh  = 1000000;
                        lakh     = 100000;
                        tenthous = 10000;
                        thous    = 1000;

                        crore = crore*cr;
                        tenlakh = tenlakh*tl;
                        lakh= lakh*l;
                        tenthous=tenthous*tt;
                        thous=thous*t;

                        funds    = crore + tenlakh + lakh + tenthous + thous;


	access.crop_fingerprint();
	access.compare_fins_database();

	bank_database *pp,tip;

                        try {
                                pp=new bank_database [4];
                        }
                        catch (bad_alloc xa) {
                                cout<<"Alctn fld\n";
                                //return 1;
                        }

                        int128_t pre_deposit = 1000000000;
                        char name1[]="JACK",name2[]="JAMES",
                             name3[]="HENRY",name4[]="OLIVIA";


                        pp[100].set(name1,12345666,pre_deposit);
                        pp[101].set(name2,12345777,pre_deposit);
                        pp[102].set(name3,12345888,pre_deposit);
                        pp[103].set(name4,12345999,pre_deposit);

                        char rgt_fin[50],lft_fin[50];

                        ifstream in_rgt_fin("rgt_fin.txt");
                        in_rgt_fin>>rgt_fin;
                        in_rgt_fin.close();

                        ifstream in_lft_fin("lft_fin.txt");
                        in_lft_fin>>lft_fin;
                        in_lft_fin.close();

                        int lft,rgt;

                        istrstream lf(lft_fin);
                        lf>>lft;
                        istrstream rg(rgt_fin);
                        rg>>rgt;
	

	char s[20];      
	int128_t bal;
	int num;


	for(int i=100;i<104;i++) {

		if(rgt == i) {
			pp[i].get(s,num,bal);
			bal=bal-funds;
			pp[i].set(s,num,bal);

		}
		if(lft == i) {
			pp[i].get(s,num,bal);
			bal=bal+funds;
			pp[i].set(s,num,bal);
			std::cout<<speed{"\t\t\tNAMASTE ",200};
			std::cout<<speed{s,300};
			cout<<","<<endl;
			std::cout<<speed{"\t\t\tWELL COME\n\n\n",150};
			std::cout<<speed{"\t\t\tSHRI ",150};
			cout<<s<<",\n\n";

			while(true)
			{
				access.hashline();

				std::cout<<speed{"\t\t\tPLEASE CHOOSE YOUR OPTION\n\n",80};
				std::cout<<speed{"\t\t\t\t1.KNOW YOUR UPDATED BALANCE\n",80};
                                std::cout<<speed{"\t\t\t\t2.'OR' TERMINATE THE SESSION\n\n",80};
				std::cout<<speed{"\t\t\t\t     MESSAGE TO PAYER\n\n",80};
				std::cout<<speed{"\t\t\t\t3. FUNDS DEDUCTION MSG\n",80};

				access.hashline();

                                char ch;
                                cin>>ch;                                                                                                                            
				switch(ch)
				{
					case '1':
						std::cout<<speed{"\t\t\tYOUR UPDATED BALANCE IS $",80};
                                                cout<<bal<<".00\n\n";
                                                break;
                                        case '2':
						access.hashline();
						access.hashline();
						cout<<endl<<endl;
						system("gcc big_char.c");
						system("./a.out");
						cout<<endl<<endl;
						access.hashline();
						access.hashline();
                                                system("g++ remove_file.cpp"); system("./a.out");
						exit(0);
						break;
					case '3':
						pp[rgt].get(s,num,bal);
						std::cout<<speed{"\t\t\t\t NAMASTE SHRI,",80};
						std::cout<<speed{ s ,80};
						std::cout<<speed{"\n\n\t\t\t\t FROM YOUR ACCOUNT: ",80};
						cout<< num;
						std::cout<<speed{ "\n\t\t\t\t $",80};
						cout<<funds;
						std::cout<<speed{"  DEDUTED. TO SHRI  ",80};
						pp[lft].get(s,num,bal);
						std::cout<<speed{s,80};
						std::cout<<speed{"\n\t\t\t\t YOUR CURRENT BALANCE $" ,80};
						pp[rgt].get(s,num,bal);
						cout<<bal<<endl<<endl<<endl;

						break;

					default :
						cout<<"\n\n\t\tCHOOSE YOUR RIGHT OPTION\n\n";
						break;
                                        
				}
                        
			}
                
		}
        
	}

	delete [] pp;
	exit(0);

}


int main()
{

	atcvm access;

	cout<<"\n\n\n";

	access.hashline();
	access.hashline();
	cout<<"\n";

	access.greetings();

	cout<<"\n";
	access.hashline();
	access.hashline();

	access.greetingsmessage();


	std::cout<<speed{"\tTYPE ANY KEY TO CONTINUE\n",50};
        getchar();

        std::cout<<speed{"\tPLEASE UPLOAD YOUR CHEQUE\n\t\tAND CHOOSE YOUR DESIRED OPTION\n",50};

	while(true)
	{
	std::cout<<speed{"\t\t\t 1 DOCUMENT UPLOADED\n",50};
        std::cout<<speed{"\t\t\t 2 TERMINATE SESSION\n",50};

        char ch;
        cin>>ch;
        switch(ch)
        {
		case '1':
			access.workingprogram();

			break;

		case '2':
			exit(0);
			break;

		default :

			cout<<"\t\t\tPLEASE CHOOSE YOUR RIGHT OPTION\n";
			break;

	}
	}

return 0;
}
