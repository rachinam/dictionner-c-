#include <iostream>
#include <fstream>
#include <string>

// Korichi Tarzi
using namespace std;
struct element
{
    string fr ;
    string en ;
    element *suivant;
};
element *dection()
{
    element *p =NULL,*tete= NULL, *Q;
    cout<<"------------------------------------------------Dictionner  "<<endl;
    char path[] ="dictionner\\fr.txt";
    char path2[] ="dictionner\\en.txt";
    string data;

    ifstream myfile;
    ifstream myfile2;

    myfile.open(path);
    myfile2.open(path2);

    while (! myfile.eof())
    {
        getline(myfile,data);
        Q=new(element);
        Q->fr = data;
        Q->suivant=NULL;
        if(tete!=NULL)
        {
            p->suivant=Q;
        }
        else
        {
            tete=Q;
        }
        p=Q;

    }
    element *l = tete;

    while (! myfile2.eof())
    {
        getline(myfile2,data);
        l->en = data;
        l=l->suivant;

    }
    myfile.close();
    myfile2.close();
    return tete;
}

void afficherlist(element *l)
{

    element *first=l;
    while( first != NULL )
    {

        cout<<first->fr<<" = "<<first->en<<endl;
        first=first->suivant;


    }
    cout<<" OK :) "<<endl;
}

