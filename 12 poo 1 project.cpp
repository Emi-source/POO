#include <iostream>
#include <string.h>

using namespace std;

class grupa;

class student
{
private:
    char *nume;
    int an_nastere, nr_credite;
    double medie_generala;
public:

    friend class grupa;

    student(char* nume=NULL, int an_nastere=0, int nr_credite=0, double medie_generala=0)
    {
        this->nume=nume;
        this->an_nastere=an_nastere;
        this->nr_credite=nr_credite;
        this->medie_generala=medie_generala;
    }

    student(const student& st)
    {
        this->nume=st.nume;
        this->an_nastere=st.an_nastere;
        this->nr_credite=st.nr_credite;
    }

    ~student();

    set_nume(char* s)
    {
        this->nume=s;
    }

    get_nume()
    {
        return *(this->nume);
    }

    set_an_nastere(int x)
    {
        this->an_nastere=x;
    }

    get_an_nastere()
    {
        return this->an_nastere;
    }

    set_nr_credite(int x)
    {
        this->nr_credite=x;
    }

    get_nr_credite()
    {
        return this->nr_credite;
    }

    set_medie_generala(double x)
    {
        this->medie_generala=x;
    }

    get_medie_generala()
    {
        return this->medie_generala;
    }

    friend istream& operator>>(istream& in, student& st)
    {
        cout<<"Introduceti numele studentului: ";
        char num[256];
        in.get();
        in.getline(num,256);
        st.nume=new char [strlen(num)];
        cout<<"\nIntroduceti anul nasterii ";
        in>>st.an_nastere;
        cout<<"\nIntroduceti numarul de credite ";
        in>>st.nr_credite;
        do
        {
            cout<<"\nIntroduceti media generala\n";
            in>>st.medie_generala;
        }while(st.medie_generala<1 || st.medie_generala>10);
        return in;
    }
    friend ostream& operator<<(ostream& out, student& st)
    {
        out<<"Nume: "<<st.nume<<endl;
        out<<"An nastere: "<<st.an_nastere<<endl;
        out<<"Numar credite: "<<st.nr_credite<<endl;
        out<<"Medie generala: "<<st.medie_generala<<endl;
        return out;
    }

    friend ostream& operator<<(ostream& out, grupa& gr);
    friend istream& operator<<(istream& in, grupa& gr);
};

class grupa
{
private:
    student* v;
    int n;
    double medie;
public:

    friend student;

    grupa(int n=0)
    {
        this->n=n;
        v=new student[n];
        this->medie=0;
    }

    grupa(grupa& gr)
    {
        delete v;
        this->n=gr.n;
        v=new student[gr.n];
        for(int i=0;i<gr.n;i++)
            v[i]=gr.v[i];
    }

    /*~grupa()
    {
        delete v;
    }*/

    eliminare(int i)
    {
        for(int k=i-1;k<n;k++)
            v[k]=v[k+1];
        n--;
    }

    adaugare()
    {
        grupa v2(n+1);
        v2.v=v;
        v2.n=n+1;
        v2.medie=medie;
        cin>>v2.v[n+1];
        // delete v;
    }

    /*verificare()
    {
        char num[256];
        cin.get();
        cin.getline(num,256);
        char *s=new char [strlen(num)];
        for(int i=0;i<n;i++)
            if(strcmp(*s,this->v[i].get_nume())==0)
            {
                cout<<"Studentul se afla in grupa";
                goto here;
            }
        cout<<"Studentul nu se afla in grupa";
        here:
    }*/
    friend istream& operator>>(istream& in, student& st);
    friend ostream& operator<<(ostream& out, student& st);
    friend istream& operator>>(istream& in, grupa& gr)
    {
        int s=0;
        for(int i=0;i<gr.n;i++)
        {
            in>>gr.v[i];
            s+=gr.v[i].get_medie_generala();
        }
        gr.medie=s/gr.n;

        return in;
    }

    friend ostream& operator<<(ostream& out, grupa& gr)
    {
        for(int i=0;i<gr.n;i++)
            out<<gr.v[i];
        out<<"Media grupei: "<<gr.medie;
        return out;
    }
};

void menu_output()
{
    cout<<"\n Nume Prenume Grupa - Proiect - Nume proiect: Coman Emilia 212- Proiect 1- Tema 12\n";
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1. Afisati grupa \n";
    cout<<"2. Eliminare student din grupa \n";
    cout<<"3. Adaugare student in grupa \n";
    cout<<"4. Verificare daca exista un student dupa nume \n";
    cout<<"0. Iesire. \n";
}
void menu()
{
    int option,x,n;///optiunea aleasa din meniu
    option=0;

    cout<<"Cititi numarul de studenti din grupa:"<<endl;
    cin>>n;
    cout<<"Cititi grupa:"<<endl;
    grupa F212(n);
    cin>>F212;

    do
    {
        menu_output();

        printf("\nIntroduceti numarul corespunzator actiunii pe care doriti sa o efectuati: ");
        cin>>option;

        if(option==1)
        {
            cout<<F212;
        }

        if (option==2)
        {
            cout<<"Cititi numarul studentului pe care doriti sa il eliminati:";
            cin>>x;
            F212.eliminare(x);
        }
        if (option==3)
        {
            cout<<"Citit studentul ce urmeaza a fi adaugat"<<endl;
            F212.adaugare();
        }
        if (option==4)
        {
            cout<<"Citit numele studentului pe care doriti sa il cautati";
            //F212.verificare();
        }
        if (option==0)
        {
            cout<<"\nEXIT!\n";
        }
        if (option<0||option>4)
        {
            cout<<"\nSelectie invalida\n";
        }
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}
int main()
{
    menu();
    return 0;
}