element *translation()
{

    element *p =NULL,*tete= NULL, *Q;
    int s,w;
    char ss;
    string mot,v ;
    int n = 1 ;
    cout<< " [1]- Francais"<<endl;
    cout<< " [2]- Anglais" <<endl;
    cout<< " Choix : ";
    cin>>s;
    if ( s == 1 )
    {
        cout<<"francais :";
        // ÕÃ„ «·‰’ ›Ì «·»œ«Ì… 1
        for( int i = 0 ; i < n ; i++)
        { // «œŒ‹‹‹«· «·ﬂ·„«  ›Ì list
            cin>>mot;
            Q=new(element);
            Q->fr=mot;
            Q->suivant=NULL;
            if(tete!=NULL)
            {
                p->suivant=Q;

            }
            else
            {
                tete=Q;

            }
            p=Q;
            v = Q->fr;
            w = v.length(); // ÿÊ· «·ﬂ·„…
            ss = v[w-1]; // √Œ— „«ÂÊ „ÊÃÊœ ›Ì «·ﬂ·„…
            if(ss != '.')
            { // Ì‰Õﬁﬁ „‰ √Œ— „« ›Ì «·ﬂ·„… «–« ·„  ﬂ‰ ‰ﬁÿ… Ì“Ìœ ›Ì ÕÃ„ «·‰’
                n = n + 1 ;
            }


        }


    }
    else
        if( s == 2)
        {
            cout<<"englais :";
            // ÕÃ„ «·‰’ ›Ì «·»œ«Ì… 1
            for( int i = 0 ; i < n ; i++)
            { // «œŒ‹‹‹«· «·ﬂ·„«  ›Ì list
                cin>>mot;
                Q=new(element);
                Q->en=mot;
                Q->suivant=NULL;
                if(tete!=NULL)
                {
                    p->suivant=Q;

                }
                else
                {
                    tete=Q;

                }
                p=Q;
                v = Q->en;
                w = v.length(); // ÿÊ· «·ﬂ·„…
                ss = v[w-1]; // √Œ— „«ÂÊ „ÊÃÊœ ›Ì «·ﬂ·„…
                if(ss != '.')
                { // Ì‰Õﬁﬁ „‰ √Œ— „« ›Ì «·ﬂ·„… «–« ·„  ﬂ‰ ‰ﬁÿ… Ì“Ìœ ›Ì ÕÃ„ «·‰’
                    n = n + 1 ;
                }
            }



        }else
        {
            cout <<" 1 ou 2  !!";
        }

    return tete; // lest " tete "  Õ ÊÌ ⁄·Ï «·‰’ «·„—«œ  —Ã„ Â
}
void Ajoute(string t1,element *k,int i)
{
    string data ;
    int ch;
    cout<<t1<<":aucune traduction!"<<endl;
    cout<<"[1]- Ajoute"<<endl;
    cout<<"[2]- annuler"<<endl;
    cout<<"choisir :";
    cin>>ch;
    char path[] ="dictionner\\fr.txt";
    char path2[] ="dictionner\\en.txt";
    ofstream myfile1;
    ofstream myfile2;
    myfile1.open( path , ios::out | ios::app );
    myfile2.open( path2 , ios::out | ios::app );
    if(ch == 1)
    {
        if(i == 1)
        {// ajoute dans fr : t1 englais
           cout<< "Anglais :"<<t1<<endl;
           cout<< "Francais:";cin>>data;
           myfile2<<endl;
           myfile1<<endl;
           myfile2<<t1;
           myfile1<<data;
        }else if(i == 2)
        {// ajoute dans en : t1 franca
            cout<<"Francais:"<<t1<<endl;
           cout<< "Anglais :";cin>>data;
           myfile2<<endl;
           myfile1<<endl;
            myfile1<<t1;
            myfile2<<data;
        }

    }else
    if(ch == 2)
    {
        cout<<"------ annuler ------ "<<endl;
    }else{cout<<" 1 or 2 ! ";}

}
int  *Rech(element *reception , element *tete)
{
    char ss ;
    int i ,ww;
    bool ver;
    string f, txt1,txt2,txt3;
    element *p = tete;
    element *add = tete;
    element *q = reception;
    element *w = reception;
    if(reception->fr == f)
    {
        i = 1;
        while(q != NULL)
        {//cout<<txt1<<"  ";
            txt1 = q->en;
            p = tete;
            ver = false;
            while(p != NULL)
            {
                txt2 = p->en;
                txt3 = p->fr;
                if (txt1 == txt2)                              //End  Desktop  Pictures
                {
                    q->fr = txt3;
                    ver = true;
                }
                p = p->suivant;
            }
            if(ver == false)
            {
                ww = txt1.length()-1;
                ss = txt1[ww];
                if(ss != '.')
                {
                    Ajoute(txt1,add,i);
                }
            }
            q = q->suivant;
        }
        cout<<"francais : " ;
        while(reception != NULL)
        {
            cout<<reception->fr<<" ";
            reception = reception->suivant;

        }
        cout<<endl;
    }else if(reception->en == f)
    {
        i = 2;
        while(q != NULL)
        {//cout<<txt1<<"  ";

            txt1 = q->fr;
            p = tete;
            ver =false;
            while(p != NULL)
            {
                txt2 = p->fr;
                txt3 = p->en;
                if (txt1 == txt2)                              //End  Desktop  Pictures Download
                {                                               //Fin Bereau Images telecharge
                    q->en = txt3;
                    ver = true;
                }
                p = p->suivant;
            }
            if(ver == false)
            {
                ww = txt1.length()-1;
                ss = txt1[ww];
                if(ss != '.')
                {
                    Ajoute(txt1,add,i);
                }
            }
            q = q->suivant;
        }
        cout<<"englais : ";
        while(reception != NULL)
        {
            cout<<reception->en<<" ";
            reception = reception->suivant;

        }
        cout<<endl;
    }


}


int main()
{
    cout<<"      Hamza farhat  groupe 2"<<endl;
    cout<<"      Korichi tarzi groupe 1"<<endl;
    cout<<"      Amin chouha   groupe 1"<<endl;
    element *save ,*p;
    save = dection();
    p = translation();
    Rech(p,save);
    int choi;
    cout<<"[1]- traduction"<<endl;
    cout<<"[2]- exit"<<endl;
    cout<<"choisir : ";cin>>choi;
    if(choi == 1 )
    {
        save = dection();
        p = translation();
        Rech(p,save);
    }
}
